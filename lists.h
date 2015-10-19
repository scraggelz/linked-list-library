#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

struct list
{
	struct node *head;
	struct node *tail;
};

struct node * newnode(int data)
{
	struct node *n = (struct node*)malloc(sizeof(struct node));
	n->data = data;
	n->prev = NULL;
	n->next = NULL;
	return n;
}

struct list * makelist(int data)
{
	struct list *l = (struct list*)malloc(sizeof(struct list)); 
	l->head = newnode(data);
	return l;
}
	
void addnode(struct list *l, int data)
{
	struct node *head = l->head;
	struct node *newNode = newnode(data);

	if(l->head==NULL)
	{
		l->head = newNode;
		return;
	}

	while(head->next)
		head = head->next;
	head->next = newNode;
	newNode->prev = head;
	l->tail = newNode;

}

void printlist(struct list *l)
{
	struct node *head = l->head;
	while(head)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

void printback(struct node *tail)
{
	while(tail)
	{
		printf("%d\n", tail->data);
		tail = tail->prev;
	}
}
