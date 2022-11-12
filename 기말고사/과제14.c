#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct tnode{
    int data;
    struct tnode* left;
    struct tnode* right;
}Tnode;

typedef struct queue{
    Tnode* data[MAX_SIZE];
    int front;
    int rear;
}Queue;

void Qinit(Queue* q){
    q->front = 0;
    q->rear = 0;
}

int QisFull(Queue* q){
    return (q->rear+1) % MAX_SIZE == q->front;
}

int QisEmpty(Queue* q){
    return q->front == q->rear;
}

void enqueue(Queue* q,Tnode* node){
    if(QisFull(q)){
        printf("Q is Full!\n");
        exit(-1);
    }

    q->rear = (q->rear+1)%MAX_SIZE;
    q->data[q->rear] = node;
}

Tnode* dequeue(Queue* q){
    if(QisEmpty(q)){
        printf("Q is Empty\n");
        exit(-1);
    }

    q->front = (q->front+1)%MAX_SIZE;
    return q->data[q->front];
}


void level_order(Tnode* root){
    if(root==NULL)
        return;
    Queue q;
    Qinit(&q);
    enqueue(&q,root);
    while(!QisEmpty(&q)){
        root = dequeue(&q);
        printf("%d ",root->data);
        if(root->left)
            enqueue(&q,root->left);
        if(root->right)
            enqueue(&q,root->right);
    }
}


Tnode* create_node(int data){
    Tnode* newNode = (Tnode*)malloc(sizeof(Tnode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Tnode* insert_node(Tnode* root,int data){
    if(root==NULL)
        return create_node(data);
    if(data < root->data)
        root->left = insert_node(root->left,data);
    else if(data>root->data)
        root->right = insert_node(root->right,data);
    return root;
}

void f1(){
    FILE* fp = fopen("in.txt","r");
    Tnode* root = NULL;
    int x;
    while(!feof(fp)){
        fscanf(fp,"%d",&x);
        root = insert_node(root,x);
    }

    level_order(root);
}

int main(void){
    f1();
}
// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// typedef struct tnode{
//     int data;
//     struct tnode* left;
//     struct tnode* right;
// }Tnode;

// typedef struct queue{
//     Tnode* queue[MAX_SIZE];
//     int front,rear;
// }Queue;

// void Qinit(Queue* q){
//     q->front = 0;
//     q->rear = 0;
// }

// int QisEmpty(Queue* q){
//     return q->front == q->rear;
// }

// int QisFull(Queue* q){
//     return (q->rear+1) % MAX_SIZE == q->front;
// }

// void enqueue(Queue* q, Tnode* node){
//     if(QisFull(q)){
//         printf("Q IS FULL!\n");
//         return;
//     }   
//     q->rear = (q->rear+1) % MAX_SIZE;
//     q->queue[q->rear] = node;
// }

// Tnode* dequeue(Queue* q){
//     if(QisEmpty(q)){
//         printf("Q is Empty!");
//         exit(-1);
//     }

//     q->front = (q->front+1) % MAX_SIZE;
//     return q->queue[q->front];
// }

// Tnode* create_node(int data){
//     Tnode* newNode = (Tnode*)malloc(sizeof(Tnode));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// void levelorder_traverse(Tnode* root){
//     Queue q;
//     Qinit(&q);
//     if(root == NULL)
//         return;
//     enqueue(&q,root);
//     while(!QisEmpty(&q)){
//         root = dequeue(&q);
//         printf("%d ",root->data);
//         if(root->left)
//             enqueue(&q,root->left);
//         if(root->right)
//             enqueue(&q,root->right);
//     }
// }

// Tnode* insert_node(Tnode* root,int key){
//     if(root==NULL)
//         return create_node(key);
//     if(key < root->data)
//         root->left = insert_node(root->left, key);
//     else if(key > root->data)
//         root->right = insert_node(root->right, key);
//     return root;
// }

// void f1(){
//     FILE* fp = fopen("in.txt","r");
//     Tnode* root =NULL;
//     int x;
//     while(!feof(fp)){
//         fscanf(fp,"%d",&x);
//         root = insert_node(root,x);
//     }
//     levelorder_traverse(root);
//     fclose(fp);
// }

// int main(void){
//     f1();
// }


	