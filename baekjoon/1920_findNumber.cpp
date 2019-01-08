#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector<int> A;

int solution(int m) {
	int L = 0, R = A.size() - 1;

	while (L <= R) {
		int mid = (L + R) / 2;

		if (m > A[mid]) 
			L = mid + 1;
		else if (m < A[mid]) 
			R = mid - 1;
		else
			return 1;
	}

	return 0;
}

int main() {
	int N, M, buffer;
	int max = 0, min = 100000;
	unordered_map<int, bool> visited;

	scanf("%d", &N);
	A = vector<int>(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		
		if (A[i] > max)
			max = A[i];

		if (A[i] < min)
			min = A[i];
	}

	scanf("%d", &M);

	sort(A.begin(), A.end());

	for (int i = 0; i < M; i++) {
		scanf("%d", &buffer);

		if (buffer > max || buffer < min) {
			printf("%d\n", 0);
			continue;
		}

		if (visited.find(buffer) != visited.end()) {
			printf("%d\n", 1);
			continue;
		}

		visited[buffer] = true;		
		printf("%d\n", solution(buffer));
	}
}