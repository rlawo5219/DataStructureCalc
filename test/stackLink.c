#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stackLink.h"

void initChar() {
	top1 = NULL;
}

void initDouble() {
	top2 = NULL;
}

int isStackEmptyChar() {
	if (top1 == NULL) return 1;
	else return 0;
}

int isStackEmptyDouble() {
	if (top2 == NULL) return 1;
	else return 0;
}

void pushChar(elementChar item) {
	stackNodeChar* temp = (stackNodeChar*)malloc(sizeof(stackNodeChar));

	temp->data = item;
	temp->link = top1;
	top1 = temp;
}

elementChar popChar() {
	elementChar item;
	stackNodeChar* old = top1;

	if (isStackEmptyChar()) {
		printf("\n\n Stack is NULL!\n");
		return;
	}
	else {
		item = old->data;
		top1 = old->link;
		free(old);
		return item;
	}
}

elementChar peekChar() {
	if (isStackEmptyChar()) {
		printf("\n\n Stack is NULL!\n");
		return;
	}
	else {
		return (top1->data);
	}
}

void peekAllS() {
	stackNodeChar* temp = top1;
	char items[100];
	int i = 0, j;
	if (isStackEmptyChar()) {
		printf("\n\n Stack is NULL!\n");
		return;
	}
	else {
		while (temp != NULL) {
			items[i] = temp->data;
			temp = temp->link;
			i++;
		}
		for (j = i - 1; j >= 0; j--) {
			printf("%c", items[j]);
		}
	}
}

void pushDouble(elementDouble item) {
	stackNodeDouble* temp = (stackNodeDouble*)malloc(sizeof(stackNodeDouble));

	temp->data = item;
	temp->link = top2;
	top2 = temp;
}

elementDouble popDouble() {
	elementDouble item;
	stackNodeDouble* old = top2;

	if (isStackEmptyDouble()) {
		printf("\n\n Stack is NULL!\n");
		return;
	}
	else {
		item = old->data;
		top2 = old->link;
		free(old);
		return item;
	}
}

void peekAllD() {
	stackNodeDouble* temp = top2;
	int i = 0, j;
	double items[100];
	if (isStackEmptyDouble()) {
		printf("\n\n Stack is NULL!\n");
		return;
	}
	else {
		while (temp != NULL) {
			items[i] = temp->data;
			temp = temp->link;
			i++;
		}
		for (j = i - 1; j >= 0; j--) {
			if ((int)items[j] - items[j] == 0) {
				printf(" %.0lf", items[j]);
			}
			else {
				printf(" %.2lf", floor(items[j]*100)/100);
			}
		}
	}
}