#include<iostream>
#include<utility>
#include<vector>
#include<math.h>

using namespace std;
typedef pair<int, int> p;

int W, H, D;
int map[15][15];

int get_distance(p a, p b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int solution(vector<int> &archor, vector<p> enemy) {
	int result = 0;
	vector<bool> death(enemy.size(), false);

	while (true) {
		vector<int> target(3, -1);
		bool finished = true;

		for (int i = 0; i < archor.size(); i++) {
			p archor_pos = make_pair(H, archor[i]);

			for (int j = enemy.size() - 1; j >= 0; j--) {
				if (!death[j] && get_distance(archor_pos, enemy[j]) <= D) {
					if (target[i] != -1) {
						if (get_distance(archor_pos, enemy[j]) < get_distance(archor_pos, enemy[target[i]])) {
							target[i] = j;
						}
						else if (get_distance(archor_pos, enemy[j]) == get_distance(archor_pos, enemy[target[i]])) {
							if(enemy[j].second < enemy[target[i]].second)
								target[i] = j;
						}
					}
					else {
						target[i] = j;
					}
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			if (target[i] != -1 && !death[target[i]]) {
				death[target[i]] = true;
				result++;
			}
		}

		for (int i = 0; i < enemy.size(); i++) {
			enemy[i].first += 1;

			if (enemy[i].first == H)
				death[i] = true;
		}

		for (int i = 0; i < death.size(); i++) {
			if (!death[i]) {
				finished = false;
				break;
			}
		}

		if (finished)
			break;
	}

	return result;
}

int main() {
	vector<p> enemy;
	int result = 0;

	cin >> H >> W >> D;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1)
				enemy.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < W; i++) {
		for (int j = i + 1; j < W; j++) {
			for (int k = j + 1; k < W; k++) {
				vector<int> archor = { i , j, k };

				int tmp = solution(archor, enemy);

				if (tmp > result)
					result = tmp;
			}
		}
	}

	cout << result << endl;
}