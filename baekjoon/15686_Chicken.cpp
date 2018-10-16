#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct House {
	int row;
	int col;

	House(int i, int j) : row(i), col(j) {}
};

struct Chicken {
	int row;
	int col;
	int counter = 0;
	int totalDist = 0;
	vector<int> dist;

	Chicken(int i, int j): row(i), col(j) {	}

	bool operator< (Chicken &compare) {
		if (compare.totalDist == this->totalDist) {
			return this->counter > compare.counter;
		}		
		return this->totalDist < compare.totalDist;
	}

	void SetInfo(vector<House> &house, vector<int> &minDist) {
		int temp;
		
		for (int i = 0; i < house.size(); i++) {
			temp = abs(this->row - house[i].row) + abs(this->col - house[i].col);
			dist.push_back(temp);
			totalDist += temp;

			if (temp < minDist[i])
				minDist[i] = temp;
		}
	}

	void SetCounter(vector<int> minDist) {
		for (int i = 0; i < minDist.size(); i++) {
			if (dist[i] == minDist[i])
				counter++;
		}
	}

	void SetChickenDist(vector<int> &minDist) {
		if (minDist.empty()) {
			for (int distance : dist) {
				minDist.push_back(distance);
			}
			return;
		}

		for (int i = 0; i < minDist.size(); i++) {
			if (dist[i] < minDist[i])
				minDist[i] = dist[i];
		}		
	}
};

int main() {
	vector<Chicken> chicken;
	vector<House> house;
	vector<int> chickenDist;

	int n, m, answer = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;

			if (input == 1) {
				house.push_back(House(i, j));
				chickenDist.push_back(100);
			}
				
			if (input == 2)
				chicken.push_back(Chicken(i, j));
		}
	}

	for (int i = 0; i < chicken.size(); i++) {
		chicken[i].SetInfo(house, chickenDist);
	}

	for (int i = 0; i < chicken.size(); i++) {
		chicken[i].SetCounter(chickenDist);
	}

	sort(chicken.begin(), chicken.end());
	chickenDist.clear();

	for (int i = 0; i < m; i++) {
		chicken[i].SetChickenDist(chickenDist);
	}

	for (int distance: chickenDist) {
		answer += distance;
	}

	cout << answer << endl;
}