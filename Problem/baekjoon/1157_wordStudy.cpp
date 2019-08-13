#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string input;
	vector<int> alphabet(26, 0);
	int max = 0, maxIndex;

	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] > 'Z') 
			input[i] -= 32;

		alphabet[input[i] - 'A']++;
	}

	for (int i = 0; i < alphabet.size(); i++) {
		if (alphabet[i] > max) {
			max = alphabet[i];
			maxIndex = i;
		}
	}

	for (int i = 0; i < alphabet.size(); i++) {
		if (alphabet[i] == max && i != maxIndex) {
			cout << '?' << endl;
			return 0;
		}
	}

	cout << (char)(maxIndex + 'A') << endl;
	return 0;
}