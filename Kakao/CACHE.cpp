#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool StringCompare(const string &str1, const string &str2) {
	if (str1.length() != str2.length())
		return false;

	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] != str2[i] && str1[i] != str2[i] - 32 && str1[i] - 32 != str2[i])
			return false;
	}

	return true;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vector<string> cache;

	for (int i = 0; i < cities.size(); i++) {
		bool flag = false;

		for (int j = 0; j < cacheSize && j < cache.size(); j++) {
			if (StringCompare(cities[i], cache[j])) {
				cache.erase(cache.begin() + j);
				flag = true;
				break;
			}
		}

		cache.resize(cacheSize);
		cache.insert(cache.begin(), cities[i]);

		if (flag)
			answer += 1;
		else
			answer += 5;
	}

	return answer;
}

int main() {
	cout << solution(3, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" }) << endl;
}