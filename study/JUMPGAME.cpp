#include<iostream>

using namespace std;

int C, n;

bool Jump(int **cost, bool **check, int x, int y) {
	if (x >= n || y >= n) 
		return false;
	else if (x == n - 1 && y == n - 1)
		return true;

	if (!check[x][y])
		return false;

	if (!Jump(cost, check, x + cost[x][y], y) && !Jump(cost, check, x, y + cost[x][y])) {
		check[x][y] = false;
		return false;
	}

	return true;
}

int main() {
	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> n;
				
		int **cost = new int*[n];
		bool **check = new bool*[n];

		for (int j = 0; j < n; j++) {
			cost[j] = new int[n];
			check[j] = new bool[n];
			
			for (int k = 0; k < n; k++){
				cin >> cost[j][k];
				check[j][k] = true;
			}
		}

		if (Jump(cost, check, 0, 0)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}