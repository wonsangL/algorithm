#include<iostream>
#include<vector>
#include<queue>

#define MAX 402

using namespace std;

int n, m, p, capacity[MAX][MAX], parent[MAX]; 	

bool bfs() {
	bool *visited = new bool[MAX];	
	fill(visited, visited + MAX, false);

	queue<int> q;
	q.push(0);
	visited[0] = true;
	parent[0] = -1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < MAX; i++) {
			if (!visited[i] && capacity[u][i] > 0) {
				parent[i] = u;
				q.push(i);
				visited[i] = true;
			}
		} 
	}

	return visited[MAX - 1];
}

int main() {
	int maxFlow = 0, u;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> p;

		for (int j = 0; j < p; j++) {
			int index;
			cin >> index;
			capacity[i][n + index] = 1;
		}
	}

	for (int j = 1; j <= n; j++) {
		capacity[0][j] = 1;
	}

	for (int j = n + 1; j <= n + m; j++) {
		capacity[j][MAX - 1] = 1;
	}	
	
	while (bfs()) {
		int flow = 2;

		for (int v = MAX - 1; v != 0; v = parent[v]) {
			u = parent[v];
			flow = min(flow, capacity[u][v]);
		}

		for (int v = MAX - 1; v != 0; v = parent[v]) {
			u = parent[v];
			capacity[u][v] -= flow;
			capacity[v][u] += flow;
		}

		maxFlow += flow;
	}

	cout << maxFlow << endl;
	return 0;
}