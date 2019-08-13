#include<iostream>
#include<vector>

#define INF 100000000

using namespace std;

typedef pair<int, int> intPair;

int main() {
	int N, M, A, B, C;
	bool flag = false;

	cin >> N >> M;

	vector<vector<intPair>> adj(N);
	vector<int> dist(N, INF);

	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		adj[A - 1].push_back(make_pair(B - 1, C));
	}

	dist[0] = 0;

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (intPair temp : adj[i]) {
				if (dist[i] != INF && dist[temp.first] > dist[i] + temp.second) {
					dist[temp.first] = dist[i] + temp.second;

					if (k == N - 1)
						flag = true;
				}
			}
		}
	}
	
	if (flag) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 1; i < N; i++) {
		cout << ((dist[i] == INF)? -1 : dist[i]) << endl;
	}
}
		