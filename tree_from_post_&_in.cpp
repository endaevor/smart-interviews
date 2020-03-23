/*
Let us see the process of constructing tree from in[] = {4, 8, 2, 5, 1, 6, 3, 7} and post[] = {8, 4, 5, 2, 6, 7, 3, 1}

1) We first find the last node in post[]. The last node is “1”, we know this value is root as root always appear in the end of postorder traversal.

2) We search “1” in in[] to find left and right subtrees of root. Everything on left of “1” in in[] is in left subtree and everything on right is in right subtree.

3) We recur the above process for following two.
….b) Recur for in[] = {6, 3, 7} and post[] = {6, 7, 3}
…….Make the created tree as right child of root.
….a) Recur for in[] = {4, 8, 2, 5} and post[] = {8, 4, 5, 2}.
…….Make the created tree as left child of root.

Below is the implementation of above idea. One important observation is, we recursively call for right subtree before left subtree as we decrease index of postorder index whenever we create a new node.
*/

/* C++ program to construct tree using inorder and 
postorder traversals */
#include <bits/stdc++.h> 

using namespace std; 

/* A binary tree node has data, pointer to left 
child and a pointer to right child */
struct Node { 
	int data; 
	Node *left, *right; 
}; 

// Utility function to create a new node 
Node* newNode(int data); 

/* Prototypes for utility functions */
int search(int arr[], int strt, int end, int value); 

/* Recursive function to construct binary of size n 
from Inorder traversal in[] and Postorder traversal 
post[]. Initial values of inStrt and inEnd should 
be 0 and n -1. The function doesn't do any error 
checking for cases where inorder and postorder 
do not form a tree */
Node* buildUtil(int in[], int post[], int inStrt, 
				int inEnd, int* pIndex) 
{ 
	// Base case 
	if (inStrt > inEnd) 
		return NULL; 

	/* Pick current node from Postorder traversal using 
	postIndex and decrement postIndex */
	Node* node = newNode(post[*pIndex]); 
	(*pIndex)--; 

	/* If this node has no children then return */
	if (inStrt == inEnd) 
		return node; 

	/* Else find the index of this node in Inorder 
	traversal */
	int iIndex = search(in, inStrt, inEnd, node->data); 

	/* Using index in Inorder traversal, construct left and 
	right subtress */
	node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex); 
	node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex); 

	return node; 
} 

// This function mainly initializes index of root 
// and calls buildUtil() 
Node* buildTree(int in[], int post[], int n) 
{ 
	int pIndex = n - 1; 
	return buildUtil(in, post, 0, n - 1, &pIndex); 
} 

/* Function to find index of value in arr[start...end] 
The function assumes that value is postsent in in[] */
int search(int arr[], int strt, int end, int value) 
{ 
	int i; 
	for (i = strt; i <= end; i++) { 
		if (arr[i] == value) 
			break; 
	} 
	return i; 
} 

/* Helper function that allocates a new node */
Node* newNode(int data) 
{ 
	Node* node = (Node*)malloc(sizeof(Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

/* This funtcion is here just to test */
void preOrder(Node* node) 
{ 
	if (node == NULL) 
		return; 
	printf("%d ", node->data); 
	preOrder(node->left); 
	preOrder(node->right); 
} 

// Driver code 
int main() 
{ 
	int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 }; 
	int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 }; 
	int n = sizeof(in) / sizeof(in[0]); 

	Node* root = buildTree(in, post, n); 

	cout << "Preorder of the constructed tree : \n"; 
	preOrder(root); 

	return 0; 
} 
