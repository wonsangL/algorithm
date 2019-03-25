#include<iostream>
#include<string>
#include<utility>
#include<math.h>

using namespace std;

string input[4];
typedef pair<int, int> p;
p cursor[4];

void rotate(int index, int dir) {
	if (cursor[index].first + dir < 0)
		cursor[index].first = 7;
	else if (cursor[index].first + dir > 7)
		cursor[index].first = 0;
	else
		cursor[index].first += dir;

	cursor[index].second = (cursor[index].first + 4) % 8;
}

void solution(int cur_index, int pre_index, int dir) {
	if (cur_index - 1 >= 0 && cur_index - 1 != pre_index) {
		if (input[cur_index][cursor[cur_index].first] != input[cur_index - 1][cursor[cur_index - 1].second])
			solution(cur_index - 1, cur_index, dir * -1);
	}
	
	if (cur_index + 1 < 4 && cur_index + 1 != pre_index) {
		if (input[cur_index][cursor[cur_index].second] != input[cur_index + 1][cursor[cur_index + 1].first])
			solution(cur_index + 1, cur_index, dir * -1);
	}

	rotate(cur_index, -1 * dir);
}


int main() {
	int k, result = 0;

	for (int i = 0; i < 4; i++) {
		cin >> input[i];
		cursor[i] = make_pair(6, 2);
	}

	cin >> k;

	for (int i = 0; i < k; i++) {
		int index, dir;
		cin >> index >> dir;
		solution(index - 1, -2, dir);
	}

	for (int i = 0; i < 4; i++) {
		int index = (cursor[i].first + 2) % 8;
		if (input[i][index] == '1') {
			result += pow(2, i);
		}
	}

	cout << result << endl;
}