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

void swapNodedata(Node* node1,Node* node2){
    int temp;
    temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void bubble_sort(List* plist){
    Node* cur=plist->head;
    int size = plist->size;
    for(int i=0;i<size;i++){
        for(int j=0;j<(size-i)-1;j++){
            if(cur->next==NULL)
                break;
            if(cur->data<cur->next->data)
                swapNodedata(cur,cur->next);
            cur = cur->next;
        }
        cur = plist->head;
    }
}


List* create_list(){
    List* newList = (List*)malloc(sizeof(List));
    newList->head = NULL;
    newList->tail=NULL;
    newList->size=0;
    return newList;
}

void insert_head(List* plist,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = plist->head;
    if(plist->tail==NULL)
        plist->tail=newNode;
    plist->head=newNode;
    plist->size++;
    bubble_sort(plist);
}

void print_list(List* plist){
    Node* cur = plist->head;
    while(cur!=NULL){
        printf("%d ",cur->data);
        cur=cur->next;
    }
}

void free_list(List* plist){
    Node* cur = plist->head;
    Node* ptr;
    while(cur!=NULL){
        ptr =cur;
        cur = cur->next;
        free(ptr);
    }
}

int main(void){
    int x;
    List* list;
    list = create_list();
    while(1){
        scanf("%d",&x);
        if(x==-1)
            break;
        insert_head(list,x);
        print_list(list);
        printf("\n");

    }
    free_list(list);
    return 0;
}