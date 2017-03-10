#include<stdio.h>

typedef struct _node {
	int value;
	struct _node *next;
}node;

void insert(int, node**);

int main() {
	int input = 0, i;
	node * head = NULL;
	
	scanf_s("%d", &input);

	for (i = 1; i <= input / 2; i++) {
		if (input % i == 0) {
			insert(i, &head);
			insert(input / i, &head);
		}
	}

	while (head->next != NULL) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");

	return 0;
}

void insert(int value, node **head) {
	node* current = NULL;
	node* previous = NULL;
	node* newNode = (node*)malloc(sizeof(node));
	newNode->value = value;
	newNode->next = NULL;

	if (*head == NULL) {
		*head = newNode;
		return;
	}

	current = *head;

	while (current->next != NULL) {
		if (current->value > newNode->value) {
			if (previous == NULL) {
				newNode->next = current;
				*head = newNode;
				return;
			}

			previous->next = newNode;
			newNode->next = current;
			return;
		}
		previous = current;
		current = current->next;
	}

	current->next = newNode;
}
