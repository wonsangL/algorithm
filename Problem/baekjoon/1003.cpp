#include<iostream>
#include<utility>

using namespace std;

pair<int, int> counter[40];

pair<int, int> fibonacci(int n) {
	if ((counter[n].first != 0 && counter[n].second != 0) || (n == 1 || n == 0)) {
		return counter[n];
	}

	pair<int, int> n_1 = fibonacci(n - 1);
	pair<int, int> n_2 = fibonacci(n - 2);

	return counter[n] = make_pair(n_1.first + n_2.first, n_1.second + n_2.second);
}

int main() {
	int T; 
	cin >> T;

	counter[0] = make_pair(1, 0);
	counter[1] = make_pair(0, 1);

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		pair<int, int> answer = fibonacci(N);

		cout << answer.first << " " << answer.second << endl;
	}
}