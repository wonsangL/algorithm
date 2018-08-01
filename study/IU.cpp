#include<iostream>
#include<cmath>

using namespace std;

int Check(int dif, int level, int def, int limit) {
	int result = 0;

	if (dif == 0) {
		return 1;
	}
	else if(dif < 0) {
		return 0;
	}

	int temp = 2 * pow(3, level - def);

	for (int i = 1; i <= limit && i <= (def - 1)  * 2; i++) {
		result += Check(dif - temp * i, level, def - 1, i);
	}

	return result;
}

int solution(int n) {
	int answer = 0, level = 1, min;

	if (n % 2 == 0) {
		return 0;
	}

	while (true) {
		if (n < pow(3, level) + level * 2) {
			break;
		}

		level++;
	}

	min = pow(3, level - 1) + (level - 1) * 2;

	answer = Check(n - min, level - 1, level - 1, 36);

	return answer;
}

int main() {
	int input;

	cin >> input;

	cout << solution(input) << endl;
}