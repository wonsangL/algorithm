#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int allClear = 0;

class Stage {
public:
	int index;
	double clear;
	double player;

	Stage(int index) : index(index), clear(0), player(0){}
};

bool compare(const Stage &a, const Stage &b) {
	double ratioA = a.player + allClear == 0 ? 0 : (a.player - a.clear) / (a.player + allClear);
	double ratioB = b.player + allClear == 0 ? 0 : (b.player - b.clear) / (b.player + allClear);

	if (ratioA == ratioB)
		return a.index < b.index;
	
	return ratioA > ratioB;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<Stage> state;

	for (int i = 0; i < N; i++)
		state.push_back(Stage(i + 1));

	for (int input : stages) {
		if (input == N + 1) {
			allClear++;
			continue;
		}

		for (int i = 0; i < input; i++) {
			state[i].player++;

			if (i != input - 1)
				state[i].clear++;
		}
	}

	sort(state.begin(), state.end(), compare);

	for (Stage stage : state) {
		answer.push_back(stage.index);
	}

	return answer;
}
