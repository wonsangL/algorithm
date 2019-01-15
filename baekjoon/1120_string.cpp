#include<iostream>
#include<string>

using namespace std;

int main() {
	string A, B;
	int answer = 51;

	cin >> A >> B;

	for (int i = 0; i <= B.length() - A.length(); i++) {
		int indexB = i;
		int result = 0;

		for (int j = 0; j < A.length(); j++) {
			if (B[indexB++] != A[j])
				result++;
		}

		if (answer > result)
			answer = result;
	}

	cout << answer << endl;
}