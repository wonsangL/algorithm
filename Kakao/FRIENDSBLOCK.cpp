#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int x[] = { 0 ,0, 1, 1 };
int y[] = { 0, 1, 0, 1 };

class Position {
public:
	int row;
	int col;
	Position(int row, int col) : row(row), col(col){}
	bool operator== (const Position &other) {
		if (row == other.row && col == other.col)
			return true;
		return false;
	}
};

bool check(int row, int col, vector<string> &board) {
	if (board[row][col] == '-')
		return false;

	if (board[row][col] == board[row][col + 1] && board[row][col] == board[row + 1][col] && board[row][col] == board[row + 1][col + 1])
		return true;

	return false;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0, result;
	vector<Position> deleted;

	do {
		result = 0;

		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (check(i, j, board)) {
					for (int k = 0; k < 4; k++) {
						if (find(deleted.begin(), deleted.end(), Position(i + x[k], j + y[k])) == deleted.end()) {
							result++;
							deleted.push_back(Position(i + x[k], j + y[k]));
						}
					}
				}
			}
		}

		for (Position pos : deleted) {
			board[pos.row][pos.col] = '-';
		}

		if (deleted.size() > 0) {
			for (int i = m - 1; i >= 0; i--) {
				for (int j = 0; j < n; j++) {
					if (board[i][j] == '-') {
						int index = i;
						while (board[index][j] == '-' && index > 0)
							index--;

						board[i][j] = board[index][j];
						board[index][j] = '-';
					}
				}
			}
		}
		
		deleted.clear();

		answer += result;
	} while (result != 0);
	
	return answer;
}

int main() {
	cout << solution(4, 5, { "CCBDE", "AAADE", "AAABF", "CCBBF" }) << endl;
	cout << solution(6, 6, { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" }) << endl;
}