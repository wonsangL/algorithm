#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int d_row[] = { 1, -1, 0, 0 };
int d_col[] = { 0 ,0, 1, -1 };

void find_combination(string str, unordered_map<string, int>& result, int row, int col, char board[4][4]) {
	str += board[row][col];

	if (str.length() == 7) {
		if (result.find(str) == result.end()) {
			result[str] = 0;
		}
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int new_row = row + d_row[i];
		int new_col = col + d_col[i];

		if (new_row < 0 || new_row >= 4 || new_col < 0 || new_col >= 4) {
			continue;
		}

		find_combination(str, result, new_row, new_col, board);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		unordered_map<string, int> result;
		char board[4][4];

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				find_combination("", result, i, j, board);
			}
		}

		cout << "#" << test_case << " " << result.size() << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}