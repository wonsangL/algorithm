#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
	string input;

	cin >> input;

	for (int i = 0; i < input.length() / 2; i++) {
		if (input[i] != input[input.length() - i - 1]) {
			cout << 0 << endl;
			return 0;
		}
	}

	cout << 1 << endl;
}