#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

vector<int> most_divisor[9];

int get_most_divisor(int x, int digit) {
	if (digit < 0) {
		return 0;
	}

	int result = 0;

	if (!most_divisor[digit].empty()) {
		for (int i = 0; i < most_divisor[digit].size(); i++) {
			if (most_divisor[digit][i] <= x) {
				result++;
			}
		}

		return result + get_most_divisor(x, digit - 1);
	}

	for (int i = 1; i <= sqrt(pow(10, digit + 1)); i++) {
		if ((int)pow(10, digit + 1) % i != 0) {
			continue;
		}

		if (i > pow(10, digit)) {
			if (i <= x) {
				result++;
			}

			most_divisor[digit].push_back(i);
		}

		if (pow(10, digit + 1) / i > pow(10, digit)) {
			if (pow(10, digit + 1) / i <= x) {
				result++;
			}

			most_divisor[digit].push_back(pow(10, digit + 1) / i);
		}
	}

	return result + get_most_divisor(x, digit - 1);
}

int get_digit(int input) {
	int result = 0;

	while (input > 10) {
		input /= 10;
		result++;
	}

	return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	most_divisor[0].push_back(1);
	most_divisor[0].push_back(2);
	most_divisor[0].push_back(5);
	most_divisor[0].push_back(10);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int x, answer = 0; 
		cin >> x;

		cout << "#" << test_case << " " << get_most_divisor(x, get_digit(x)) << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}