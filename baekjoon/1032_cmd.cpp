#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	int N;
	vector<string> input;
	string result;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string buffer;
		cin >> buffer;
		input.push_back(buffer);
	}

	result = input[0];
		
	for (int i = 0; i < input[0].length(); i++) {
		for (int j = 1; j < N; j++) {
			if (result[i] != input[j][i]) {
				result[i] = '?';
				break;
			}
		}
	}

	cout << result << endl;
}