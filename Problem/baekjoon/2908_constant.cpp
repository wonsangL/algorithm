#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
	string A, B;
	int newA = 0, newB = 0, unit = 0;

	cin >> A >> B;

	for (int i = 0; i < 3; i++) {
		newA += (A[i] - '0') * (int)pow(10, unit);
		newB += (B[i] - '0') * pow(10, unit++);
	}

	cout <<( newA > newB ? newA : newB) << endl;
}