#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int calCost(vector<pair<int, int>> &table, vector<int> &cost, int index) {
	if (cost[index] != -1)
		return cost[index];

	if (index + table[index].first > table.size())
		return 0;

	int result = table[index].second;
	int max = 0;

	for (int i = index + table[index].first; i < table.size(); i++) {
		int buffer = calCost(table, cost, i);

		if (buffer > max)
			max = buffer;
	}

	return cost[index] = result + max;
}

int main() {
	int N, answer = 0;
	vector<pair<int, int>> table;

	cin >> N;

	vector<int> cost(N, -1);

	for (int i = 0; i < N; i++) {
		int time, pay;

		cin >> time >> pay;

		table.push_back(make_pair(time, pay));
	}
	
	for (int i = 0; i < table.size(); i++) {
		int buffer = calCost(table, cost, i);
		
		if (buffer > answer)
			answer = buffer;
	}

	cout << answer << endl;
}