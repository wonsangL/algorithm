#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string T, P;

	getline(cin, T);
	getline(cin, P);

	int N = T.length();
	int M = P.length();

	vector<int> pi(M, 0);
	vector<int> answer;
	int answerNum;

	//pi 구하기
	for (int i = 1, j = 0; i < M; i++) {
		while (j > 0 && P[i] != P[j])
			j = pi[j - 1];

		if (P[i] == P[j])
			pi[i] = ++j;
	}

	//kmp 알고리즘
	for (int i = 0, j = 0; i < N; i++) {
		while (j > 0 && T[i] != P[j])
			j = pi[j - 1];

		if (T[i] == P[j]) {
			if (j == M - 1) {
				answer.push_back(i - M + 2);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}

	answerNum = answer.size();
	
	cout << answerNum << endl;
	for (int i = 0; i < answerNum; i++) {
		cout << answer[i] << " ";
	}
	cout << endl;

	return 0;
}