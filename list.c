// A singly linked list of integers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

static List strToList(char *s);
static char *myStrdup(char *s);
static Node sortedInsert(Node head, int val);

List newList(void) {
	List l = malloc(sizeof(*l));
	if (l == NULL) {
		fprintf(stderr, "couldn't allocate list\n");
		exit(EXIT_FAILURE);
	}
	l->head = NULL;
	return l;
}

List readList(void) {
	char buf[MAX_LINE_LEN + 2] = {0};
	fgets(buf, MAX_LINE_LEN + 2, stdin);
	return strToList(buf);
}

static List strToList(char *s) {
	char *copy = myStrdup(s);
	Node head = NULL;
	Node curr = NULL;
	char *token = strtok(copy, " \n\t");
	while (token != NULL) {
		Node n = newNode(atoi(token));
		if (head == NULL) {
			head = n;
		} else {
			curr->next = n;
		}
		curr = n;
		token = strtok(NULL, " \n\t");
	}
	free(copy);
	List l = newList();
	l->head = head;
	return l;
}

static char *myStrdup(char *s) {
	char *copy = malloc((strlen(s) + 1) * sizeof(char));
	strcpy(copy, s);
	return copy;
}

Node newNode(int value) {
	Node n = malloc(sizeof(*n));
	if (n == NULL) {
		fprintf(stderr, "couldn't allocate node\n");
		exit(EXIT_FAILURE);
	}
	n->value = value;
	n->next = NULL;
	return n;
}

void freeList(List l) {
	Node curr = l->head;
	while (curr != NULL) {
		Node temp = curr;
		curr = curr->next;
		free(temp);
	}
	free(l);
}

void printList(List l) {
	Node curr = l->head;
	while (curr != NULL) {
		printf("[%d] -> ", curr->value);
		curr = curr->next;
	}
	printf("X\n");
}

void printListSet(List l) {
	printf("{");
	for (Node curr = l->head; curr != NULL; curr = curr->next) {
		printf("%d", curr->value);
		if (curr->next != NULL) {
			printf(", ");
		}
	}
	printf("}\n");
}

List listSortedCopy(List l) {
	List copy = newList();
	for (Node curr = l->head; curr != NULL; curr = curr->next) {
		copy->head = sortedInsert(copy->head, curr->value);
	}
	return copy;
}

static Node sortedInsert(Node head, int val) {
	if (head == NULL || val <= head->value) {
		Node n = newNode(val);
		n->next = head;
		return n;
	} else {
		head->next = sortedInsert(head->next, val);
		return head;
	}
}

