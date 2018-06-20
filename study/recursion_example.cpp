#include<iostream>
#include<vector>

using namespace std;

void recursion(int n, int count, vector<int> list) {
	if (count == 0) {
		for (vector<int>::iterator it = list.begin(); it != list.end(); it++) {
			cout << it << endl;
		}
	}
}

int main() {

}