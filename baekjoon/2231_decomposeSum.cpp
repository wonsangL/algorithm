#include<iostream>

using namespace std;

int main() {
	int N;

	cin >> N;

	for (int i = 1; i < N; i++) {
		int compare, digit;
		compare = digit = i;
		
		while (digit > 0) {
			compare += digit % 10;
			digit /= 10;
		}

		if (compare == N) {
			cout << i << endl;
			return 0;
		}
	}

	cout << 0 << endl;
}
