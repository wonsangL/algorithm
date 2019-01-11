#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string input;
	vector<int> alphabet(26, 0);

	cin >> input;

	for (int i = 0; i < input.length(); i++)
		alphabet[input[i] - 'a']++;

	for (int i = 0; i < alphabet.size(); i++)
		cout << alphabet[i] << " ";
	cout << endl;
}