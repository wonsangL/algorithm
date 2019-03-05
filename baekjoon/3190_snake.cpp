#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int N, K, L;

int dir_graph[100][100] = { 0 };

int drow[] = { 0, 1, 0, -1 };
int dcol[] = { 1, 0, -1, 0 };

bool collision_body(pair<int, int> newPos, pair<int, int> origin, int length) {
	bool body[100][100];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			body[i][j] = false;
		}
	}

	body[newPos.first][newPos.second] = true;

	while (length != 0) {
		int row = origin.first;
		int col = origin.second;

		if (body[origin.first][origin.second])
			return false;

		body[origin.first][origin.second] = true;

		origin.first += drow[(dir_graph[row][col] + 2) % 4];
		origin.second += dcol[(dir_graph[row][col] + 2) % 4];

		length--;
	}

	return true;
}

int main() {
	int result = 0, dir = 0, length = 1, timer = 0;

	pair<int, int> head = make_pair(0, 0);

	bool apple[100][100];
	vector<pair<int, char>> turn_info;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			apple[i][j] = false;
	}

	for (int i = 0; i < K; i++) {
		int row, col;
		cin >> row >> col;
		apple[row - 1][col - 1] = true;
	}

	cin >> L;

	for (int i = 0; i < L; i++) {
		int x; char dir_input;
		cin >> x >> dir_input;

		turn_info.push_back(make_pair(x - timer, dir_input));

		timer = x;
	}

	turn_info.push_back(make_pair(100, 'E'));

	for (int i = 0; i < turn_info.size(); i++) {
		for (int j = 0; j < turn_info[i].first; j++) {
			result++;

			if (head.first + drow[dir] >= N || head.first + drow[dir] < 0 || head.second + dcol[dir] >= N || head.second + dcol[dir] < 0) {
				cout << result << endl;
				return 0;
			}
			
			if (!collision_body(make_pair(head.first + drow[dir], head.second + dcol[dir]), head, length)) {
				cout << result << endl;
				return 0;
			}

			head.first += drow[dir];
			head.second += dcol[dir];

			dir_graph[head.first][head.second] = dir;

			if (apple[head.first][head.second]) {
				apple[head.first][head.second] = false;	
				length++;
			}
		}

		if (turn_info[i].second == 'D')
			dir = (dir + 1) >= 4 ? 0 : dir + 1;
		else
			dir = (dir - 1) < 0 ? 3 : dir - 1;
	}
}