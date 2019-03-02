#include<iostream>
#include<vector>

using namespace std;

void solution(vector<int> &input, int index, vector<int> result) {	
	if (index >= input.size())
		return;

	result.push_back(input[index]);

	if (result.size() == 6) {
		for (int i = 0; i < 5; i++) {
			cout << result[i] << " ";
		}
		cout << result[5] << endl;
		result.pop_back();

		return;
	}

	if (input.size() - index - 1 >= 6 - result.size()) {
		for (int i = index + 1; i < input.size(); i++) {
			solution(input, i, result);
		}
	}

	result.pop_back();
}

int main() {
	int k;
	cin >> k;

	while (k != 0) {
		vector<int> input;

		for (int i = 0; i < k; i++) {
			int buffer;
			cin >> buffer;
			input.push_back(buffer);
		}

		for (int i = 0; i < input.size(); i++) {
			solution(input, i, vector<int>());
		}

		cout << endl;
		
		cin >> k;
	}
}