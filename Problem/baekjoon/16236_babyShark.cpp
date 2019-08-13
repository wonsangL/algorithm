#include<iostream>
#include<utility>
#include<queue>
#include<math.h>

using namespace std;

typedef pair<int, int> p;

int map[20][20];
int N;

int d_row[] = { 1, 0, -1, 0 };
int d_col[] = { 0, 1, 0, -1 };

class Shark {
public:
	p m_pos;
	int m_counter;
	int m_size;

	Shark() {}
	Shark(p pos) : m_pos(pos), m_counter(0), m_size(2) {}

	void eat_fish(p pos) {
		map[m_pos.first][m_pos.second] = 0;
		map[pos.first][pos.second] = 0;

		m_pos = pos;

		m_counter++;

		if (m_counter == m_size) {
			m_size++;
			m_counter = 0;
		}
	}
};

int get_distance(p a, p b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int find_fish(Shark &shark) {
	p result = { N, N };
	queue<p> q, buffer;
	int distance = -1;
	bool visited[20][20];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			visited[i][j] = false;
	}
	
	q.push(shark.m_pos);
	visited[shark.m_pos.first][shark.m_pos.second] = true;

	while (!q.empty()) {
		int size = q.size();
		distance++;
			
		for (int i = 0; i < size; i++) {
			p tmp = q.front();
			q.pop();

			if (map[tmp.first][tmp.second] != 0 && map[tmp.first][tmp.second] < shark.m_size) {
				buffer.push(tmp);
				continue;
			}

			for (int j = 0; j < 4; j++) {
				int row = tmp.first + d_row[j];
				int col = tmp.second + d_col[j];

				if (row >= 0 && row < N && col >= 0 && col < N) {
					if (!visited[row][col] && map[row][col] <= shark.m_size) {
						q.push(make_pair(row, col));
						visited[row][col] = true;
					}
				}
			}
		}

		if (!buffer.empty())
			break;
	}

	while (!buffer.empty()) {
		p tmp = buffer.front();
		buffer.pop();

		if (tmp.first < result.first) {
			result = tmp;
		}
		else if (tmp.first == result.first) {
			if (tmp.second < result.second)
				result = tmp;
		}
	}

	if (result.first != N) {
		shark.eat_fish(result);
		return distance;
	}

	return 0;
}

int main() {
	Shark shark;
	int result = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> map[i][j];

			if (map[i][j] == 9)
				shark = Shark(make_pair(i, j));
		}
	}

	while (true) {
		int buffer = find_fish(shark);

		if (buffer == 0)
			break;

		result += buffer;
	}

	cout << result << endl;
	return 0;
}