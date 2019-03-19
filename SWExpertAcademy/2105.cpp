#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int map[20][20];

int drow[] = { -1, -1, 1, 1 };
int dcol[] = { -1, 1, 1, -1 };

int T, N;

typedef pair<int, int> point;

int visite_cafe(point start, point cur, int dir, int weight, int sum, vector<bool> &dessert, vector<bool> &dir_candidate) {
	if (start.first == cur.first && start.second == cur.second)
		return sum;

	if (cur.first < 0 || cur.first >= N || cur.second < 0 || cur.second >= N)
		return -1;

	if (dessert[map[cur.first][cur.second] - 1])
		return -1;

	dessert[map[cur.first][cur.second] - 1] = true;

	int new_row = cur.first + drow[dir];
	int new_col = cur.second + dcol[dir];

	int result = visite_cafe(start, make_pair(new_row, new_col), dir, weight, sum + 1, dessert, dir_candidate);
	
	int new_dir = dir + weight;

	if (new_dir < 0)
		new_dir = 3;
	else if (new_dir > 3)
		new_dir = 0;

	if (!dir_candidate[new_dir]) {
		dir_candidate[new_dir] = true;

		new_row = cur.first + drow[new_dir];
		new_col = cur.second + dcol[new_dir];

		int buffer = visite_cafe(start, make_pair(new_row, new_col), new_dir, weight, sum + 1, dessert, dir_candidate);

		if (buffer > result)
			result = buffer;

		dir_candidate[new_dir] = false;
	}

	dessert[map[cur.first][cur.second] - 1] = false;

	return result;
}

int find_max_route(point start) {
	vector<bool> dessert(100, false);
	vector<bool> dir(4, false);

	int result = - 1;

	dessert[map[start.first][start.second] - 1] = true;

	for (int i = 0; i < 4; i++) {
		int new_row = start.first + drow[i];
		int new_col = start.second + dcol[i];
		dir[i] = true;

		int buffer = visite_cafe(start, make_pair(new_row, new_col), i, 1, 1, dessert, dir);

		if (buffer > result)
			result = buffer;

		buffer = visite_cafe(start, make_pair(new_row, new_col), i, -1, 1, dessert, dir);

		if (buffer > result)
			result = buffer;

		dir[i] = false;
	}

	return result;
}

int main() {
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int result = -1;

		cin >> N;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> map[j][k];
			}
		}

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				int buffer = find_max_route(make_pair(j, k));

				if (buffer > result)
					result = buffer;
			}
		}

		cout << "#" << i << " " << result << endl;
	}

	return 0;
}