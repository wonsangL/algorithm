#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int N;

int status[20][20];

vector<int> teamA;

int compare_team() {
	int scoreA = 0;
	int scoreB = 0;

	bool is_teamA[20];

	for (int i = 0; i < N; i++)
		is_teamA[i] = false;

	for (int i = 0; i < teamA.size(); i++)
		is_teamA[teamA[i]] = true;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (is_teamA[i] && is_teamA[j])
				scoreA += status[i][j];
			else if(!is_teamA[i] && !is_teamA[j])
				scoreB += status[i][j];
		}
	}

	return abs(scoreB - scoreA);
}

int create_team(int index, int size) {
	int result = 1000;

	if (teamA.size() == size) 
		return compare_team();

	teamA.push_back(index);

	for (int i = index + 1; i < N; i++) {
		int buffer = create_team(i, size);

		if (result > buffer)
			result = buffer;
	}

	teamA.pop_back();

	return result;
}

int main() {
	cin >> N;
	int result = 1000;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> status[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		int buffer = create_team(i, N / 2);
		if (result > buffer)
			result = buffer;
	}

	cout << result << endl;
	return 0;
}