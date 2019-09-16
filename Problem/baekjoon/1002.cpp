#include<iostream>
#include<math.h>

using namespace std;

double get_distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int x1, y1, r1, x2, y2, r2;

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) {
				cout << -1 << endl;
				continue;
			}

			cout << 0 << endl;
			continue;
		}

		double d = get_distance(x1, y1, x2, y2);

		if (r1 + r2 == d || abs(r1 - r2) == d) {
			cout << 1 << endl;
			continue;
		}
	
		if (abs(r1 - r2) < d && d < r1 + r2) {
			cout << 2 << endl;
			continue;
		}

		cout << 0 << endl;
	}
}