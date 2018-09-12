#include <string>
#include<unordered_map>
#include<vector>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	
	unordered_map<string, int> counter;
	float size1 = 0, size2 = 0, common = 0;

	for (int i = 0; i < str1.length() - 1; i++) {
		if (('a' <= str1[i] && str1[i] <= 'z') || ('A' <= str1[i] && str1[i] <= 'Z')) {
			if (('a' <= str1[i + 1] && str1[i + 1] <= 'z') || ('A' <= str1[i + 1] && str1[i + 1] <= 'Z')) {
				string token = str1.substr(i, 2);
				size1++;

				for (int j = 0; j < 2; j++) {
					if (token[j] > 'Z')
						token[j] -= 32;
				}

				if (counter.find(token) == counter.end()) {
					counter[token] = 0;
				}
				else {
					counter[token]++;
				}
			}
			else {
				i++;
			}
		}
	}

	for (int i = 0; i < str2.length() - 1; i++) {
		if (('a' <= str2[i] && str2[i] <= 'z') || ('A' <= str2[i] && str2[i] <= 'Z')) {
			if (('a' <= str2[i + 1] && str2[i + 1] <= 'z') || ('A' <= str2[i + 1] && str2[i + 1] <= 'Z')) {
				string token = str2.substr(i, 2);
				size2++;

				for (int j = 0; j < 2; j++) {
					if (token[j] > 'Z')
						token[j] -= 32;
				}

				if (counter.find(token) != counter.end()) {
					counter[token]--;
					common++;

					if (counter[token] < 0)
						counter.erase(token);
				}
			}
			else {
				i++;
			}
		}
	}

	if (size1 == 0 && size1 == size2)
		return 65536;

	return answer = common / (size1 + size2 - common) * 65536;
}
