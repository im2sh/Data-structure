#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct list{
    Node* head;
    Node* tail;
    int size;
}List;

List* create_list(){
    List* newList = (List*)malloc(sizeof(List));
    newList->head=NULL;
    newList->tail=NULL;
    newList->size=0;
    return newList;
}

void insert_last(List* plist,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(plist->head==NULL){
        plist->head=newNode;
    }
    else{
        plist->tail->next=newNode;
    }
    plist->tail=newNode;
}

void print_list(List* plist){
    Node* cur=plist->head;
    while(cur!=NULL){
        printf("%d (%p)\n",cur->data,cur);
        cur = cur->next;
    }
}

void free_list(List* plist){
    Node* cur = plist->head;
    Node* ptr;
    while(cur!=NULL){
        ptr = cur;
        cur=cur->next;
        free(ptr);
    }
}

void f1(){
    List* list;
    list = create_list();
    int i;
    int x;
    scanf("%d",&x);
    for(i=0;i<x;i++){
        insert_last(list,i);
    }
    print_list(list);
    free_list(list);
}

int main(void){
    f1();
    return 0;
}