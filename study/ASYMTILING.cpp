#include<iostream>
#define DIV 1000000007

using namespace std;

int C, n, Answer = 0;

int Cal(int x, int y) {
	int result = 1;

	for (int i = x + y; i > x; i--) {
		result *= i;
	}

	for (int i = 2; i <= y; i++) {
		result /= i;
	}

	return result;
}

int main() {
	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> n;

		for (int j = n - 1; j > 0; j--) {
			if ((n - j) % 2 == 0) {
				int x = (n - j) / 2;

				Answer += Cal(j, x);

				if ((x + j - 1) % 2 == 0)
					Answer--;
			}
		}

		cout << Answer << endl;
	}
}