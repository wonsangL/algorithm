#include<iostream>
#include<string>
#include<vector>

using namespace std;

string solution(string input) {
	vector<int> index;
	string result;

	index.push_back(0);

	for (int i = 1; i < input.length(); i++) {
		if (input[i] == '-')
			index.push_back(i + 1);
	}

	for (int i : index) {
		result += input[i];
	}

	return result;
}

int main() {
	string input;

	cin >> input;

	cout << solution(input) << endl;
}