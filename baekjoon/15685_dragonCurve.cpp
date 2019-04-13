#include<iostream>
#include<vector>

using namespace std;

bool board[101][101];
int d_x[] = { 1, 0, -1, 0 };
int d_y[] = { 0, -1, 0, 1 };

int N;

void draw_curve(int x, int y, int d, int g) {
	vector<int> q;
	int new_x = x + d_x[d];
	int new_y = y + d_y[d];

	q.push_back(d);

	board[x][y] = true;
	board[new_x][new_y] = true;

	for (int i = 0; i < g; i++) {
		for (int j = q.size() - 1; j >= 0; j--) {
			int new_d = ( q[j] + 1 ) % 4;

			new_x = new_x + d_x[new_d];
			new_y = new_y + d_y[new_d];

			board[new_x][new_y] = true;
			q.push_back(new_d);
		}
	}
}

int main() {
	int result = 0;

	cin >> N;

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++)
			board[i][j] = false;
	}

	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		draw_curve(x, y, d, g);
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) {
				result++;
			}
		}
	}

	cout << result << endl;
	return 0;
}