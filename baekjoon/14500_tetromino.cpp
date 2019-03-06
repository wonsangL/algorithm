#include<iostream>

using namespace std;

int N, M;
int board[500][500];
bool mino[500][500];

int drow[] = { 1, 0, -1, 0 };
int dcol[] = { 0, 1, 0, -1 };

int get_max_cost(int row, int col, int length, int sum) {
	if (row < 0 || row >= N || col < 0 || col >= M)
		return -1;

	if (mino[row][col])
		return -1;

	int max = 0;

	sum += board[row][col];
	mino[row][col] = true;
	length--;

	if (length == 0) {
		mino[row][col] = false;
		return sum;
	}
	else if (length == 3) {
		for (int i = 0; i < 4; i++) {
			int tmp_sum = 0;

			for (int j = 0; j < 3; j++) {
				if (row + drow[(i + j) % 4] >= 0 && row + drow[(i + j) % 4] < N && col + dcol[(i + j) % 4] >= 0 && col + dcol[(i + j) % 4] < M) {
					length--;
					tmp_sum += board[row + drow[(i + j) % 4]][col + dcol[(i + j) % 4]];
				}
			}

			if (length == 0) {
				if (sum + tmp_sum > max) {
					max = sum + tmp_sum;
				}
			}

			length = 3;
		}
	}
		

	for (int i = 0; i < 4; i++) {
		int buffer = get_max_cost(row + drow[i], col + dcol[i], length, sum);
		
		if (buffer != -1) {
			if (buffer > max)
				max = buffer;
		}
	}

	mino[row][col] = false;
	return max;
}

int main() {
	int result = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			mino[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int buffer = get_max_cost(i, j, 4, 0);

			if (buffer > 0) {
				if (buffer > result)
					result = buffer;
			}
		}
	}

	cout << result << endl;
}