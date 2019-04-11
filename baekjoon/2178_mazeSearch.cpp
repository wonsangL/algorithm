#include<iostream>
#include<string>
#include<queue>
#include<utility>

using namespace std;

typedef pair<int, int> p;

int N, M;
string map[100];
bool visited[100][100];

int d_row[] = { 1, 0, -1, 0 };
int d_col[] = { 0, 1, 0, -1 };

int main() {
	int result = 0;

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}

	queue<p> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;

	while (!q.empty()) {
		int size = q.size();
		result++;

		for (int i = 0; i < size; i++) {
			p tmp = q.front();
			q.pop();

			if (tmp.first == N - 1 && tmp.second == M - 1) {
				cout << result << endl;
				return 0;
			}

			for (int j = 0; j < 4; j++) {
				int row = tmp.first + d_row[j];
				int col = tmp.second + d_col[j];

				if (row >= 0 && row < N && col >= 0 && col < M && map[row][col] == '1') {
					if (visited[row][col])
						continue;

					visited[row][col] = true;
					q.push(make_pair(row, col));
				}
			}
		}
	}
}