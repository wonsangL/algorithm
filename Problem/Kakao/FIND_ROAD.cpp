#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
	int index;
	int x;
	int y;
	Node *l_child;
	Node *r_child;

	Node(int index, int x, int y) : index(index), x(x), y(y) {
		this->l_child = NULL;
		this->r_child = NULL;
	}
};

bool compare(Node &a, Node &b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}

	return a.y > b.y;
}

class Bst {
private:
	Node *head;

	void inner_insert(Node **ptr, Node &new_node) {
		if (*ptr == NULL) {
			*ptr = &new_node;
			return;
		}

		if ((*ptr)->x < new_node.x) {
			inner_insert(&((*ptr)->r_child), new_node);
		}
		else {
			inner_insert(&((*ptr)->l_child), new_node);
		}
	}

	void inner_get_perorder(Node *ptr, vector<int> &result) {
		if (ptr == NULL) {
			return;
		}
		
		result.push_back(ptr->index);
		inner_get_perorder(ptr->l_child, result);
		inner_get_perorder(ptr->r_child, result);
	}

	void inner_get_postorder(Node *ptr, vector<int> &result) {
		if (ptr == NULL) {
			return;
		}
		
		inner_get_postorder(ptr->l_child, result);
		inner_get_postorder(ptr->r_child, result);
		result.push_back(ptr->index);
	}
public:
	Bst() {
		head = NULL;
	}

	void insert(Node &new_node) {
		inner_insert(&head, new_node);
	}

	vector<int> get_preorder() {
		vector<int> result;
		inner_get_perorder(head, result);
		return result;
	}

	vector<int> get_postorder() {
		vector<int> result;
		inner_get_postorder(head, result);
		return result;
	}
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	Bst tree;
	vector<Node> node;

	for (int i = 0; i < nodeinfo.size(); i++) {
		node.push_back(Node(i + 1, nodeinfo[i][0], nodeinfo[i][1]));
	}

	sort(node.begin(), node.end(), compare);

	for (int i = 0; i < node.size(); i++) {
		tree.insert(node[i]);
	}

	vector<vector<int>> answer;
	answer.push_back(tree.get_preorder());
	answer.push_back(tree.get_postorder());
	return answer;
}

int main() {
	vector<vector<int>> result = solution({ {5, 3},{11, 5},{13, 3},{3, 5},{6, 1},{1, 3},{8, 6},{7, 2},{2, 2} });

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}