#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

typedef pair<int, int> p;
string board[12];

int drow[] = { 0, -1, 0, 1 };
int dcol[] = { 1, 0, -1, 0 };

void check_block(p pos, vector<p> &block) {
	for (int i = 0; i < block.size(); i++) {
		if (pos.first == block[i].first && pos.second == block[i].second)
			return;
	}
	
	if (block.size() != 0 && board[block[0].first][block[0].second] != board[pos.first][pos.second])
		return;

	block.push_back(pos);

	for (int i = 0; i < 4; i++) {
		int new_row = pos.first + drow[i];
		int new_col = pos.second + dcol[i];

		if (new_row >= 0 && new_row < 12 && new_col >= 0 && new_col < 6)
			check_block(make_pair(new_row, new_col), block);
	}
}

bool update_board() {
	bool result = false;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (board[i][j] != '.') {
				vector<p> block;

				check_block(make_pair(i, j), block);

				if (block.size() >= 4) {
					for (int k = 0; k < block.size(); k++) {
						board[block[k].first][block[k].second] = '.';
					}

					result = true;
				}
			}
		}
	}

	if (result) {
		for (int i = 11; i >= 0; i--) {
			for (int j = 6; j >= 0; j--) {
				if (board[i][j] != '.') {
					int new_row = i + 1;

					while (new_row < 12 && board[new_row][j] == '.')
						new_row++;
					
					if (new_row - 1 != i) {
						board[new_row - 1][j] = board[i][j];
						board[i][j] = '.';
					}
				}
			}
		}
	}

	return result;
}

int main() {
	int result = 0;

	for (int i = 0; i < 12; i++)
		cin >> board[i];
	
	while (update_board())
		result++;

	cout << result << endl;
}