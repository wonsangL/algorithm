#include<iostream>

using namespace std;

int T[44];

bool is_tri_num(int index, int count, int rest) {
	rest -= T[index];
	count++;

	if (count > 3)
		return false;
	else if (count == 3) {
		if (rest == 0)
			return true;
	}
	else {
		for (int i = index; i < 44; i++) {
			if (is_tri_num(i, count, rest))
				return true;
		}
	}

	return false;
}

int main() {
	int K, input;

	cin >> K;

	for (int i = 0; i < 44; i++) 
		T[i] = (i + 1) * (i + 2) / 2;

	for (int i = 0; i < K; i++) {
		bool flag = false;

		cin >> input;
		
		for (int i = 0; i < 44; i++) {
			if (is_tri_num(i, 0, input)) {
				flag = true;
				break;
			}
		}

		cout << ( flag ? 1 : 0 ) << endl;
	}
}