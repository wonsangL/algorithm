#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int result = 0, bar = 0;
		string input;

		cin >> input;

		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '(') {
				if (input[i + 1] == ')') {
					result += bar;
					i++;
					continue;
				}

				bar++;
			}
			else {
				bar--;
				result++;
			}
		}

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}