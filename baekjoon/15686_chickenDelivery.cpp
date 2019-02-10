#include<iostream>
#include<vector>
#include<math.h>
#include<utility>

using namespace std;

int N, M;

vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<vector<int>> dist;

int getDistance(pair<int, int> A, pair<int, int> B) {
	return abs(A.first - B.first) + abs(A.second - B.second);
}

int findMinDistance(vector<int> &index, int count, int cursor) {
	index.push_back(cursor);
	int answer = 100000;
	
	if (count == 1) {
		int result = 0;

		for (int i = 0; i < home.size(); i++) {
			int min = 100;
			for (int j : index) {
				if (min > dist[i][j])
					min = dist[i][j];
			}
			result += min;
		}

		index.pop_back();
		return result;
	}

	for (int i = cursor + 1; i < chicken.size(); i++) {
		int candidate = findMinDistance(index, count - 1, i);

		if (answer > candidate)
			answer = candidate;
	}

	index.pop_back();
	return answer;
}

int main() {
	cin >> N >> M;
	int result = 100000;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int flag;

			cin >> flag;

			if (flag == 1)
				home.push_back(make_pair(i, j));
			else if (flag == 2)
				chicken.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < home.size(); i++) {
		vector<int> row;
		for (int j = 0; j < chicken.size(); j++) {
			row.push_back(getDistance(home[i], chicken[j]));
		}
		dist.push_back(row);
	}

	vector<int> index;

	for (int i = 0; i < chicken.size(); i++) {
		int buffer = findMinDistance(index, M, i);

		if (result > buffer)
			result = buffer;
	}
	
	cout << result << endl;
}