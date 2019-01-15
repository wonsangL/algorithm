#include<iostream>
#include<string>

using namespace std;

int main() {
	int result = 0;
	string input;

	cin >> input;

	for (char word : input)
		if (word == 'a' || word == 'i' || word == 'e' || word == 'o' || word == 'u')
			result++;

	cout << result << endl;
}