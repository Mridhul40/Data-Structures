////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementation of Trie Data Structure - contains a string as key and an integer as its corresponding value.
//functions implemented: make_trie (), insert (), delete (), search ()
//search () returns the value of the key if key exists, 0 otherwise
//Currently Under Construction
//Issue: The insert () function causes segmentation fault, needs debugging.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ALPHABET_NULL 27

const int A_ASCII = 97;
typedef struct node {
	char letter;
	int value;
	struct node *children [ALPHABET_NULL];
} node;

node* make_trie (void) {
	return (malloc (sizeof (node)));
}
void insert (node *root, char *key, int value, int first) {
	if (root->children [ ((int) (key [0])) - A_ASCII ] == NULL) {
		root->children [ ((int) (key [0])) - A_ASCII ] = malloc (sizeof (node));
		char fill;
		if (first < strlen (key)) {
			fill = key [first];
		}
		else {
			fill = '\0';
			root->children [ ((int) (key [0])) - A_ASCII ]->value = value;
		}
		root->children [ ((int) (key [0])) - A_ASCII ]->letter = fill;
	}
	insert (root->children [ ((int) (key [0])) - A_ASCII ], key, value, first + 1); 
}

int search (node *root, char *key) {
}

//SAMPLE CALLS TO TEST FUNCTIONALITY
int main (int argc, char *argv []) {
	node *t = make_trie ();
	char *strings [] = {"hello", "amy", "anna", "annabeth", "unbrella", "zoo key"};
	char *searchTerms [] = {"annabeth", "zoo keyyyyy", "amy", "hola"};

	for (int i = 0; i < 6; i++) {
		insert (t, strings [i], i, 0);
	}
	for (int i = 0; i < 4; i++) {
//		int value = search (t, searchTerms);
//		if (value) { printf ("%s exists with value %d\n", searchTerms [i], value); }
//		else { printf ("%s doesn't exist\n", searchTerms [i]); }
	}

	return (0);
}
