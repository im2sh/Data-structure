#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_VER 10

#define TRUE 1
#define FALSE 0

int visited[MAX_VER];

typedef struct graph{
    int v;
    int mat[MAX_VER][MAX_VER];
}Graph;

typedef struct queue{
    int data[MAX_SIZE];
    int front;
    int rear;
}Queue;

void Ginit(Graph* g){
    g->v = 0;
    for(int i=0;i<MAX_VER;i++){
        for(int j=0;j<MAX_VER;j++){
            g->mat[i][j] = 0;
        }
    }
}

void graph_insert_vertex(Graph* g,int v){
    g->v = v;
}

void graph_insert_edge(Graph* g,int x,int y){
    g->mat[x][y] = 1;
    g->mat[y][x] = 1;
}

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

void enqueue(Queue* q,int data){
    if(QisFull(q)){
        printf("Q is Full\n");
        exit(-1);
    }

    q->rear = (q->rear+1)%MAX_SIZE;
    q->data[q->rear] = data;
}

int dequeue(Queue* q){
    if(QisEmpty(q)){
        printf("Q is Empty!\n");
        exit(-1);
    }

    q->front = (q->front+1)%MAX_SIZE;
    return q->data[q->front];
}

void bfs(Graph* g,int v){
    Queue q;
    Qinit(&q);
    visited[v] =TRUE;
    printf("%d ",v);
    enqueue(&q,v);

    while(!QisEmpty(&q)){
        v=dequeue(&q);
        for(int i=1;i<=g->v;i++){
            if(!visited[i] && g->mat[v][i]){
                visited[i] = TRUE;
                printf("%d ", i);
                enqueue(&q,i);
            }
        }
    }
}

void bfs_init(){
    for(int i=0;i<MAX_VER;i++)
        visited[i] = FALSE;
}

void f1(){
    FILE* fp = fopen("in.txt","r");
    Graph* g = (Graph*)malloc(sizeof(Graph));
    int v;
    int x;
    int search;
    Ginit(g);
    fscanf(fp,"%d",&v);
    graph_insert_vertex(g,v);
    int i,j;
    while(!feof(fp)){
        for(i=2;i<=g->v;i++){
            for(j=1;j<=i-1;j++){
                fscanf(fp,"%d",&x);
                if(x==1)
                    graph_insert_edge(g,i,j);
            }
        }
    }
    while(1){
        bfs_init();
        scanf("%d",&search);
        if(search==-1)
            break;
        bfs(g,search);
    }
}

int main(void){
    f1();
}

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100
// #define MAX_VER 10

// #define TRUE 1
// #define FALSE 0

// int visited[MAX_VER];

// typedef struct graph{
//     int v;
//     int mat[MAX_VER][MAX_VER];
// }Graph;

// typedef struct queue{
//     int data[MAX_SIZE];
//     int front;
//     int rear;
// }Queue;

// void Ginit(Graph* g){
//     g->v = 0;
//     for(int i=0;i<MAX_VER;i++){
//         for(int j=0;j<MAX_VER;j++){
//             g->mat[i][j] = 0;
//         }
//     }
// }

// void graph_insert_vertex(Graph* g,int v){
//     g->v = v;
// }

// void graph_insert_edge(Graph* g,int x,int y){
//     g->mat[x][y] = 1;
//     g->mat[y][x] = 1;
// }

// void Qinit(Queue* q){
//     q->front = 0;
//     q->rear = 0;
// }

// int QisFull(Queue* q){
//     return (q->rear+1) % MAX_SIZE == q->front;
// }

// int QisEmpty(Queue* q){
//     return q->front == q->rear;
// }

// void enqueue(Queue* q,int data){
//     if(QisFull(q)){
//         printf("Q is Full\n");
//         exit(-1);
//     }

//     q->rear = (q->rear+1)%MAX_SIZE;
//     q->data[q->rear] = data;
// }

// int dequeue(Queue* q){
//     if(QisEmpty(q)){
//         printf("Q is Empty!\n");
//         exit(-1);
//     }

//     q->front = (q->front+1)%MAX_SIZE;
//     return q->data[q->front];
// }


// void bfs(Graph* g,int v){
//     Queue q;
//     Qinit(&q);
//     int i;
//     visited[v] = TRUE;
//     printf("%d ",v);
//     enqueue(&q,v);
//     while(!QisEmpty(&q)){
//         v = dequeue(&q);
//         for(i=1;i<=g->v;i++){
//             if(g->mat[v][i]&&!visited[i]){
//                 visited[i] = TRUE;
//                 printf("%d ",i);
//                 enqueue(&q,i);
//             }
//         }
//     }

// }

// void bfs_init(){
//     for(int i=0;i<MAX_VER;i++)
//         visited[i] = FALSE;
// }

// void f1(){
//     FILE* fp = fopen("in.txt","r");
//     Graph* g = (Graph*)malloc(sizeof(Graph));
//     int v;
//     int x;
//     int search;
//     Ginit(g);
//     fscanf(fp,"%d",&v);
//     graph_insert_vertex(g,v);
//     int i,j;
//     while(!feof(fp)){
//         for(i=2;i<=g->v;i++){
//             for(j=1;j<=i-1;j++){
//                 fscanf(fp,"%d",&x);
//                 if(x==1)
//                     graph_insert_edge(g,i,j);
//             }
//         }
//     }
//     while(1){
//         bfs_init();
//         scanf("%d",&search);
//         if(search==-1)
//             break;
//         bfs(g,search);
//     }
// }

// int main(void){
//     f1();
// }