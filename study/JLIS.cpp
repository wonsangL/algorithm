#include<iostream>
#include<vector>
#define MAX(a, b) (((a) > (b))? (a) : (b))

using namespace std;
int T, n, m, Answer = 0;

int length(vector<int> &first, vector<int> &second) {
	vector<int> merge;

	merge.assign(first.begin(), first.end());
	merge.insert(merge.end(), second.begin(), second.end());

	for (vector<int>::iterator it = merge.begin(); it != merge.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		int buffer;

		vector<int> first;
		vector<int> second;

		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			cin >> buffer;
			first.push_back(buffer);
		}

		for (int j = 0; j < m; j++) {
			cin >> buffer;
			second.push_back(buffer);
		}

		Answer = MAX(length(first, second), length(second, first));
	}
}