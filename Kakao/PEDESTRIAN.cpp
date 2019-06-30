#include <vector>

using namespace std;

int MOD = 20170805;

int d_row[] = { 1, 0 };
int d_col[] = { 0, 1 };

void initialize(int m, int n, vector<vector<int>> &route) {
	route = vector<vector<int>>(m);

	for (int i = 0; i < m; i++) {
		route[i] = vector<int>(n);

		for (int j = 0; j < n; j++) {
			if (i == m - 1 && j == n - 1) {
				route[i][j] = 1;
				continue;
			}
			
			route[i][j] = -1;
		}
	}
}

int get_route(int row, int col, int dir, vector<vector<int>> &city_map, vector<vector<int>> &route) {
	if (route[row][col] != -1) {
		return route[row][col];
	}

	if (city_map[row][col] == 2) {
		int new_row = row + d_row[dir];
		int new_col = col + d_col[dir];

		if (new_row < city_map.size() && new_col < city_map[row].size()) {
			return get_route(new_row, new_col, dir, city_map, route);
		}
		
		return 0;
	}

	int result = 0;

	if (city_map[row][col] == 0) {
		for (int i = 0; i < 2; i++) {
			int new_row = row + d_row[i];
			int new_col = col + d_col[i];

			if (new_row < city_map.size() && new_col < city_map[row].size()) {
				result += get_route(new_row, new_col, i, city_map, route);
			}
		}
	} 
	
	return route[row][col] = result % MOD;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	vector<vector<int>> route;
	initialize(m, n, route);
	
	return get_route(0, 0, 0, city_map, route);
}