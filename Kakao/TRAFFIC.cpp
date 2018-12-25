#include<iostream>
#include <string>
#include <vector>
#include<cmath>

using namespace std;

typedef struct node {
	double startTime;
	double endTime;
}NODE;

bool compare(NODE* a, NODE* b) {
	return a->startTime < b->startTime;
}
	
vector<NODE*> nodes;

int GetCount(int index) {
	int result = 1;
	int preCount = 0, postCount = 0;

	for (int i = 0; i < nodes.size(); i++) {
		if (i == index)
			continue;

		if (nodes[index]->startTime - 0.999 < nodes[i]->endTime && nodes[index]->startTime > nodes[i]->startTime)
			preCount++;
		else if (nodes[index]->endTime <= nodes[i]->endTime && nodes[index]->endTime + 0.999 > nodes[i]->startTime)
			postCount++;
	}

	return result += postCount > preCount ? postCount : preCount;
}

int solution(vector<string> lines) {
	int answer = 0, max = 0;

	for (string line : lines) {
		NODE *newNode = new NODE();
		newNode->startTime = newNode->endTime = 0;

		line = line.substr(11);

		int find = line.find(" ");

		string S = line.substr(0, find);
		string T = line.substr(find + 1);

		for (int i = 2; i >= 0; i--) {
			find = S.find(":");

			if (find == -1)
				newNode->endTime += stod(S);
			else
				newNode->endTime += stod(S.substr(0, 2)) * pow(60, i);
			
			S = S.substr(3);
		}

		find = T.find("s");
		T = T.substr(0, find);

		newNode->startTime = newNode->endTime - stod(T);
		nodes.push_back(newNode);
	}

	for (int i = 0; i < nodes.size(); i++) {
		int buffer = GetCount(i);

		if (max < buffer)
			max = buffer;
	}
	
	return answer = max;
}
