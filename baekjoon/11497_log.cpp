#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int T;
	
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int N, temp, result = 0;

		vector<int> log;

		std::cin >> N;

		for (int j = 0; j < N; j++) {
			std::cin >> temp;
			log.push_back(temp);
		}

		sort(log.begin(), log.end());

		if (log[0] == log[N - 1]) {
			std::cout << result << std::endl;
			return 0;
		}
		
		for (vector<int>::size_type j = 2; j < N; j++) {
			if (log[j] - log[j - 2] > result) {
				result = log[j] - log[j - 2];
			}
		}
		
		std::cout << result << std::endl;
	}


	return 0;
}