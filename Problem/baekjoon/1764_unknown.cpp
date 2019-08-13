#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int stringToIndex(string input) {
	int result = 0;

	for (int i = 0; i < input.length(); i++)
		result += input[i] - 'a';

	return result;
}

int main() {
	int N, M;
	vector<vector<string>> dictionary(520);
	vector<string> result;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		char buffer[21];
		scanf("%s", buffer);

		dictionary[stringToIndex(buffer)].push_back(buffer);
	}

	for (int i = 0; i < M; i++) {
		char buffer[21];
		scanf("%s", buffer);

		int index = stringToIndex(buffer);

		for (int j = 0; j < dictionary[index].size(); j++) {
			if (buffer == dictionary[index][j]) {
				result.push_back(buffer);
				break;
			}
		}
	}

	sort(result.begin(), result.end());

	printf("%d\n", result.size());

	for (string answer : result)
		printf("%s\n", answer.c_str());
}