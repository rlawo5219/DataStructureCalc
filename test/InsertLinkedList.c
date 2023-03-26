#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "InsertLinkedList.h"

linkedList_h* createLinkedList() {
	linkedList_h* CL = (linkedList_h*)malloc(sizeof(linkedList_h));
	CL->head = NULL;
	return CL;
}

void printList(linkedList_h* CL) {
	listNode* p = CL->head;
	printf("CL = (");
	if (p == NULL) {
		printf(")\n"); return;
	}
	do {
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) printf(", ");
	} while (p != CL->head);
	printf(")\n");
}

void insertFirstNode(linkedList_h* CL, char* x) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	listNode* temp;
	strcpy(newNode->data, x);
	if (CL->head == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		temp = CL->head;
		while (temp->link != CL->head) {
			temp = temp->link;
		}
		newNode->link = temp->link;
		temp->link = newNode;
		CL->head = newNode;
	}
}

void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL->head == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void deleteNode(linkedList_h* CL, listNode* old) {
	listNode* pre;
	if (CL->head == NULL) return;
	if (CL->head->link == NULL) {
		free(CL->head);
		CL->head = NULL;
		return;
	}
	else if (old == NULL) return;
	else {
		pre = CL->head;
		while (pre->link != old) {
			pre = pre->link;
		}
		pre->link = old->link;
		if (old == CL->head) {
			CL->head = old->link;
		}
		free(old);
	}
}

listNode* searchNode(linkedList_h* CL, char* x) {
	listNode* temp = CL->head;
	if (temp->link == NULL) return NULL;
	do {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	} while (temp != CL->head);
	return NULL;
}