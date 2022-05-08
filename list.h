// A singly linked list of integers

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024

typedef struct node *Node;
struct node {
	int value;
	Node next;
};

typedef struct list *List;
struct list {
	Node head;
};

/**
 * Creates an empty list
 */
List newList(void);

/**
 * Creates a new node containing the given value.
 */
Node newNode(int value);


List readList(void);

void freeList(List l);

void printList(List l);

/**
 * Prints a list in a set format. For example, the list 1 -> 2 -> 3 -> X
 * is printed as {1, 2, 3}.
 */
void printListSet(List l);

/**
 * Returns a sorted copy of the given list.
 */
List listSortedCopy(List l);

#endif

