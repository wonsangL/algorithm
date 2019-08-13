#include<iostream>
#include<math.h>
#include<vector>
#include<utility>

using namespace std;

typedef pair<int, int> p;

int map[20][20];

int T, N, M;

int get_distance(p &origin, p &a) {
	return abs(a.first - origin.first) + abs(a.second - origin.second);
}

void solution(int row, int col, vector<p> &house) {
	int result = 0;
	p origin = make_pair(row, col);

	for (int i = 1; i <= 21; i++) {
		int count = 0;

		for (int j = 0; j < house.size(); j++) {
			if (get_distance(origin, house[j]) < i)
				count++;
		}

		if (count * M - (i * i + (i - 1) * (i - 1)) >= 0 && count > result)
			result = count;
	}

	map[row][col] = result;
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		vector<p> house;
		int result = 0;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> map[j][k];

				if (map[j][k] == 1)
					house.push_back(make_pair(j, k));
			}
		}

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				solution(j, k, house);

				if (map[j][k] > result)
					result = map[j][k];
			}
		}

		cout << "#" << i + 1 << " " << result << endl;
	}
}