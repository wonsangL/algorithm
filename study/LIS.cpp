#include<iostream>

using namespace std;

int C, N;
int *sequence;
int *length;

int GetLength(int index) {
	int maxLength = 0, buffer;

	if (index == N - 1){
		length[index] = 1;
		return 1;
	}
	
	int &ref = length[index];

	if (ref != 1)
		return ref;

	for (int i = index + 1; i < N; i++) {
		if (sequence[index] < sequence[i]) {
			buffer = GetLength(i);

			if (buffer > maxLength) {
				maxLength = buffer;
			}
		}
	}

	ref += maxLength;
	return ref;
}

int main() {
	cin >> C;

	for (int i = 0; i < C; i++) {
		int answer = 0, buffer;
		cin >> N;

		sequence = new int[N];
		length = new int[N];

		for (int j = 0; j < N; j++) {
			cin >> sequence[j];
			length[j] = 1;
		}

		for (int j = 0; j < N; j++) {
			buffer = GetLength(j);
			if (buffer > answer)
				answer = buffer;
		}
		
		cout << answer << endl;
		delete[] sequence;
		delete[] length;
	}
}