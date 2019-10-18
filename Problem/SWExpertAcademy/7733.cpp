#include<iostream>
#include<queue>

using namespace std;

int d_row[] = { 0 ,1, 0, -1 };
int d_col[] = { 1, 0, -1, 0 };

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, result = 0;
		vector<vector<int>> cheese;

		cin >> n;

		for (int i = 0; i < n; ++i) {
			vector<int> buffer;

			for (int j = 0; j < n; ++j) {
				int input;
				cin >> input;

				buffer.push_back(input);
			}

			cheese.push_back(buffer);
		}

		for (int day = 0; day <= 100; ++day) {
			int chunk = 0;
			bool visited[100][100];
			queue<pair<int, int>> q;

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					visited[i][j] = false;
				}
			}

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (!visited[i][j] && cheese[i][j] > day) {
						++chunk;
						q.push(make_pair(i, j));
						visited[i][j] = true;

						while (!q.empty()) {
							pair<int, int> current = q.front();
							q.pop();

							for (int k = 0; k < 4; ++k) {
								int row = current.first + d_row[k];
								int col = current.second + d_col[k];

								if (row < 0 || row >= n || col < 0 || col >= n) {
									continue;
								}

								if (!visited[row][col] && cheese[row][col] > day) {
									q.push(make_pair(row, col));
									visited[row][col] = true;
								}
							}
						}
					}
				}
			}

			if (chunk > result) {
				result = chunk;
			}
		}

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}