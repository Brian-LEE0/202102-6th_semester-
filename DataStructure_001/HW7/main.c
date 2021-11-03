#include "./Binary_Tree.h"

int main(int argc, char* argv[]) {
	BST_TREE* Tree = BST_Create(true);
	char input[100];
	printf("input a string : ");
	scanf(" %[^\n]s", input);
	printf("\n");
	int i = 0;
	while (input[i] != '\0') {
		BST_Insert(Tree, &(input[i]));
		i++;
	}
	
	printf("Pre-order : ");
	BST_Preorder(Tree);
	printf("\n\n");
	printf("In-order : ");
	BST_Inorder(Tree);
	printf("\n\n");
	printf("Post-order : ");
	BST_Postorder(Tree);
	printf("\n\n");
	printf("Breadth_First : ");
	BST_BreadthFirst(Tree);
	printf("\n\n");
	
	BST_Destroy(Tree);

}
