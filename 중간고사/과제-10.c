#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    float coef;
    int expon;
    struct node* next;
}Node;

typedef struct list{
    Node* head;
    Node* tail;
    int size;
}List;

char compare(int num1,int num2){
    if(num1>num2)
        return '>';
    else if(num1<num2)
        return '<';
    else
        return '=';
}


List* create_list(){
    List* new_list = (List*)malloc(sizeof(List));
    new_list->head=NULL;
    new_list->tail=NULL;
    new_list->size=0;
    return new_list;
}

void insert_last(List* plist,float coef,int expon){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->expon=expon;
    newNode->next = NULL;

    if(plist->head==NULL)
        plist->head=newNode;
    else
        plist->tail->next=newNode;
    plist->tail=newNode;
    plist->size++;
}

void poly_add(List* list1,List* list2,List* list3){
    Node* a =list1->head;
    Node* b =list2->head;
    double tempcoef;
    while(a&&b){
        switch(compare(a->expon,b->expon)){
            case '>':
                insert_last(list3,a->coef,a->expon);
                a = a->next;
                break;
            case '=':
                tempcoef = a->coef+b->coef;
                if(tempcoef)
                    insert_last(list3,tempcoef,a->expon);
                a = a->next;
                b = b->next;
                break;
            case '<':
                insert_last(list3,b->coef,b->expon);
                b=b->next;
                break;
        }
    }
    for(;a!=NULL;a=a->next)
        insert_last(list3,a->coef,a->expon);
    for(;b!=NULL;b=b->next)
        insert_last(list3,b->coef,b->expon);
}

void print_poly(List* plist){
    Node* cur = plist->head;
    while(cur!=NULL){
        printf("%.f %d ",cur->coef, cur->expon);
        cur = cur->next;
    }
}

void f1(){
    FILE* fp = fopen("a.txt","r");
    FILE* fp1 = fopen("b.txt","r");
    int a_num;
    int b_num;
    float x;
    int y;
    List* list1,*list2,*list3;
    list1 = create_list();
    list2 = create_list();
    list3 = create_list();
    fscanf(fp,"%d",&a_num);
    fscanf(fp1,"%d",&b_num);

    while(!(feof(fp))){
        fscanf(fp,"%f %d",&x,&y);
        insert_last(list1,x,y);
    }
    while(!(feof(fp1))){
        fscanf(fp1,"%f %d",&x,&y);
        insert_last(list2,x,y);
    }
    poly_add(list1,list2,list3);
    print_poly(list3);   
}

int main(void){
    f1();
}