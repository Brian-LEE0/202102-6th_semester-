#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compare(void* argu1, void* argu2);



typedef struct Node {
	void* dataPtr;
	struct Node* left, * right;
}NODE;

typedef struct {
	int count;
	int (*compare)(void* argu1, void* argu2);
	NODE* root;
}BST_TREE;

BST_TREE* BST_Create(int c)
{
	BST_TREE* tree = NULL;
	tree = (BST_TREE*)malloc(sizeof(BST_TREE));
	if (tree) {
		tree->root = NULL;
		tree->count = 0;
		tree->compare = compare;
	}
	return tree;
} // BST_Create

NODE* SearchBST(NODE* root, char key)
{
	if (!root)
		return NULL;
	if (key < *(char*)(root->dataPtr))
		return SearchBST(root->left, key);
	else if (key > *(char*)(root->dataPtr))
		return SearchBST(root->right, key);
	else
		return root;
}
NODE* _insert(BST_TREE* tree, NODE* root, NODE* newPtr, int code)
{
	printf("case : %c code : %d\n", *(char*)(newPtr->dataPtr), code);
	code++; // empty node code;
	char temp[20], bin[20];
	int r, i = 0;
	while (1) {
		r = code % 2;
		code /= 2;
		temp[i++] = '0' + r;
		if (code <= 0) break;
	}// DEC to BIN

	for (int j = --i; j >= 0; j--) {
		bin[i - j] = temp[j];
		printf("bin : %c\n", bin[i - j]);
	}// reverse str;

	printf(" i : %d", i);
	for (int j = i-1; j >= 0; j--) {
		if (j == 0) {
			if (bin[i] == '0') {
				root->left = newPtr;
				printf("%p good 3\n", root->left);
			}
			else
			{
				root->right = newPtr;
				printf("%p good 4\n", root->right);

			}
			return newPtr;
		}
		if (bin[i - j] == '0') {
			printf("%p good 1\n", root->left);
			root = root->left;
		}
		else
		{
			printf("%p good 2\n", root->right);
			root = root->right;

		}
	}
} // _insert

bool BST_Insert(BST_TREE* tree, void* dataPtr)
{
	NODE* newPtr = NULL;
	// given data, allocate a new node
	newPtr = (NODE*)malloc(sizeof(NODE));
	if (!newPtr) {
		return false;
	}
	newPtr->right = NULL;
	newPtr->left = NULL;
	newPtr->dataPtr = dataPtr;
	// insert the node into BST
	if (tree->count == 0)
		tree->root = newPtr;
	else
		_insert(tree, tree->root, newPtr, tree->count);
	(tree->count)++;

	return true;
} // BST_Insert

void* _retrieve(BST_TREE* tree, void* dataPtr, NODE* root)
{
	if (root) {
		if (tree->compare(dataPtr, root->dataPtr) < 0)
			return _retrieve(tree, dataPtr, root->left);
		else if (tree->compare(dataPtr, root->dataPtr) > 0)
			return _retrieve(tree, dataPtr, root->right);
		else // Found equal key
			return root->dataPtr;
	} // if root
	else
		return NULL; // Data not in tree
} // _retrieve

void* BST_Retrieve(BST_TREE* tree, void* keyPtr)
{
	if (tree->root)
		return _retrieve(tree, keyPtr, tree->root);
	else
		return NULL;
} // BST_Retrieve

void printCha(void* stuPtr)
{
	char str = *(char*)stuPtr;
	printf("%c", str);
}
void _Postorder(NODE* root)
{
	if (root == NULL)
		return;
	_Postorder(root->left);
	_Postorder(root->right);
	printCha(root->dataPtr);
}

void _Preorder(NODE* root)
{
	if (root == NULL)
		return;
	printCha(root->dataPtr);
	_Preorder(root->left);
	_Preorder(root->right);
}

void _Inorder(NODE* root)
{
	if (root == NULL)
		return;
	_Inorder(root->left);
	printCha(root->dataPtr);
	_Inorder(root->right);

}

void BST_Postorder(BST_TREE* tree) {
	_Postorder(tree->root);
	return;
}

void BST_Preorder(BST_TREE* tree) {
	_Preorder(tree->root);
	return;
}

void BST_Inorder(BST_TREE* tree) {
	_Inorder(tree->root);
	return;
}



//void breadthFirst(NODE* root)
//
//void LevelOrder(TreeNode* root) {
//	Queue* queue = NULL;
//	if (root == NULL)
//		return;
//	queue = CreateQueue(��);
//	while (root) {
//		Process(root
//			->data);
//		if (root->left)
//			Enqueue(queue, root->left);
//		if (root->right)
//			Enqueue(queue, root->right);
//		if (!IsEmptyQueue(queue))
//			root = Dequeue(queue);
//		else
//			root = NULL;
//	}
//	DestroyQueue(queue);
//}


int compare(void* argu1, void* argu2)
{
	printf("%c %c\n", *(char*)argu1, *(char*)argu2);
	return *(char*)argu1 - *(char*)argu2;
}
