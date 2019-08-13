#include<iostream>
#include<vector>
#include<queue>

#define INF 3000001

using namespace std;

typedef pair<int, int> p;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	priority_queue<p, vector<p>, greater<p>> pq;
	
	int V, E, K, u, v, w;

	cin >> V >> E >> K;

	vector<vector<p>> adj(V);
	vector<int> dist(V, INF);

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u - 1].push_back(make_pair(v - 1, w));
	}

	dist[K - 1] = 0;
	pq.push(make_pair(K - 1, 0));

	while (!pq.empty()) {
		int i = pq.top().first;
		int weight = pq.top().second;
		pq.pop();

		if (weight > dist[i])
			continue;

		for (p p : adj[i]) {
			if (weight + p.second < dist[p.first]) {
				pq.push(make_pair(p.first, weight + p.second));
				dist[p.first] = weight + p.second;
			}
		}	
	}

	for (int result : dist) {
		if (result == INF)
			cout << "INF\n";
		else
			cout << result << "\n";
	}

	return 0;
}