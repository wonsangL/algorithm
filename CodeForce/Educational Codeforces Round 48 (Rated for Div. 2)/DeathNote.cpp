#include<iostream>

using namespace std;

int main() {
	int n, m, current = 0, page = 0;
	int *answer;
	
	cin >> n >> m;

	answer = new int[n];

	for (int i = 0; i < n; i++) {
		int buffer;
		cin >> buffer;

		page += buffer;

		answer[current++] = page / m;

		page = page % m;
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}

	cout << endl;

	delete[] answer;
	return 0;
}