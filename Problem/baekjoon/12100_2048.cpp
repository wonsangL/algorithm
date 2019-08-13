#include<iostream>
#include<vector>

using namespace std;

int d_row[] = { 1, 0, -1, 0 };
int d_col[] = { 0, 1, 0, -1 };

int N;

void find_match(vector<vector<int>> &board, int row, int col, int dir) {
	int comp = board[row][col];

	int new_row = row + d_row[dir];
	int new_col = col + d_col[dir];

	while (new_row >= 0 && new_row < N && new_col >= 0 && new_col < N && board[new_row][new_col] == 0) {
		new_row += d_row[dir];
		new_col += d_col[dir];
	}

	if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < N && board[new_row][new_col] == comp) {
		board[row][col] *= 2;
		board[new_row][new_col] = 0;
	}
}

int solution(vector<vector<int>> board, int dir, int count) {
	int result = 0;

	if (dir % 2 == 0) {
		for (int col = 0; col < N; col++) {
			int stack;
			int row = stack = d_row[dir] > 0 ? 0 : N - 1;

			while (row >= 0 && row < N) {
				if (board[row][col] != 0) {
					find_match(board, row, col, dir);
					
					if(stack != row){
						board[stack][col] = board[row][col];
						board[row][col] = 0;
					}
					
					stack += d_row[dir];
				}

				row += d_row[dir];
			}
		}
	}
	else {
		for (int row = 0; row < N; row++) {
			int stack;
			int col = stack = d_col[dir] > 0 ? 0 : N - 1;

			while (col >= 0 && col < N) {
				if (board[row][col] != 0) {
					find_match(board, row, col, dir);
					
					if (stack != col) {
						board[row][stack] = board[row][col];
						board[row][col] = 0;
					}
					
					stack += d_col[dir];
				}
					
				col += d_col[dir];
			}
		}
	}

	if (count + 1 < 5) {
		for (int i = 0; i < 4; i++) {
			int tmp = solution(board, i, count + 1);
			if (tmp > result)
				result = tmp;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > result)
				result = board[i][j];
		}
	}

	return result;
}

int main() {
	cin >> N;

	vector<vector<int>> board(N);
	int result = 0;

	for (int i = 0; i < N; i++) {
		board[i] = vector<int>(N, 0);
		
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		int tmp = solution(board, i, 0);
		
		if (tmp > result)
			result = tmp;
	}

	cout << result << endl;
}