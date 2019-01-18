#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string x, y;
		vector<int> result;

		cin >> x >> y;

		for (int j = 0; j < x.length(); j++)
			result.push_back(y[j] >= x[j] ? y[j] - x[j] : y[j] + 26 - x[j]);

		cout << "Distances: ";

		for (int answer : result)
			cout << answer << " ";

		cout << endl;
	}
}