#include<iostream>
#include<vector>

using namespace std;

void recursion(int n, int count, vector<int> list) {
	if (count == 0) {
		cout << "(";
		for (vector<int>::iterator it = list.begin(); it != list.end(); it++) {
			cout << *it << " ";
		}
		cout << ")" << endl;
		
		return;
	}

	if (list.empty()) {
		for (int i = 0; i <= n - count; i++) {
			list.push_back(i + 1);
			recursion(n, count - 1, list);
			list.pop_back();
		}
	}
	else {
		for (int i = list[list.size() - 1]; i < n; i++) {
			list.push_back(i + 1);
			recursion(n, count - 1, list);
			list.pop_back();
		}
	}
}

int main() {
	vector<int> list;
	int n, count;
	cin >> n >> count;

	recursion(n, count, list);
}