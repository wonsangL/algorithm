#include<iostream>
#include<fstream>

using namespace std;

long long buyStock(int, int, long long*);

int main() {
	int T, N;

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		long long *stock;
		long long result = 0;

		std::cin >> N;

		stock = new long long[N];

		for (int j = 0; j < N; j++) {
			std::cin >> stock[j];
		}

		result = buyStock(0, N, stock);

		std::cout << result << std::endl;
	}

	return 0;
}

long long buyStock(int start, int end, long long* stock) {
	int maxIndex = start;
	long long result = 0;

	if (end == start) {
		return result;
	}

	for (int i = start; i < end; i++) {
		if (stock[i] >= stock[maxIndex]) {
			maxIndex = i;
		}
	}

	result += stock[maxIndex] * (maxIndex - start);

	for (int i = start; i < maxIndex; i++) {
		result -= stock[i];
	}

	return result + buyStock(maxIndex + 1, end, stock);
}