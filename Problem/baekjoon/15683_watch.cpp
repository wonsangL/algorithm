#include<iostream>
#include<vector>
#include<math.h>
#include<tuple>

using namespace std;

int drow[] = { 0, 1, 0, -1 };
int dcol[] = { -1, 0, 1, 0 };

int N, M; 

int office[8][8];
vector<pair<int, int>> cctv;
vector<vector<int>> cctv_dir = {
	{ 8, 4, 2, 1 }, { 10, 5 }, { 12, 6, 3, 9 }, { 14, 7, 11, 13 }, { 15 }
};

void fill_vision(int idx, int dir, int row, int col) {
	if (row == N || col == M || office[row][col] == 6 || row < 0 || col < 0)
		return;

	if (office[row][col] == 0)
		office[row][col] = -1 - idx;

	return fill_vision(idx, dir, row + drow[dir], col + dcol[dir]);
}
void remove_vision(int idx, int dir, int row, int col) {
	if (row == N || col == M || office[row][col] == 6 || row < 0 || col < 0)
		return;

	if (office[row][col] == -1 - idx)
		office[row][col] = 0;

	return remove_vision(idx, dir, row + drow[dir], col + dcol[dir]);
}

int get_min_space(int idx) {
	int result = 0;
	
	if (idx == cctv.size()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (office[i][j] == 0)
					result++;
			}
		}

		return result;
	}

	int dir_idx = office[cctv[idx].first][cctv[idx].second] - 1;
	result = 65;

	for (int i = 0; i < cctv_dir[dir_idx].size(); i++) {
		for (int j = 1; j <= 8; j *= 2) {
			if (cctv_dir[dir_idx][i] & j) {
				fill_vision(idx, log2(j), cctv[idx].first, cctv[idx].second);
			}
		}

		int buffer = get_min_space(idx + 1);

		if (result > buffer)
			result = buffer;

		for (int j = 1; j <= 8; j *= 2) {
			if (cctv_dir[dir_idx][i] & j) {
				remove_vision(idx, log2(j), cctv[idx].first, cctv[idx].second);
			}
		}
	}

	return result;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> office[i][j];
			
			if (office[i][j] != 6 && office[i][j] != 0)
				cctv.push_back(make_pair(i, j));
		}
	}

	cout << get_min_space(0) << endl;
}