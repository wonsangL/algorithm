#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> dwarf;

bool findDwarf(vector<int> &result, int sum, int index) {
	sum += dwarf[index];
	result.push_back(dwarf[index]);

	if (result.size() > 7 || sum > 100) {
		result.pop_back();
		return false;
	}
		
	if (sum == 100 && result.size() == 7)
		return true;

	for (int i = index + 1; i < dwarf.size(); i++) {
		if (findDwarf(result, sum, i))
			return true;
	}

	result.pop_back();
	return false;
}

int main() {
	vector<int> result;

	for (int i = 0; i < 9; i++) {
		int buffer;
		cin >> buffer;
		dwarf.push_back(buffer);
	}

	for (int i = 0; i < dwarf.size(); i++) {
		if (findDwarf(result, 0, i)) {
			sort(result.begin(), result.end());

			for (int answer : result)
				cout << answer << endl;

			return 0;
		}
	}
}