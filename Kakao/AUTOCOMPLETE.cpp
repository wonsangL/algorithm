#include <string>
#include <vector>

using namespace std;

struct Node{
	string value = "";
	bool isLeaf = true;
	Node * parent = NULL;
	Node * child[27] = { NULL, };
};

typedef Node* NodePtr;

void Insert(NodePtr &root, string value) {
	NodePtr current = root;

	NodePtr newNode = new Node();
	newNode->value = value;

	int i = 0;
	
	while (!current->isLeaf) {
		while (current->value[i] == newNode->value[i]) {
			i++;
		}
		
		if (current->child[newNode->value[i] - 'a'] == NULL) {
			current->child[newNode->value[i] - 'a'] = newNode;
			return;
		}

		current = current->child[newNode->value[i] - 'a'];
	}

	int length = current->value.length() > newNode->value.length() ? current->value.length() : current->value.length();

	NodePtr secondNode = new Node();
	secondNode->value = current->value;
	secondNode->parent = current;

	for (int i = 0; i < length; i++) {
		if (current->value[i] != newNode->value[i]) {
			current->isLeaf = false;

			newNode->parent = current;
			current->child[newNode->value[i] - 'a'] = newNode;			
			current->child[secondNode->value[i] - 'a'] = secondNode;

			current->value = current->value.substr(0, i);
			return;
		}
	}

	if (current->value.length() > newNode->value.length()) {
		current->child[26] = newNode;
		current->child[secondNode->value[length] - 'a'] = secondNode;
	}
	else {
		current->child[26] = secondNode;
		current->child[newNode->value[length] - 'a'] = newNode;
	}
}


int solution(vector<string> words) {
	int answer = 0;
	Node rootNode;
	rootNode.isLeaf = false;
	rootNode.value = " ";

	NodePtr root = &rootNode;

	for (string word : words) {
		Insert(root, word);
	}

	return answer;
}

int main() {
	solution({ "go","gone","guild" });
	solution({ "abc","def","ghi","jklm" });
	solution({ "word","war","warrior","world" });
}