#include<iostream>
#define SIZE 5
#define INF 999

using namespace std;

void PrintSolution(int dist[SIZE]) {
	cout << "result" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << dist[i] << endl;
	}
}

int MinIndex(int dist[SIZE], bool sptSet[SIZE]) {
	int min = INF;
	int minIndex;

	for (int i = 0; i < SIZE; i++) {
		if (!sptSet[i] && dist[i] <= min) {
			min = dist[i];
			minIndex = i;
		}
	}
	
	return minIndex;
}


void Dijkstra(int graph[SIZE][SIZE], int src) {
	int dist[SIZE];
	bool sptSet[SIZE];

	//�迭 �ʱ�ȭ
	for (int i = 0; i < SIZE; i++) {
		dist[i] = INF;
		sptSet[i] = false;
	}

	dist[src] = 0;


	//������ ���� �̹� weight ������ ������ ������ Ȯ���� �ʿ䰡 ����!
	for (int i = 0; i < SIZE - 1; i++) {
		int min = MinIndex(dist, sptSet);

		sptSet[min] = true;

		for (int j = 0; j < SIZE; j++) {
			if (!sptSet[j] && graph[min][j] && dist[j] > dist[min] + graph[min][j]) {
				dist[j] = dist[min] + graph[min][j];
			}
		}
	}

	PrintSolution(dist);
}


int main() {
	int graph[SIZE][SIZE] = { {0, 1, 0, 0, 2},
							{1, 0, 5, 0, 0},
							{0, 5, 0, 0, 3},
							{0, 0, 0, 0, 1},
							{2, 0, 3, 1, 0} };

	Dijkstra(graph, 0);

	return 0;
}