#include<iostream>
#include<string>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int d_row[] = { 1, 0, -1, 0 };
int d_col[] = { 0, 1, 0, -1 };

int main() {
	int N;
	cin >> N;

	int map[25][25];
	bool visited[25][25];
	vector<int> result;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < input.length(); j++) {
			map[i][j] = input[j] - '0';
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j] != 0) {
				queue<pair<int, int>> q;
				int temp = 1;

				q.push(make_pair(i, j));
				visited[i][j] = true;

				while (!q.empty()) {
					pair<int, int> current = q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						int new_row = current.first + d_row[k];
						int new_col = current.second + d_col[k];

						if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < N) {
							if (!visited[new_row][new_col] && map[new_row][new_col] != 0) {
								q.push(make_pair(new_row, new_col));
								visited[new_row][new_col] = true;
								temp++;
							}
						}
					}
				}

				result.push_back(temp);
			}
		}
	}

	cout << result.size() << endl;

	sort(result.begin(), result.end(), less<int>());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
}