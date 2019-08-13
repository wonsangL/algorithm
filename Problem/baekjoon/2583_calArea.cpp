#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> result;
bool **matrix;
int M, N, K;
int nextX[] = {0, 1, 0, -1};
int nextY[] = {-1, 0, 1, 0};

bool Check(int x, int y) {
	return matrix[y][x];
}

int Count(int x, int y) {
	if (x >= N || y >= M || x < 0 || y < 0 || !matrix[y][x])
		return 0;
	
	int result = 1;
	matrix[y][x] = false;
	for (int i = 0; i < 4; i++) {
		result += Count(x + nextX[i], y + nextY[i]);
	}
	
	return result;
}

int main() {
	cin >> M >> N >> K;

	matrix = new bool*[M];

	for (int i = 0; i < M; i++) {
		matrix[i] = new bool[N];
		for (int j = 0; j < N; j++) {
			matrix[i][j] = true;
		}
	}

	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++) {
			for (int k = x1; k < x2; k++) {
				matrix[j][k] = false;
			}
		}
	}

	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (matrix[y][x]) {
				int buffer = Count(x, y);

				if (buffer > 0)
					result.push_back(buffer);
			}
		}
	}

	sort(result.begin(), result.end());
	
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout <<  endl;
	
	return 0;
}