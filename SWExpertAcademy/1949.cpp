#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int T, N, K;
int map[8][8];
bool visited[8][8];

int drow[] = { 0, 1, 0, -1 };
int dcol[] = { 1, 0, -1, 0 };

int climb(int row, int col, bool used) {
	int result = 0;
	visited[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int buffer = 0;
		int new_row = row + drow[i];
		int new_col = col + dcol[i];

		if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < N) {
			if (!visited[new_row][new_col]) {
				if (map[row][col] > map[new_row][new_col]) {
					buffer = climb(new_row, new_col, used);
				}
				else if (used && map[row][col] > map[new_row][new_col] - K) {
					int diff = map[new_row][new_col] - map[row][col] + 1;

					map[new_row][new_col] -= diff;
					buffer = climb(new_row, new_col, false);
					map[new_row][new_col] += diff;
				}
			}
		}

		if (buffer > result)
			result = buffer;
	}

	visited[row][col] = false;

	return 1 + result;
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		int max = 0, result = 0;
		vector<pair<int, int>> start_point;

		cin >> N >> K;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> map[j][k];

				visited[j][k] = false;

				if (map[j][k] > max)
					max = map[j][k];
			}
		}

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (map[j][k] == max)
					start_point.push_back(make_pair(j, k));
			}
		}

		for (int j = 0; j < start_point.size(); j++) {
			int buffer = climb(start_point[j].first, start_point[j].second, true);

			if (buffer > result)
				result = buffer;
		}

		cout << "#" << i + 1 << " " << result << endl;
	}

}