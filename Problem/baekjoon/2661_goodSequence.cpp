#include<iostream>
#include<string>

using namespace std;

int N;
string num[] = { "1", "2", "3" };

bool CheckSequence(string &seq) {
	int length = seq.length();
	bool result = true;

	for (int i = 1; i <= length / 2; i++) {
		if (seq[length - 1] == seq[length - 1 - i]) {
			result = false;

			for (int j = 1; j < i; j++) {
				if (seq[length - 1 - j] != seq[length - 1 - i - j]) {
					result = true;
					break;
				}
			}

			if (!result)
				return result;
		}
	}

	return result;
}

string GetSequence(string result, int length) {
	if (length == 0)
		return result;

	for (int i = 0; i < 3; i++) {
		string buffer = result + num[i];
		
		if (CheckSequence(buffer)) {
			buffer = GetSequence(buffer, length - 1);
			
			if (buffer.length() == N)
				return buffer;
		}
	}

	return "";
}

int main() {
	cin >> N;
	cout << GetSequence("1", N - 1) <<endl;
}