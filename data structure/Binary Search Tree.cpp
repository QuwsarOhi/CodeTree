// Basic Binary Search Tree Implementation

#include <bits/stdc++.h>
using namespace std;

struct node{
	int key;
	node *left, *right;		//less   greater
	node() {
		left = right = NULL;
	}
};

bool insert(int key, node *root) {		// Worst time complexity O(n)
	if(root->key == key)				// If key already exists, ignore the insert (return 0)
		return 0;
	if(key < root->key) {
		printf("left\n");
		if(root->left != NULL) {
			printf("recurse\n");
			return insert(key, root->left);
		}
		else {
			printf("left new\n");
			root->left = new node();
			root->left->key = key;
			return 1;
		}
	}
	else {
		printf("right\n");
		if(root->right != NULL) {
			printf("recurse\n");
			return insert(key, root->right);
		}
		else {
			printf("right new\n");
			root->right = new node();
			root->right->key = key;
			return 1;
		}
	}
	return 0;
}

bool search(int key, node *root) {		// Worst time complexity O(n)
	if(root->key == key)
		return 1;
	if(key < root->key) {
		printf("left_search\n");
		if(root->left != NULL)
			return search(key, root->left);
		else
			return 0;
	}
	else {
		printf("right_search\n");
		if(root->right != NULL)
			return search(key, root->right);
		else
			return 0;
	}
	return 0;
}

void del(node *root) {
	if(root->left != NULL)
		del(root->left);
	if(root->right != NULL)
		del(root->right);	
	delete root;
}
	
int main() {
	node *root = new node();
	root->key = 10;
	insert(20, root);
	printf("%d inserted\n", 20);
	insert(5, root);
	printf("%d inserted\n", 5);
	insert(4, root);
	printf("%d inserted\n", 4);
	if(search(5, root))
		printf("found!!\n");
	del(root);
	return 0;
}
