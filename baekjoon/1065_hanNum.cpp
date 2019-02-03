#include<iostream>

using namespace std;

bool check(int input) {
	int first = input % 10, second, diff = 10;

	input /= 10;

	while (input > 0) {
		second = input % 10;

		if (diff == 10) {
			diff = second - first;
			first = second;
			input /= 10;
			continue;
		}

		if (second - first != diff)
			return false;

		first = second;
		input /= 10;
	}

	return true;
}

int main() {
	int answer = 99, input;

	cin >> input;

	if (input < 100) {
		cout << input << endl;
		return 0;
	}
		

	for (int i = 100; i <= input; i++) {
		if (check(i))
			answer++;
	}

	cout << answer << endl;
}