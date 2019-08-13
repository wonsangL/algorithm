#include<iostream>
#include<utility>

using namespace std;

int N;

int num[11];
int op[4];

pair<int, int> calcurate_max(int index, int result) {
	int max = -1000000001, min = 1000000001;

	if (index + 1 == N)
		return make_pair(result, result);

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			int tmp;

			if (i == 0) {
				tmp = result + num[index + 1];
			}
			else if (i == 1) {
				tmp = result - num[index + 1];
			}
			else if (i == 2) {
				tmp = result * num[index + 1];
			}
			else {
				tmp = result / num[index + 1];
			}

			op[i]--;
			
			pair<int, int> buffer = calcurate_max(index + 1, tmp);
			
			op[i]++;

			if (buffer.first > max)
				max = buffer.first;

			if (buffer.second < min)
				min = buffer.second;
		}
	}

	return make_pair(max, min);
}
//int calcurate_min(int index, int result) {
//	int min = 1000000001;
//
//	if (index + 1 == N)
//		return result;
//
//	for (int i = 0; i < 4; i++) {
//		if (op[i] > 0) {
//			int temp;
//
//			if (i == 0) {
//				temp = result + num[index + 1];
//			}
//			else if (i == 1) {
//				temp = result - num[index + 1];
//			}
//			else if (i == 2) {
//				temp  = result * num[index + 1];
//			}
//			else {
//				temp = result / num[index + 1];
//			}
//
//			op[i]--;
//
//			int buffer = calcurate_max(index + 1, temp);
//
//			op[i]++;
//
//			if (buffer < min)
//				min = buffer;
//		}
//	}
//
//	return min;
//}


int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	cout << calcurate_max(0, num[0]).first << endl;;
	cout << calcurate_max(0, num[0]).second << endl;;
}