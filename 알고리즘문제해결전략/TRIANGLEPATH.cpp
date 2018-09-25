#include<iostream>

using namespace std;

int C, n;

int **accumulation;
int **cost;

inline int MAX(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int FindPath(int row, int col) {
	if (row == n - 1) {
		accumulation[row][col] = cost[row][col];
		return cost[row][col];
	}

	int &ref = accumulation[row][col];
	
	if (ref != -1)
		return ref;

	return ref = cost[row][col] + MAX(FindPath(row + 1, col), FindPath(row + 1, col + 1));
}

int main() {
	cin >> C;

	for (int i = 0; i < C; i++) {
		int Answer = 0;

		cin >> n;

		cost = new int*[n];
		accumulation = new int*[n];

		for (int i = 0; i < n; i++) {
			cost[i] = new int[n];
			accumulation[i] = new int[n];

			for (int j = 0; j <= i; j++) {
				cin >> cost[i][j];
				accumulation[i][j] = -1;
			}
		}

		Answer = FindPath(0, 0);
		cout << Answer << endl;
	}
}