#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, V;

void dfs(int index, vector<int> edge[], vector<bool> &visited) {
	if (visited[index])
		return;

	visited[index] = true;
	cout << index + 1 << " ";

	for (int i = 0; i < edge[index].size(); i++) {
		dfs(edge[index][i], edge, visited);
	}
}

void bfs(int index, vector<int> edge[], vector<bool> &visited) {
	deque<int> q;

	q.push_back(index);
	visited[index] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop_front();

		cout << node + 1 << " ";

		for (int i = 0; i < edge[node].size(); i++) {
			if (visited[edge[node][i]])
				continue;

			q.push_back(edge[node][i]);
			visited[edge[node][i]] = true;
		}
	}
}

int main() {
	vector<int> edge[1000];

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int origin, dest;
		cin >> origin >> dest;

		edge[origin - 1].push_back(dest - 1);
		edge[dest - 1].push_back(origin - 1);
	}

	for(int i = 0; i < N; i++)
		sort(edge[i].begin(), edge[i].end());

	vector<bool> visited(N, false);
	dfs(V - 1, edge, visited);
	cout << endl;
	
	visited = vector<bool>(N, false);
	bfs(V - 1, edge, visited);

	return 0;
}