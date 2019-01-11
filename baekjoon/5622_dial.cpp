#include<iostream>
#include<string>

using namespace std;

int dial[] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };

int main() {
	string input;
	int answer = 0;

	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		answer += dial[input[i] - 'A'] + 1;
	}

	cout << answer << endl;
}