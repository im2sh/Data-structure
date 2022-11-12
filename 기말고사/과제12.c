#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
	int data;
	struct tnode* left;
	struct tnode* right;
}Tnode;

Tnode* create_node(int data){
	Tnode* newNode = (Tnode*)malloc(sizeof(Tnode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Tnode* insert_node(int n,int x){
	Tnode* root = create_node(n);
	if(n<10){
		if(n*x<10)
			root->left = insert_node(n*x,x);
		if(n+x<10)
			root->right = insert_node(n+x,x);
	}
	return root;
}

void inorder_traverse(Tnode* root){
	if(root!=NULL){
		inorder_traverse(root->left);
		printf("%d ",root->data);
		inorder_traverse(root->right);
	}
}

int main(void){
	int n,x;
	scanf("%d %d",&n,&x);
	Tnode* root = insert_node(n,x);
	inorder_traverse(root);
}


// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #include <stdlib.h>


// typedef struct treenode {
// 	int data;
// 	struct treenode* left;
// 	struct treenode* right;
// }Tnode;

// Tnode* create_node(int data) {
// 	Tnode* newNode = (Tnode*)malloc(sizeof(Tnode));
// 	newNode->data = data;
// 	newNode->left = NULL;
// 	newNode->right = NULL;
// 	return newNode;
// }

// Tnode* insert_node(int n,int x) {
// 	Tnode* root = create_node(n);
    
// 	if (n<10)
// 	{
//         if(n*x<10)
// 		    root->left = insert_node(n * x, x);
//         if(n+x<10)
// 		    root->right = insert_node(n + x, x);
// 	}

//     return root;
// }


// void inorder_traverse(Tnode* root) {
// 	if (root != NULL) {
// 		inorder_traverse(root->left);
// 		printf("%d ", root->data);
// 		inorder_traverse(root->right);
// 	}
// }

// void f1() {
// 	int x, n;
// 	printf("n: ");
// 	scanf("%d", &n);
// 	printf("x: ");
// 	scanf("%d", &x);
// 	Tnode* root = NULL;

// 	root = insert_node(n, x);

// 	inorder_traverse(root);
// }

// int main(void) {
// 	f1();
// }