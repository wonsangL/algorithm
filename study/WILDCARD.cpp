#include<iostream>
#include<string>
#include<vector>

using namespace std;

int C, n;
string pattern;
string *fileName;
vector<string> result;

bool Check(string input) {
	for (int i = 0; i < pattern.length(); i++) {
		if (pattern.at(i) == '*' || pattern.at(i) == '?') {

		}
		else {
			if (pattern.at(i) != input.at(i)) {
				return false;
			}
		}
	}
	
	return true;
}

int main() {
	cin >> C;

	for (int i = 0; i < C; i++) {
		result.clear();

		cin >> pattern >> n;

		fileName = new string[n];

		for (int i = 0; i < n; i++) {
			cin >> fileName[i];
			
			if (Check(fileName[i])) {
				result.push_back(fileName[i]);
			}
		}

		delete[] fileName;
		
		for (int j = 0; j < result.size(); j++) {
			cout << result[i] << endl;
		}
	}
}