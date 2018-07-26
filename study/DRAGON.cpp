#include<iostream>
#include<vector>

using namespace std;

int c, n, p, l;

vector<char> op[50];

int GetLength(int gen) {
	if (gen == 0)
		return 2;

	return GetLength(gen - 1) * 2 + 1;
}

vector<char> GetOp(int gen) {
	if (gen < 0) {
		return vector<char>();
	}

	vector<char> &ref = op[gen];

	if (gen == 0) {
		ref.push_back('+');
	}
	else {
		if (ref.empty()) {
			vector<char> buffer = GetOp(gen - 1);
			
			ref.insert(ref.end(), buffer.begin(), buffer.end());
			ref.insert(ref.end(), '+');
			   
			buffer[buffer.size() / 2] = '-';
			ref.insert(ref.end(), buffer.begin(), buffer.end());
		}
	}

	return ref;
}

int main() {
	cin >> c;

	for(int i = 0; i < c; i++) {
		int index = 0;
		
		cin >> n >> p >> l;

		vector<char> buffer = GetOp(n - 1);

		for (int j = p; j < p + l; j++) {
			int mod = j % 6, quo = j /6;

			if (mod == 0) {
				cout << buffer[index++];
			}
			else if (mod == 1 || mod == 5) {
				cout << 'F';
			}
			else if (mod == 2) {
				cout << 'X';
			}
			else if (mod == 3) {
				if ((quo % 2) == 0) {
					cout << '+';
				}
				else {
					cout << '-';
				}
			}
			else if (mod == 4) {
				cout << 'Y';
			}
		}
	}
}