#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	string a, b;
	int length = 0;

	cin >> a >> b;

	vector<bool> comp(b.size(), false);

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j] && !comp[j]) {
				length++;
				comp[j] = true;
				break;
			}
		}
	}

	cout << a.size() + b.size() - 2 * length << endl;
}