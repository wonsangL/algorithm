#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	string A, B;
	int minA, maxA, minB, maxB;
	
	cin >> A >> B;

	for (int i = 0; i < A.length(); i++) {
		if (A[i] == '5')
			A[i] = '6';
	}

	maxA = stoi(A);

	for (int i = 0; i < A.length(); i++) {
		if (A[i] == '6')
			A[i] = '5';
	}

	minA = stoi(A);

	for (int i = 0; i < B.length(); i++) {
		if (B[i] == '5')
			B[i] = '6';
	}

	maxB = stoi(B);

	for (int i = 0; i < B.length(); i++) {
		if (B[i] == '6')
			B[i] = '5';
	}

	minB = stoi(B);

	cout << minA + minB << " " << maxA + maxB << endl;
}