#include<iostream>
#include<string>

using namespace std;

bool check(int row, int column, int M, int N);
bool** matrix;

int main() {
	int M, N;
	string input;

	std::cin >> M;
	std::cin >> N;

	matrix = new bool*[M];

	for (int i = 0; i < M; i++) {
		matrix[i] = new bool[N];

		std::cin >> input;

		for (int j = 0; j < N; j++) {
			if (input[j] == '0')
				matrix[i][j] = true;
			else
				matrix[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		if (matrix[0][i]) {
	
			if (check(0, i, M, N)) {
				std::cout << "YES" << std::endl;
				return 0;
			}
		}
	}

	std::cout << "NO" << std::endl;
	return 0;
}

bool check(int row, int column, int M, int N) {
	bool result = false;
	matrix[row][column] = false;

	//if it reach to the floor, return true
	if (row == M - 1) {
		return true;
	}

	//check downward
	if (row != M - 1) {
		if (matrix[row + 1][column]) {
			result = check(row + 1, column,  M, N);
		}
	}

	//check right 
	if (column != N - 1 && !result) {
		if (matrix[row][column + 1]) {
			result = check(row, column + 1, M, N);
		}
	}
	
	//check left
	if (column != 0 && !result) {
		if (matrix[row][column - 1]) {
			result = check(row, column - 1, M, N);
		}
	}

	//check upward
	if (row != 0 && !result) {
		if (matrix[row - 1][column]) {
			result = check(row - 1, column, M, N);
		}
	}
			
	return result;
}
