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

void swapNode(Node* node1,Node* node2){
    int temp;
    temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void bubble_sort(List* plist){
    Node* cur = plist->head;
    int size = plist->size;
    for(int i=0;i<size;i++){
        for(int j=0;j<(size-i)-1;j++){
            if(cur->next==NULL)
                break;
            if(cur->data > cur->next->data)
                swapNode(cur,cur->next);
            cur = cur->next;
        }
        cur = plist->head;
    }
}

List* create_list(){
    List* newList = (List*)malloc(sizeof(List));
    newList->head =NULL;
    newList->tail = NULL;
    newList->size = 0;
    return newList;
}

void insert_last(List* plist,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next=NULL;
    if(plist->head==NULL)
        plist->head = newNode;
    else
        plist->tail->next = newNode;
    plist->tail=newNode;
    plist->size++;
}

void print_list(List* plist){
    Node* cur = plist->head;
    while(cur!=NULL){
        printf("%d ",cur->data);
        cur=cur->next;
    }
}

void set_find(List* list1,List* list2,List* list3){
    Node* a = list1->head;
    Node* b = list2->head;

    while(a&&b){
        if(a->data==b->data){
            insert_last(list3,a->data);
            a=a->next;
            b=b->next;
        }
        else if(a->data<b->data)
            a=a->next;
        else
            b=b->next;
    }
}
void f1(){
    FILE* fp = fopen("in.txt","r");
    FILE* fp1 = fopen("in2.txt","r");
    List* list1;
    List* list2;
    List* list3;
    int x;
    list1 = create_list();
    list2 = create_list();
    list3 = create_list();

    while(!(feof(fp))){
        fscanf(fp,"%d",&x);
        insert_last(list1,x);
        bubble_sort(list1);
    }

    while(!(feof(fp1))){
        fscanf(fp1,"%d",&x);
        insert_last(list2,x);
        bubble_sort(list2);
    }
    print_list(list1);
    printf("\n");
    print_list(list2);
    printf("\n");
    set_find(list1,list2,list3);
    printf("교집합: ");
    print_list(list3);
}

int main(void){
    f1();
}