#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

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
    return (q->rear+1)%MAX_SIZE == q->front;
}

int QisEmpty(Queue* q){
    return q->front == q->rear;
}

void enqueue(Queue* q, Tnode* node){
    if(QisFull(q)){
        printf("Q is Full!\n");
        exit(-1);
    }

    q->rear = (q->rear+1) % MAX_SIZE;
    q->data[q->rear] = node;
}

Tnode* dequeue(Queue* q){
    if(QisEmpty(q)){
        printf("Q is Empty!\n");
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
    else if(data > root->data)
        root->right = insert_node(root->right,data);
    return root;
}

Tnode* search_node(Tnode* root,int key){
    if(root==NULL)
        return NULL;
    if(root->data == key)
        return root;
    else if(root->data < key)
        return search_node(root->left,key);
    else
        return search_node(root->right,key);
}

int check_tree(Tnode* root,int key){
    Tnode* check = search_node(root,key);
    if(check==NULL)
        return TRUE;
    else
        return FALSE;
}

void f1(){
    FILE* fp = fopen("in.txt","r");
    Tnode* root = NULL;
    Tnode* search;
    int check;
    int x;
    char word;
    while(!feof(fp)){
        fscanf(fp,"%c %d",&word, &x);
        switch(word){
            case 'A':
                printf("%c %d: ",word,x);
                check = check_tree(root,x);
                
                if(check==TRUE){
                    root = insert_node(root,x);
                    level_order(root);
                    printf("\n");
                    break;
                }

                else{
                    printf("%d cannot be inserted\n",x);
                    break;
                }
            case 'S':
                printf("%c %d: ",word,x);
                search = search_node(root,x);
                if(search==NULL)
                    printf("%d is not in T\n",x);
                else
                    printf("%d is in T\n", x);
                break;
        }

    }
}

int main(void){
    f1();
}


// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100
// #define TRUE 1
// #define FALSE 0

// typedef struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// }Tnode;

// typedef struct queue{
//     Tnode* queue[MAX_SIZE];
//     int front;
//     int rear; 
// }Queue;

// void Qinit(Queue* q){
//     q->front = 0;
//     q->rear = 0;
// }

// int QisEmpty(Queue* q){
//     return q->front==q->rear;
// }

// int QisFull(Queue* q){
//     return (q->front+1) % MAX_SIZE == q->rear;
// }

// void enqueue(Queue* q, Tnode* n){
//     if(QisFull(q)){
//         printf("Q is Full\n");
//         return;
//     }
//     q->rear = (q->rear+1) % MAX_SIZE;
//     q->queue[q->rear] = n;
// }

// Tnode* dequeue(Queue* q){
//     if(QisEmpty(q)){
//         printf("Q is Empty\n");
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

// Tnode* insert_node(Tnode* root,int data){
//     if(root==NULL)
//         return create_node(data);
//     if(data<root->data)
//         root->left = insert_node(root->left,data);
//     else if(data>root->data)
//         root->right = insert_node(root->right,data);
//     return root;
// }

// // int search_node(Tnode* root,int key){
// //     if(root->data == key)
// //         return TRUE;
// //     if(key < root->data)
// //         search_node(root->left,key);
// //     else
// //         search_node(root->right,key);
    
// //     return FALSE;
// // }

// Tnode* search_node(Tnode* root, int key){
//     if(root==NULL)
//         return NULL;
//     if(root->data == key)
//         return root;
//     else if(root->data < key)
//         return search_node(root->right,key);
//     else
//         return search_node(root->left,key);
// }

// void levelorder_traverse(Tnode* root){
//     Queue q;
//     Qinit(&q);
//     if(root==NULL)
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

// int check_search(Tnode* root,int n){
//     Tnode* result = search_node(root, n);
//     if(result == NULL) // ?
//         return TRUE;
//     else
//         return FALSE;
// }

// void f1(){
//     FILE* fp = fopen("in.txt","r");
//     char word;
//     int n;
//     Tnode* root = NULL;
//     Tnode* temp;
//     int result = 0;
//     int check = TRUE;
//     while(!feof(fp)){
//         fscanf(fp, "%c %d", &word, &n);
//         switch(word){
//             case 'A':
//                 printf("%c %d: ",word,n);
//                 check = check_search(root,n);
//                 if(check==TRUE){
//                     root = insert_node(root,n);        
//                     levelorder_traverse(root);
//                     printf("\n");
//                     break;
//                 }
//                 else{
//                     printf("%d cannot be inserted\n",n);
//                     break;
//                 }
//             case 'S':
//                 printf("%c %d: ",word,n);
//                 temp = search_node(root,n);
//                 if(temp != NULL)
//                     printf("%d is in T\n",n);
//                 else
//                     printf("%d is not in T\n",n);
//                 break;
//         }
//     }
//     fclose(fp);
// }

// int main(void){
//     f1();
// }