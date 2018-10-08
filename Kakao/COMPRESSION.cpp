#include<iostream>
#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

vector<int> solution(string msg) {
	unordered_map<string, int> dictionary;
	unordered_map<string, vector<string>> maxKey;
	vector<int> answer;		
	int keyLength = 1, index = 0;
	
	for (int i = 'A'; i <= 'Z'; i++) {
		vector<string> buffer;
		string key(1, (char)i);
		buffer.push_back(key);
		
		dictionary[key] = ++index;
		maxKey[key] = buffer;
	}

	for (int i = 0; i < msg.length();) {
		string character(1, msg[i]);
		string key(1, msg[i]);
		string newKey;

		for (int j = maxKey[character].size() - 1; j >= 0; j--) {
			if (i + maxKey[character][j].length() > msg.length())
				continue; 

			if (maxKey[character][j] == msg.substr(i, maxKey[character][j].length())) {
				key = maxKey[character][j];
				newKey = msg.substr(i, maxKey[character][j].length() + 1);
				break;
			}
		}

		//아래 코드에서 시간 초과
		/*for (int j = keyLength; j > 0; j--) {
			if (i + j > msg.length())
				j = msg.length() - 1;

			if (dictionary.find(msg.substr(i, j)) != dictionary.end()) {
				key = msg.substr(i, j);
				newKey = msg.substr(i, j + 1);
				break;
			}
		}*/

		i += key.length();
		answer.push_back(dictionary[key]);

		dictionary[newKey] = ++index;
		maxKey[character].push_back(newKey);
		
		if (newKey.length() > keyLength)
			keyLength = newKey.length();
	}

	return answer;
}

int main() {
	vector<int> result = solution("KAKAO");
	for (int i : result) {
		cout << i << " ";
	}
	cout << endl;

	result = solution("TOBEORNOTTOBEORTOBEORNOT");
	for (int i : result) {
		cout << i << " ";
	}
	cout << endl;

	result = solution("ABABABABABABABAB");
	for (int i : result) {
		cout << i << " ";
	}
	cout << endl;
}