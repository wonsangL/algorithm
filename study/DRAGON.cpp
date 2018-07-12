#include<iostream>

using namespace std;

int C, n, p, l;

int main() {
	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> n >> p >> l;

		int div = p / 6;
		int mod = p % 6;
		bool flag = false;

		if (div % 2 == 1) {
			flag = true;
		}

		for (int j = mod; j < mod + l; j++) {
			switch (j % 6) {
			case 0:

				break;
			case 1:
				cout << 'F';
				break;
			case 2:
				cout << 'X';
				break;
			case 3:
				if (flag) {
					cout << '-';
					flag = false;
				}
				else {
					cout << '+';
					flag = true;
				}
				break;
			case 4:
				break;
				cout << 'Y';
			case 5:
				cout << 'F';
				break;
			}
		}
	}
}