#include<iostream>
#include<vector>

using namespace std;

int main() {
	int T, N, M;
	
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		vector<int> printQueue(N);
		vector<bool> printed(N, false);
		int max = 0, result = 1, cursor = 0;

		for (int j = 0; j < N; j++) {
			cin >> printQueue[j];

			if (printQueue[j] > max)
				max = printQueue[j];
		}

		while (true) {
			if (cursor >= N)
				cursor = 0;

			if (printQueue[cursor] == max && !printed[cursor]) {
				if (cursor == M) {
					cout << result << endl;
					break;
				}
		
				printed[cursor] = true;
				result++;
				cursor++;
				max = 0; 

				for (int k = 0; k < N; k++) {
					if (printQueue[k] > max && !printed[k])
						max = printQueue[k];
				}
			}
			else
				cursor++;
		}
	}

}
