#include<iostream>

using namespace std;

int house[32][32];
long long route[32][32][3];
int N;

int drow[] = { 0, 1, 1 };
int dcol[] = { 1, 1, 0 };

long long move_pipe(int row, int col, int dir) {
	if (row == N - 1 && col == N - 1)
		return 1;

	if (route[row][col][dir] != -1)
		return route[row][col][dir];

	long long result = 0;

	for (int i = dir - 1; i <= dir + 1; i++) {
		if (i < 0 || i >= 3)
			continue;

		int new_row = row + drow[i];
		int new_col = col + dcol[i];

		if (new_row < 0 || new_row >= N || new_col < 0 || new_col >= N)
			continue;

		if (house[new_row][new_col] != 1) {
			if (i == 1) {
				if (house[new_row - 1][new_col] == 1 || house[new_row][new_col - 1] == 1)
					continue;
			}

			result += move_pipe(new_row, new_col, i);
		}
	}

	return route[row][col][dir] = result;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> house[i][j];
			
			for (int k = 0; k < 3; k++) {
				route[i][j][k] = -1;
			}
		}
	}

	cout << move_pipe(0, 1, 0) << endl;
	return 0;
}