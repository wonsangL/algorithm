#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main() {
	string N;
	int num[9] = { 0, };
	int setSum = 0;	

	cin >> N;
	
	for (int i = 0; i < N.length(); i++) {
		int index = N[i] - '0';
		
		if (index == 9)
			index -= 3;

		num[index]++;

		if (index == 6) {
			if (num[index] % 2 != 0) {
				if (num[index] / 2 + 1 > setSum)
					setSum = num[index] / 2 + 1;
			}
			else {
				if (num[index] / 2 > setSum)
					setSum = num[index] / 2;
			}		
		}
		else {
			if (num[index] > setSum)
				setSum = num[index];
		}	
	}

	cout << setSum << endl;
}