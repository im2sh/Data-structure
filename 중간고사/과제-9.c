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
	newNode->data=data;
	newNode->next=NULL;
	if(plist->head==NULL){
		plist->head=newNode;
	}
	else{
		plist->tail->next=newNode;
	}

	plist->tail=newNode;
	plist->size++;
}

void insert_head(List* plist,int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = plist->head;

	if(plist->tail==NULL)
		plist->tail=newNode;
	plist->head=newNode;

}

void print_list(List* plist){
	Node* cur = plist->head;
	int count=0;
	while(cur!=NULL){
		if(count==plist->size-1){
			printf("%d\n",cur->data);
			break;
		}
		printf("%d -> ",cur->data);
		cur = cur->next;
		count++;
	}
}

void free_list(List* plist){
	Node* cur = plist->head;
	Node* ptr;
	while(cur!=NULL){
		ptr =cur;
		cur=cur->next;
		free(ptr);
	}
}

int check_list(List* plist,int data){
	Node* cur = plist->head;
	int count = 0;
	while(cur!=NULL){
		if(cur->data==data)
			count++;
		cur=cur->next;
	}
	if(count>0)
		return 1;
	return 0;
}

void f1(){
	FILE* fp = fopen("in9_1_2.txt","r");
	List* list;
	list = create_list();
	int x;
	while(!(feof(fp))){
		fscanf(fp,"%d",&x);
		if(!(check_list(list,x)))
			insert_last(list,x);
	}
	print_list(list);
	//free_list(list);
	fclose(fp);
}

void f2(){
	FILE* fp = fopen("in9_2_2.txt","r");
	List* list;
	int x;
	list = create_list();
	while(!(feof(fp))){
		fscanf(fp,"%d",&x);
		insert_head(list,x);
	}
	print_list(list);
	free_list(list);
	fclose(fp);
}
int main(void){
	f1();
	printf("\n");
	f2();
}
