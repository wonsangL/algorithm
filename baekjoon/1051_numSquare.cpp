#include<iostream>
#include<string>

using namespace std;

int N, M;
string grid[50];

int find_rect(int row, int col) {
	int c_col = M - 1, result = 1;

	while (c_col != col) {
		if (grid[row][col] == grid[row][c_col]) {
			if (row + (c_col - col) < N && grid[row][col] == grid[row + (c_col - col)][col]) {
				if (grid[row][col] == grid[row + (c_col - col)][c_col]) {
					if ((c_col - col + 1) * (c_col - col + 1) > result)
						result = (c_col - col + 1) * (c_col - col + 1);
				}
			}
		}
		c_col--;
	}

	return result;
}

int main() {
	int result = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> grid[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int buffer = find_rect(i, j);

			if (buffer > result)
				result = buffer;
		}
	}

	cout << result << endl;
}