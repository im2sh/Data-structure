#include <stdio.h>
#include <stdlib.h>

#define MAX_VER 10

typedef struct graph{
    int v;
    int mat[MAX_VER][MAX_VER];
}Graph;

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct list{
    Node* head;
    Node* tail;
}List;

void insert_last(List* plist,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(plist->head == NULL)
        plist->head = newNode;
    else
        plist->tail->next = newNode;
    plist->tail = newNode;
}

void print_list(List* plist){
    Node* cur = plist->head;
    while(cur!=NULL){
        printf("%d ",cur->data);
        cur = cur->next;
    }
}

void Ginit(Graph* g){
    g->v = 0;
    for(int i=0;i<MAX_VER;i++){
        for(int j=0;j<MAX_VER;j++)
            g->mat[i][j] = 0;
    }
}

void graph_insert_vertex(Graph* g,int v){
    g->v = v;
}

void graph_insert_edge(Graph* g,int x,int y){
    g->mat[x][y] = 1;
    g->mat[y][x] = 1;
}



int main(void){
    FILE* fp = fopen("in.txt","r");
    Graph* g = (Graph*)malloc(sizeof(Graph));
    List* list = (List*)malloc(sizeof(List)*5);
    Ginit(g);
    graph_insert_vertex(g,5);
    int x,y;
    int i,j;

    while(!feof(fp)){
        fscanf(fp,"%d %d",&x,&y);
        graph_insert_edge(g,x,y);
    }

    for(i = 1;i<=g->v;i++){
        for(j=1;j<=g->v;j++){
            printf("%d ",g->mat[i][j]);
            if(g->mat[i][j]==1)
                insert_last(&list[i],j);
        }
        printf("\n");
    }
    for(i=1;i<=g->v;i++){
        printf("v%d : ",i);
        print_list(&list[i]);
        printf("\n");
    }
}
// #include <stdio.h>
// #include <stdlib.h>

// int graph[6][6];

// typedef struct node{
//     int data;
//     struct node* next;
// }Node;

// typedef struct list{
//     Node* head;
//     Node* tail;
// }List;

// List* create_list(){
//     List* newList = (List*)malloc(sizeof(List));
//     newList->head =NULL;
//     newList->tail =NULL;
//     return newList;
// }
// void insert_last(List* plist,int data){
//     Node* new_node = (Node*)malloc(sizeof(Node));
//     new_node->data = data;
//     new_node->next = NULL;

//     if(plist->head == NULL){
//         plist->head = new_node;
//     }
//     else
//         plist->tail->next = new_node;
//     plist->tail = new_node;
// }

// void print_list(List* plist){
//     Node* cur = plist->head;
//     while(cur!=NULL){
//         printf("%d ",cur->data);
//         cur=cur->next;
//     }
//     printf("\n");
// }

// void insert_graph(int x,int y){
//     graph[x][y] = 1;
//     graph[y][x] = 1;
// }

// int main(void){
//     FILE* fp = fopen("in.txt","r");
//     List* v;
//     v = (List*)malloc(sizeof(List)*5);

//     int x,y;
//     int i,j;
//     while(!feof(fp)){
//         fscanf(fp,"%d %d",&x,&y);
//         insert_graph(x,y);
//     }
//     for(i=1;i<6;i++){
//         for(j=1;j<6;j++){
//             printf("%d ",graph[i][j]);
//         }
//         printf("\n");
//     }
//     for(i=1;i<6;i++){
//         for(j=1;j<6;j++){
//             if(graph[i][j]==1){
//                 insert_last(&v[i],j);
//             }
//         }
//     }
//     for(i=1;i<6;i++){
//         printf("v%d: ",i);
//         print_list(&v[i]);
//     }
//     return 0;
// }
