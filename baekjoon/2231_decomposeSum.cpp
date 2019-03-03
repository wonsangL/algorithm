//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main() {
//	int T, N, M, cursor = 0;
//	
//	cin >> T;
//
//	for (int i = 0; i < T; i++) {
//		cin >> N >> M;
//
//		vector<int> printQueue(N);
//		vector<bool> printed(N, false);
//		int max = 0, result = 1;
//
//		for (int j = 0; j < N; j++) {
//			cin >> printQueue[j];
//
//			if (printQueue[j] > max)
//				max = printQueue[j];
//		}
//
//		while (true) {
//			if (cursor >= N)
//				cursor = 0;
//
//			if (printQueue[cursor] == max && !printed[cursor]) {
//				if (cursor == M) {
//					cout << result << endl;
//					break;
//				}
//		
//				printed[cursor] = true;
//				result++;
//				cursor++;
//				max = 0; 
//
//				for (int k = 0; k < N; k++) {
//					if (printQueue[k] > max && !printed[k])
//						max = printQueue[k];
//				}
//			}
//			else
//				cursor++;
//		}
//	}
//
//}


#include<iostream>

using namespace std;

int main() {
	int N;

	cin >> N;

	for (int i = 1; i < N; i++) {
		int compare, digit;
		compare = digit = i;
		
		while (digit > 0) {
			compare += digit % 10;
			digit /= 10;
		}

		if (compare == N) {
			cout << i << endl;
			return 0;
		}
	}

	cout << 0 << endl;
}
