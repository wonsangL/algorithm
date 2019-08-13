#include<iostream>
#include<string>

using namespace std;

int main() {
	string line;
	int answer = 0;

	for (int i = 0; i < 8; i++) {
		cin >> line;

		for (int j = i % 2 == 0 ? 0 : 1 ; j < 8; j += 2) {
			if (line[j] == 'F')
				answer++;
		}
	}

	cout << answer << endl;
}