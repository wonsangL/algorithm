#include<iostream>
#include<queue>

using namespace std;

int main() {
	int N, K, answer = 0;
	cin >> N >> K;

	queue<int> q;
	vector<bool> visited(100001, false);

	q.push(N);
	visited[N] = true;

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int current = q.front();
			q.pop();

			if (current == K) {
				cout << answer << endl;
				return 0;
			}

			if (current - 1 >= 0 && !visited[current - 1]) {
				visited[current - 1] = true;
				q.push(current - 1);
			}

			if (current + 1 <= 100000 && !visited[current + 1]) {
				visited[current + 1] = true;
				q.push(current + 1);
			}

			if (current * 2 <= 100000 && !visited[current * 2]) {
				visited[current * 2] = true;
				q.push(current * 2);
			}
		}

		answer++;
	}
}