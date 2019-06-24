#include <vector>

using namespace std;

int d_row[] = { 0, -1, 0, 1 };
int d_col[] = { -1, 0, 1, 0 };

void initialize(vector<vector<bool>> &visited, int m, int n) {
	visited = vector<vector<bool>>(m);

	for (int i = 0; i < m; i++) {
		visited[i] = vector<bool>(n);

		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}

int check_area(vector<vector<int>> picture, vector<vector<bool>> &visited, int row, int col) {
	if (picture[row][col] == 0 || visited[row][col]) {
		return 0;
	}

	int result = 1;
	visited[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int n_row = row + d_row[i];
		int n_col = col + d_col[i];

		if (n_row < 0 || n_row >= picture.size() || n_col < 0 || n_col >= picture[row].size()) {
			continue;
		}

		if (!visited[n_row][n_col] && picture[row][col] == picture[n_row][n_col]) {
			result += check_area(picture, visited, n_row, n_col);
		}	
	}

	return result;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int max_size_of_one_area = 0;

	vector<vector<bool>> visited;
	vector<int> area_size;

	initialize(visited, picture.size(), picture[0].size());

	for (int i = 0; i < picture.size(); i++) {
		for (int j = 0; j < picture[i].size(); j++) {
			int size = check_area(picture, visited, i, j);
			
			if (size != 0) {
				area_size.push_back(size);
			}
		}
	}

	vector<int> answer(2);
	answer[0] = area_size.size();

	for (int i = 0; i < area_size.size(); i++) {
		if (max_size_of_one_area < area_size[i]) {
			max_size_of_one_area = area_size[i];
		}
	}

	answer[1] = max_size_of_one_area;
	return answer;
}
