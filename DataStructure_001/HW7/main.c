
#include "./Binary_Tree.h"


int main(int argc, char* argv[]) {
	printf("%s", argv[0]);
	BST_TREE* Tree = BST_Create(1);
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = 'd';
	char e = 'e';
	char f = 'f';
	char g = 'g';
	BST_Insert(Tree, &a);
	BST_Insert(Tree, &e);
	BST_Insert(Tree, &b);
	BST_Insert(Tree, &c);
	BST_Insert(Tree, &f);
	BST_Insert(Tree, &d);
	BST_Insert(Tree, &g);
	
	BST_Retrieve(Tree, &d);
	
	
	printf("Postorder : ");
	BST_Postorder(Tree);
	printf("\n"); 
	printf("Inorder : ");
	BST_Inorder(Tree); 
	printf("\n"); 
	printf("Preorder : ");
	BST_Preorder(Tree);
	printf("\n");

}