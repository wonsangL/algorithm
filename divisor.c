#include<stdio.h>

typedef struct _node {
	int value;
	struct _node *next;
}node;

void insert(int, node**);

int main() {
	int input = 0, i = 1;
	node * head = NULL;
	
	scanf_s("%d", &input);

	while (input / i >= i) {
		if (input % i == 0) {
			if (input / i != i) {
				insert(i, &head);
				insert(input / i, &head);
			}
			else {
				insert(i, &head);
			}
		}	
		i++;
	}


	while (head != NULL) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");


	free(head);
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

	while (current != NULL) {
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

	previous->next = newNode;
}
