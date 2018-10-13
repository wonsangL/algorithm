#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string input;
	int answer = 0;
	vector<vector<string>> dictionary(26);

	vector<string> c = { "c=", "c-" };
	dictionary['c' - 'a'] = c;
	vector<string> d = { "dz=", "d-" };
	dictionary['d' - 'a'] = d;
	vector<string> l = { "lj" };
	dictionary['l' - 'a'] = l;
	vector<string> n = { "nj" };
	dictionary['n' - 'a'] = n;
	vector<string> s = { "s=" };
	dictionary['s' - 'a'] = s;
	vector<string> z={ "z=" };
	dictionary['z' - 'a'] = z;

	cin >> input;
	
	for (int i = 0; i < input.size();) {
		bool flag = false;

		if (dictionary[input[i] - 'a'].size() > 0 && i < input.size() - 1) {
			for (int j = 0; j < dictionary[input[i] - 'a'].size() ; j++) {
				if (input.substr(i, dictionary[input[i] - 'a'][j].length()) == dictionary[input[i] - 'a'][j]) {
					answer++;
					i+= dictionary[input[i] - 'a'][j].length();
					flag = true;
					break;
				}
			}

			if (flag)
				continue;
		}

		answer++;
		i++;
	}

	cout << answer << endl;
}