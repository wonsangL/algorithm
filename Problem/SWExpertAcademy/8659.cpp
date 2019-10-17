#include<iostream>
#include<utility>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int k;
		cin >> k;
		pair<long long, long long> result = make_pair(2, 1);

		if (k == 1) {
			cout << "#" << test_case << " " << result.first << " " << result.second << endl;
			continue;
		}

		for (; k > 1; --k) {
			long long a = result.first;
			long long b = result.second;

			result = make_pair(a + b, a);
		}

		cout << "#" << test_case << " " << result.first << " " << result.second << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}