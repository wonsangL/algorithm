#include<iostream>
#include<string>
#include<vector>

using namespace std;

int C, n;
string pattern;
string *fileName;

int main() {
	cin >> C;

	for (int i = 0; i < C; i++) {
		vector<string> result;

		cin >> pattern >> n;

		fileName = new string[n];

		for (int i = 0; i < n; i++) {
			cin >> fileName[i];
		}

		delete[] fileName;
	}
}