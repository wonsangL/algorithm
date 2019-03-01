#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int result = 0, N, S, nSum = 0, pSum = 0;

void GetResult(vector<int> &input, int index, int sum) {
	if (index >= N)
		return;

	sum += input[index];

	if (sum == S) {
		result++;
	}

	for (int i = index + 1; i < N; i++) {
		GetResult(input, i, sum);
	}

	return;
}

int main() {
	vector<int> input;

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int buffer;
		cin >> buffer;
		input.push_back(buffer);

		if (buffer < 0)
			nSum += buffer;
		else
			pSum += buffer;
	}

	for (int i = 0; i < N; i++) {
		GetResult(input, i, 0);
	}

	cout << result << endl;
}