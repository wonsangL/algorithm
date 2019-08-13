#include<iostream>
#include<vector> 
#include<utility>
#include<math.h>

using namespace std;

typedef pair<int, int> p;

int move_row[] = { 0, -1, 0, 1, 0 };
int move_col[] = { 0, 0, 1, 0, -1 };

class BC {
public:
	p m_pos;
	int m_c;
	int m_p;

	BC(p pos, int c, int p) : m_pos(pos), m_c(c), m_p(p) {}
};

int get_distance(p a, p b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int M, A, result = 0;
		vector<vector<int>> movement(2);
		vector<p> user(2);
		vector<BC> ap;
		
		cin >> M >> A;

		user[0] = make_pair(1, 1);
		user[1] = make_pair(10, 10);

		for (int j = 0; j < movement.size(); j++) {
			vector<int> buffer;
			for (int k = 0; k < M; k++) {
				int tmp;
				cin >> tmp;
				buffer.push_back(tmp);
			}
			movement[j] = buffer;
		}

		for (int j = 0; j < A; j++) {
			int row, col, c, p;
			cin >> col >> row >> c >> p;
			ap.push_back(BC(make_pair(col, row), c, p));
		}

		for (int j = -1; j < M; j++) {
			int charge = 0;
			vector<vector<bool>> q(2);

			for (int k = 0; k < 2; k++)
				q[k] = vector<bool>(A, false);

			if (j != -1) {
				for (int k = 0; k < 2; k++) {
					user[k].first += move_col[movement[k][j]];
					user[k].second += move_row[movement[k][j]];
				}
			}

			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < ap.size(); l++) {
					if (get_distance(ap[l].m_pos, user[k]) <= ap[l].m_c) {
						q[k][l] = true;
					}
				}
			}

			for (int k = 0; k < A; k++) {
				if (q[0][k] || q[1][k]) {
					if (ap[k].m_p > charge)
						charge = ap[k].m_p;	
				
					for (int l = 0; l < 2; l++) {
						if (q[l][k]) { 
							for (int m = 0; m < A; m++) {
								if (k != m && q[(l + 1) % 2][m]) {
									if (ap[k].m_p + ap[m].m_p > charge)
										charge = ap[k].m_p + ap[m].m_p;
								}
							}
						}
					}
				}
			}

			result += charge;
		}

		cout << "#" << i << " " << result << endl;
	}
}