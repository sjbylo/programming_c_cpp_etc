#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int val;
	struct node* next;
} mynode;

mynode* create_node ( int val ) {
	mynode* tmp = malloc ( sizeof ( mynode ) );
	tmp->val = val;
	tmp->next = NULL;

	return tmp;
}

void catnode ( mynode* node, int val ) {
	if ( node == NULL )
		return;
	while ( node->next != NULL ) {
		node = node->next;
	}
//	mynode* tmp = malloc ( sizeof ( mynode ) );
//	tmp->val = val;
	node->next = create_node ( val );
}
	
void print_list ( mynode* n ) {
	while ( n != NULL ) {
		printf ( "%d, %u, next = %u\n", n->val, (unsigned int) n, (unsigned int) n->next);
		n = n->next;
	}
	printf ("Done\n");
	return;
}

int main()
{
	mynode n1;
	mynode n2;
	mynode n3;

	n1.val = 0;
	n2.val = 1;
	n3.val = 2;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;

	mynode* n = &n1;

	print_list( &n1 );

	catnode ( n, 10 );

	print_list( n );

	printf ("Done\n");
}


