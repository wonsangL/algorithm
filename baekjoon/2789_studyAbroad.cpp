#include<iostream>
#include<string>

using namespace std;

int main() {
	char cambridge[] = { 'C','A', 'M','B','R','I','D','G','E' };

	string input;

	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		for (char c : cambridge) {
			if (c == input[i]) {
				input.erase(input.begin() + i);
				i--;
			}
		}
	}

	cout << input;
}