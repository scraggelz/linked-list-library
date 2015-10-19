#include <stdio.h>
#include "lists.h"

int main()
{
	struct list* l = makelist(0);
	addnode(l, 1);	
	addnode(l,7);
	addnode(l,9);
	printlist(l);
	printf("\n");
	printback(l->tail);
	return 0;
}
