#include<iostream>
#include<math.h>
#include<queue>
#include<tuple>

using namespace std;

int route[] = { 15, 10, 5, 9, 3, 6, 12 };

int drow[] = { 0, 1, 0, -1 };
int dcol[] = { 1, 0, -1, 0 };

int map[50][50];
bool visited[50][50];

int T, N, M, R1, R2, L;

int movement(int row, int col, int count) {
	queue<tuple<int, int, int>> q;
	int result = 0;

	q.push(make_tuple(row, col, 1));

	while (!q.empty()) {
		row = get<0>(q.front());
		col = get<1>(q.front());
		
		int timer = get<2>(q.front());
		
		q.pop();

		if (visited[row][col])
			continue;
		
		visited[row][col] = true;
		result++;
		
		if (timer < L) {
			for (int i = 0; i < 4; i++) {
				if ((route[map[row][col] - 1] & (int)pow(2, i)) > 0) {
					int new_row = row + drow[i];
					int new_col = col + dcol[i];

					if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < M) {
						if (!visited[new_row][new_col] && map[new_row][new_col] > 0) {
							if ((route[map[new_row][new_col] - 1] & (int)pow(2, (i + 2) % 4)) > 0)
								q.push(make_tuple(new_row, new_col, timer + 1));
						}
					}
				}
			}
		}
	}

	/*int result = 0;

	if (!visited[row][col]) {
		result++;
		visited[row][col] = true;
	}

	if (count - 1 == 0)
		return result;

	for (int i = 0; i < 4; i++) {
		if ((route[map[row][col] - 1] & (int)pow(2, i)) > 0) {
			int new_row = row + drow[i];
			int new_col = col + dcol[i];

			if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < M) {
				if (map[new_row][new_col] > 0) {
					if ((route[map[new_row][new_col] - 1] & (int)pow(2, (i + 2) % 4)) > 0)
						result += movement(new_row, new_col, count - 1);
				}
			}
		}
	}*/

	return result;
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M >> R1 >> R2 >> L;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> map[j][k];
				visited[j][k] = false;
			}
		}

		cout << "#" << i + 1 << " " << movement(R1, R2, L) << endl;
	}
}