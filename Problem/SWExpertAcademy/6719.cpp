#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, k;
		double result = 0;
		vector<int> lecture;
		
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			lecture.push_back(input);
		}

		sort(lecture.begin(), lecture.end());
		
		for (int i = k - 1; i >= 0; i--) {
			result += pow(2, i) * lecture[n - 1];
			n--;
		}

		cout.setf(ios::showpoint);
		cout.precision(7);
		cout << "#" << test_case << " " << result / pow(2, k) << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}