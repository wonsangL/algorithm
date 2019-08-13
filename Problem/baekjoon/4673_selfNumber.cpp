#include<iostream>

using namespace std;

void Generator(bool arr[], int key) {
	if (key > 10000)
		return;

	int buffer = key;

	while (key > 0) {
		buffer += key % 10;
		key /= 10;
	}

	if (!arr[buffer]) {
		arr[buffer] = true;
		Generator(arr, buffer);
	}
}

int main() {
	bool check[10001] = { false };
	
	for (int i = 1; i <= 10000; i++) {
		if(!check[i])
			Generator(check, i);
	}

	for (int i = 1; i <= 10000; i++) {
		if (!check[i])
			cout << i << endl;
	}

	return 0;
}