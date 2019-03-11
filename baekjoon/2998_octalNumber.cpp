#include<iostream>
#include<math.h>
#include<string>

using namespace std;

int main() {
	string input;
	string result = "";

	cin >> input;

	while (input.length() % 3 != 0) {
		input = "0" + input;
	}

	for (int i = 0; i < input.length(); i += 3) {
		int buffer = 0;

		for (int j = 0; j < 3; j++) {
			if (input[i + j] == '1') {
				buffer += pow(2, 2 - j);
			}
		}
		result += to_string(buffer);
	}

	cout << result << endl;
}