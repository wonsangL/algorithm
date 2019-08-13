#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	vector<int> result;

	for (int i = 0; i < 5; i++) {
		string input;
		cin >> input;

		int find = input.find("FBI");
		
		if (find != -1)
			result.push_back(i + 1);
	}

	if (result.size() == 0) {
		cout << "HE GOT AWAY!" << endl;
		return 0;
	}

	for (int answer : result)
		cout << answer << " ";
}