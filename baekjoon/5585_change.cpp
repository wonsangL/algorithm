#include<iostream>

using namespace std;

int main() {
	int input;

	cin >> input;

	int change = 1000 - input;
	int money[] = { 500, 100, 50, 10, 5, 1 };
	int result = 0;

	for (int i = 0; i < 6; i++) {
		result += change / money[i];
		change = change % money[i];
	}

	cout << result << endl;

	return 0;
}