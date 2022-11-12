#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
	int data;
	struct tnode* left;
	struct tnode* right;
}Tnode;

Tnode* create_node(int data){
	Tnode* newNode = (Tnode*)malloc(sizeof(Tnode));
	newNode->data= data;
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
        if(root->left==NULL&&root->right==NULL)
		    printf("%d ",root->data);
		inorder_traverse(root->right);
	}
}

void f1(){
	int n,x;
	scanf("%d %d",&n,&x);
	Tnode* root = insert_node(n,x);
	inorder_traverse(root);
}
int main(void){
	f1();
}