#include <stdio.h>
#include <stdlib.h>

typedef struct treenode{
    int data;
    struct treenode* left;
    struct treenode* right;
}Treenode;

Treenode* createnode(int data){
    Treenode* newnode = (Treenode*)malloc(sizeof(Treenode));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void makeLeftsubtree(Treenode* main,Treenode* sub){
    if(main->left==NULL)
        free(main->left);
    main->left = sub;
}

void makerightsubtree(Treenode* main,Treenode* sub){
    if(main->right==NULL)
        free(main->right);
    main->right=sub;
}

void preoreder_traverse(Treenode* root){
    if(root!=NULL){
        preoreder_traverse(root->left);
        preoreder_traverse(root->right);
        printf("%d ",root->data);
    }
}

void f1(){
    Treenode* root = createnode(4);
    Treenode* n1 = createnode(2);
    Treenode* n2 = createnode(1);
    Treenode* n3 = createnode(3);
    Treenode* n4 = createnode(5);
    Treenode* n5 = createnode(6);

    makeLeftsubtree(root,n1);
    makeLeftsubtree(n1,n2);
    makerightsubtree(n1,n3);
    makerightsubtree(root,n4);
    makeLeftsubtree(n4,n5);
    preoreder_traverse(root);
}

int main(void){
    f1();
}

