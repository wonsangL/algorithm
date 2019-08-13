#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main() {
	int T;
	string N;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;

		long long result = 0;

		for (int j = 0; j < N.length(); j++) {
			if ((N[j] - '0') % 2 != 0) {
				if (j != N.length() - 1) {
					long long p, n;

					if (N[j] == '9') {
						int cursor = j - 1;

						while (cursor >= 0 && N[cursor] == '8') {
							cursor--;
						}
						
						string compare;
						
						if (cursor < 0) {
							compare = "2" + string(N.length(), '0');
							p = stoll(compare) - stod(N);
						}
						else {
							p = (N[cursor] - '0' + 2 ) * pow(10, N.length() - cursor - 1) - stoll(N.substr(cursor));
						}	

						n = stoll(N.substr(j)) - stoll(string(N.length() - j, '8'));
					}
					else {
						p = pow(10, N.length() - j - 1) - stoll(N.substr(j + 1));
						n = pow(10, N.length() - j - 1) + stoll(N.substr(j + 1)) - stoll(string(N.length() - j - 1, '8'));
					}

					result = p > n ? n : p;
				}
				else {
					result = 1;
				}

				break;
			}
		}

		cout << "Case #" << i + 1 << ": " << result << endl;
	}
}