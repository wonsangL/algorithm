#include<iostream>

using namespace std;

int counter[1000001];

int get_count(int n) {
	if (n == 1) {
		return 1;
	}

	if (counter[n] != -1) {
		return counter[n];
	}

	int result = 1000001;
	int temp;

	for (int i = 2; i <= 3; i++) {
		if (n % i == 0) {
			temp = get_count(n / i);
			if (temp < result) {
				result = temp;
			}
		}
	}

	temp = get_count(n - 1);
	if (temp < result) {
		result = temp;
	}

	return counter[n] = result + 1;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < 1000001; i++) {
		counter[i] = -1;
	}

	cout << get_count(N) << endl;
}