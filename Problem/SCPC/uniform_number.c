#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int checkDivision(int input, int divisor) {
	if (divisor >= input)
		return 0;

	int modula = input % divisor, division = input / divisor;

	if (modula == division) {
		return divisor;
	}
	else {
		if (divisor > modula) {
			return checkDivision(input, divisor + 1);
		}
		else if (modula % division == 0) {
			return checkDivision(input, input);
		}
		else {
			if (modula % division == 0) {
				return checkDivision(input, divisor + modula / division);
			}

			return checkDivision(input, input / (division + 1));
		}
	}
}

int Answer;

int main(void)
{
	int T, test_case, input, modula, temp;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{

		scanf("%d", &input);

		Answer = input + 1;
		for (int i = 2; i < sqrt(input); i++) {
			modula = input % i;
			temp = input;

			if (modula == 0)
				continue;

			while (temp % i == modula) {
				temp /= i;
			}

			if (temp == 0) {
				Answer = i;
				break;
			}
		}

		if (Answer == input + 1) {
			temp = checkDivision(input, (int)sqrt(input) + 1);

			if (temp != 0) {
				Answer = temp;
			}
		}

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}

	return 0;
}