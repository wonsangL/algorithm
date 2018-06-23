#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

int** matrix;

int Check(int n, vector<int> team) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!team.empty()) {
				if (matrix[i][j] != 0) {
					team.push_back(i);
					team.push_back(j);

				}
			}
			else {
				for (vector<int>::iterator it = team.begin(); it != team.end(); it++) {
					if (i != *it && j != *it) {
						if (matrix[i][j] != 0) {

						}
					}
				}
			}
		}
	}
}

int main() {
	int T, n, m;
	vector<int> team;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int result = 0;
		
		cin >> n >> m;
		matrix = (int**)malloc(sizeof(int*) * n);
		
		for (int j = 0; j < m; j++) {
			int row, col;			
			matrix[j] = (int*)calloc(n, sizeof(int));
			cin >> row >> col;
			matrix[col][row] = matrix[row][col] = 1;
		}

		result = Check(n, team);
		
		cout << result << endl;
	}
}