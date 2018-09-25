#include<iostream>
#include<vector>

using namespace std;

int c, n, m, answer = 0;

void Count(vector<vector<int>> &pair, int index, bool check[]) {
	if (index == n) {
		for (int i = 0; i < n; i++) {
			if (check[i])
				return;
		}
		answer++;
		return;
	}
	
	if (pair[index].empty() || !check[index])
		return Count(pair, index + 1, check);

	for (int i = 0; i < pair[index].size(); i++) {
		if (check[pair[index][i]]) {
			check[index] = false;
			check[pair[index][i]] = false;
			
			Count(pair, index + 1, check);
			
			check[index] = true;
			check[pair[index][i]] = true;
		}
	}
}

int main() {
	cin >> c;

	for (int i = 0; i < c; i++) {
		answer = 0;
		cin >> n >> m;

		vector<vector<int>> pair(n);
		
		bool *check = new bool[n];

		for (int j = 0; j < n; j++) {
			check[j] = true;
		}
		
		for (int j = 0; j < m; j++) {
			int index, buffer;
			cin >> index >> buffer;

			pair[index].push_back(buffer); 
		}

		for (int j = 0; j < pair.size(); j++) {
			Count(pair, j, check);
		}

		delete[] check;
		cout << answer << endl;
	}
}