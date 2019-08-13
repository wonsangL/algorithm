#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	string input;
	vector<string> result;

	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		string buffer = input.substr(i);
		result.push_back(buffer);
	}

	sort(result.begin(), result.end());

	for (string answer : result)
		cout << answer << endl;
}