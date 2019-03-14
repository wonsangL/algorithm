#include<iostream>
#include<string>
#include<vector>

using namespace std;

int N, K;

void swap_vertical(vector<string> &input) {
	string tmp;

	for (int i = 0; i < N / 2; i++) {
		tmp = input[i];
		input[i] = input[N - 1 - i];
		input[N - 1 - i] = tmp;
	}
}

void swap_horizontal(vector<string> &input) {
	char tmp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N / 2; j++) {
			tmp = input[i][j];
			input[i][j] = input[i][N - 1 - j];
			input[i][N - 1 - j] = tmp;
		}
	}
}

int main() {
	cin >> N;

	vector<string> input(N);

	for (int i = 0; i < N; i++)
		cin >> input[i];

	cin >> K;

	if (K == 2) {
		swap_horizontal(input);
	}
	else if (K == 3) {
		swap_vertical(input);
	}

	for (int i = 0; i < N; i++)
		cout << input[i] << endl;
}