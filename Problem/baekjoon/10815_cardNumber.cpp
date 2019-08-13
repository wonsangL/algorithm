#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, M, buffer;

	scanf("%d", &N);

	vector<int> card(N);

	for (int i = 0; i < N; i++)
		scanf("%d", &card[i]);

	sort(card.begin(), card.end());

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		bool flag = false;
		int L = 0, R = N - 1;

		scanf("%d", &buffer);

		while (L <= R && !flag) {
			int mid = (L + R) / 2;

			if (buffer > card[mid])
				L = mid + 1;
			else if (buffer < card[mid])
				R = mid - 1;
			else
				flag = true;
		}

		if (flag)
			printf("%d ", 1);
		else
			printf("%d ", 0);
	}
	
}