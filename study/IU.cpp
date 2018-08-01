#include<iostream>
#include<math.h>

using namespace std;

int Check(int dif, int level, int def, int limit, int &answer) {
	if (dif == 0) {
		answer++;
		return 0;
	}
	else fi(dif < 0) {
		return -1;
	}

	int temp = 2 * pow(3, level - def);

	int recursive = dif / temp;

	for (int i = 1; i < limit && i < recursive; i++) {
		Check(dif - temp * i, level, def - 1, i, answer);
	}
}

int solution(int n) {
	int answer = 0, level = 1, min;

	while (true) {
		if (n < pow(3, level) + level * 2) {
			break;
		}

		level++;
	}

	min = pow(3, level) + level * 2;

	Check(n - min, level, level, 38, answer);

	return answer;
}

int main(){
	int input;

	cin >> input;

	cout << solution(input) << endl;
}