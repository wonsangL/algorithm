#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool checkPwd(string a, string b) {
	for (int i = 0; i < a.length() / 2; i++) {
		if (a[i] != b[a.length() - i - 1])
			return false;
	}

	return true;
}

int main() {
	int N;
	vector<vector<string>> input[11];

	cin >> N;

	for (int i = 0; i < 11; i += 2) 
		input[i] = vector<vector<string>>(26);

	for (int i = 0; i < N; i++) {
		string buffer;
		cin >> buffer;

		input[buffer.length() - 3][buffer[0] - 'a'].push_back(buffer);
	}

	for (int i = 0; i < 11; i += 2) {
		//length
		for (int j = 0; j < input[i].size(); j++) {
			//alphabet
			for (string cmp : input[i][j]) {
				for (int k = 0; k < input[i][cmp[cmp.length() - 1] - 'a'].size(); k++) {
					if (checkPwd(cmp, input[i][cmp[cmp.length() - 1] - 'a'][k])) {
						cout << cmp.length() << " " << cmp[cmp.length() / 2] << endl;
						return 0;
					}
				}
			}
		}
	}
}