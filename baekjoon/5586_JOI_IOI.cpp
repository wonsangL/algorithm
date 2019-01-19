#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool checkOI(string input, int index) {
	if (index + 2 >= input.length())
		return false;

	if (input[index + 1] == 'O' && input[index + 2] == 'I')
		return true;

	return false;
}

int main() {
	string input;
	int joi = 0, ioi = 0;

	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == 'J') {
			if (checkOI(input, i)) {
				joi++;
				i++;
			}
		}
		else if (input[i] == 'I') {
			if (checkOI(input, i)) {
				ioi++;
				i++;
			}
		}
	}

	cout << joi << endl;
	cout << ioi << endl;
}