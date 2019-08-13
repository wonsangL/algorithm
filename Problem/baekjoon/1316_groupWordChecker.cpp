#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	int answer = 0, N;
	string input;
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		bool flag = true;
		vector<bool> visited(26, false);

		cin >> input;

		for (int j = 0; j < input.length() && flag; j++) {
			if (j == 0) {
				visited[input[j] - 'a'] = true;
				continue;
			}

			if (input[j] != input[j - 1]) {
				if (visited[input[j] - 'a']) {
					flag = false;
					break;
				}else
					visited[input[j] - 'a'] = true;
			}
		}

		if (flag)
			answer++;
	}

	cout << answer << endl;
}