#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int t, n;

struct COORD {
	int x;
	int y;
	COORD(int x, int y) : x(x), y(y) {}
};

float CalDistance(COORD a, COORD b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void PathFind(vector<COORD> &position, bool visit[], int index) {
	if (index == n + 1)
		return;

	for (int i = 0; i < n + 2; i++) {
		if (!visit[i] && i != index) {
			if (CalDistance(position[index], position[i]) <= 1000) {
				visit[i] = true;
				PathFind(position, visit, i);
			}
		}
	}
}

int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<COORD> position;
		bool *visit = new bool[n + 2];

		for (int j = 0; j < n + 2; j++) {
			int x, y;
			cin >> x >> y;
			COORD buffer(x, y);
			position.push_back(buffer);
			visit[j] = false;
		}

		visit[0] = true;
		PathFind(position, visit, 0);

		if (visit[n + 1])
			cout << "happy" << endl;
		else
			cout << "sad" << endl;
	}

	return 0;
}