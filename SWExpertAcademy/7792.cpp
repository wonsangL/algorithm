#include<iostream>
#include<string>

using namespace std;

class Result {
public:
	int domain;
	string name = "";

	void compare(string input) {
		bool alphabet[26];
		int input_domain = 0;

		for (int i = 0; i < 26; i++) {
			alphabet[i] = false;
		}

		for (int i = 0; i < input.length(); i++) {
			if (input[i] != ' ' && !alphabet[input[i] - 'A']) {
				alphabet[input[i] - 'A'] = true;
				input_domain++;
			}
		}

		if (name.empty()) {
			domain = input_domain;
			name = input;
			return;
		}

		if (input_domain > domain) {
			domain = input_domain;
			name = input;
			return;
		}

		if (input_domain == domain) {
			int length = name.length() > input.length() ? input.length() : name.length();
			for (int i = 0; i < length; i++) {
				if (name[i] < input[i]) {
					return;
				}

				if (name[i] > input[i]) {
					domain = input_domain;
					name = input;
					return;
				}
			}

			if (name.length() > input.length()) {
				name = input;
				domain = input_domain;
			}
		}	
	}
};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		Result result;
		cin.ignore();

		for (int i = 0; i < n; i++) {
			string input;
			getline(cin, input);

			result.compare(input);
		}

		cout << "#" << test_case << " " << result.name << endl;
	} 
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}