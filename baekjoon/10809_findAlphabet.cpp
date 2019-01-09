#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	string input;
	vector<int> result(26, -1);

	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		if (result[input[i] - 'a'] == -1)
			result[input[i] - 'a'] = i;
	}

	for (int answer : result) {
		cout << answer << " ";
	}
	cout << endl;
}