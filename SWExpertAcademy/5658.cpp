#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K, size;
		char input[29], *stop;
		vector<long> result;

		cin >> N >> K >> input;

		size = N / 4;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < 4; j++) {
				char buffer[8];
				int k;

				for (k = 0; k < size; k++) {
					buffer[k] = input[(i + (j * size) + k) % N];
				}

				buffer[k] = '\0';

				long parse = strtol(buffer, &stop, 16);
				bool flag = false;

				for (int k = 0; k < result.size(); k++) {
					if (result[k] == parse) {
						flag = true;
						break;
					}
				}

				if(!flag)
					result.push_back(parse);
			}
		}

		sort(result.begin(), result.end(), greater<int>());

		cout << "#" << test_case << " " << result[K - 1] << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}