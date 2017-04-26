#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n
{
	int val;
	struct n* left;
	struct n* right;
} node;

node* create_node( int val ) {
	printf ( "Adding val %d\n", val );
	node* tmp = malloc ( sizeof ( node ) );
	tmp->val = val;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}

void insert_node ( node* n, int val ) {
	if ( n == NULL ) {
		return;
	}
	if ( val > n->val ) {
		if (n->right != NULL) {
			insert_node (n->right, val);
		} else {
			n->right = create_node ( val );
		}
	} else {
		if (n->left != NULL) {
			insert_node (n->left, val);
		} else {
			n->left = create_node ( val );
		}
	}
	return;
}
	
node* add_node_to_tree ( node* n, int val ) {
	// If tree empty
	if ( n == NULL ) {
		return create_node ( val ); 
	} else {
		insert_node ( n, val );
	}
	return n;
}

void print_tree ( node* n ) {
	if ( n == NULL ) {
		return;
	}
	printf ( "%d, %u, left = %u, right = %u\n", n->val, (unsigned int) n, (unsigned int) n->left, (unsigned int) n->right);
	print_tree (n->left);
	print_tree (n->right);
	
	return;
}

void print_in_order ( node* n ) {
	if ( n == NULL ) {
		return;
	}
	print_in_order (n->left);
	printf ( "%d, ", n->val );
	print_in_order (n->right);
	
	return;
}

void print_pre_order ( node* n ) {
	if ( n == NULL ) {
		return;
	}
	printf ( "%d, ", n->val );
	print_pre_order (n->left);
	print_pre_order (n->right);
	
	return;
}

void print_post_order ( node* n ) {
	if ( n == NULL ) {
		return;
	}
	print_post_order (n->left);
	print_post_order (n->right);
	printf ( "%d, ", n->val );
	
	return;
}

void delete_tree ( node* n ) {
	if ( n == NULL ) {
		return;
	}
	delete_tree (n->left);
	delete_tree (n->right);

	printf ("Delete %d\n", n->val);
	free ( n );
	

	return;
}

int main()
{
	node* tree = NULL;

	FILE* fd = fopen ( "btree.txt", "r" );
	if ( fd == NULL ) {
		printf ("Expecting a file called btree.txt with integers, one on each line\n");
		exit(1);
	}

	int val;
	while ( fscanf ( fd, "%d\n", &val ) != EOF ) {
		tree = add_node_to_tree ( tree, val );
		print_tree ( tree );
	}
	fclose ( fd );
		
	printf ("Print in order:\n");
	print_in_order ( tree );
	printf ("\n");

	printf ("Print pre order:\n");
	print_pre_order ( tree );
	printf ("\n");

	printf ("Print post order:\n");
	print_post_order ( tree );
	printf ("\n");

	delete_tree ( tree );

	printf ("Done\n");
}


