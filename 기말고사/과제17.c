#include <stdio.h>
#include <stdlib.h>

#define MAX_VER 10
#define TRUE 1
#define FALSE 0

int visited[MAX_VER];
int cycle;

typedef struct graph{
    int v;
    int mat[MAX_VER][MAX_VER];
}Graph;

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

void dfs(Graph* g,int v){
    int i;
    visited[v] = TRUE;

    for(i=1;i<=g->v;i++){
        if(g->mat[v][i] && !visited[i])
            dfs(g,i);
    }
}

void dfs_cycle(Graph* g,int v,int past){
    int i;
    visited[v] = TRUE;

    for(i=1;i<=g->v;i++){
        if(g->mat[v][i] && !visited[i])
            dfs_cycle(g,i,v);
        else if(!g->mat[v][i])
            continue;
        else if(g->mat[v][i] && visited[i] && past != i)
            cycle = TRUE;
    }
}
void dfs_init(){
    for(int i=0;i<MAX_VER;i++)
        visited[i] = FALSE;
}

void f1(){
    FILE* fp = fopen("in.txt","r");
    Graph* g = (Graph*)malloc(sizeof(Graph));
    Ginit(g);
    int i,j;
    int v;
    int x;
    int component = 0;
    fscanf(fp,"%d",&v);
    graph_insert_vertex(g,v);

    while(!feof(fp)){
        for(i=2;i<=g->v;i++){
            for(j=1;j<=i-1;j++){
                fscanf(fp,"%d",&x);
                if(x==1)
                    graph_insert_edge(g,i,j);
            }
        }
    }
    for(i=1;i<=g->v;i++){
        if(!visited[i]){
            dfs(g,i);
            component++;
        }
    }
    printf("%d\n",component);
}

void f2(){
    FILE* fp = fopen("in.txt","r");
    Graph* g = (Graph*)malloc(sizeof(Graph));
    Ginit(g);
    int i,j;
    int v;
    int x;
    fscanf(fp,"%d",&v);
    graph_insert_vertex(g,v);

    while(!feof(fp)){
        for(i=2;i<=g->v;i++){
            for(j=1;j<=i-1;j++){
                fscanf(fp,"%d",&x);
                if(x==1){
                    graph_insert_edge(g,i,j);
                }
            }
        }
    }
    dfs_init();
    for(i=1;i<=g->v;i++){
        if(!visited[i])
            dfs_cycle(g,i,0);
    }
    if(cycle == TRUE)
        printf("yes\n");
    else
        printf("no\n");
}

int main(void){
    f1();
    f2();
}


// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_VER 10
// #define TRUE 1
// #define FALSE 0
// int cycle;
// int visited[MAX_VER]={};

// typedef struct graph{
//     int vertex;
//     int mat[MAX_VER][MAX_VER];
// }Graph;

// void Ginit(Graph* g){
//     g->vertex = 0;
//     for(int i=0;i<MAX_VER;i++){
//         for(int j=0;j<MAX_VER;j++){
//             g->mat[i][j] = 0;
//         }
//     }
// }

// void graph_insert_vertex(Graph* g,int v){
//     g->vertex = v;
// }

// void graph_insert_edge(Graph* g,int x,int y){
//     g->mat[x][y] = 1;
//     g->mat[y][x] = 1;
// }

// void dfs(Graph* g,int v,int past){
//     visited[v] = TRUE;
//     for(int i=1;i<=g->vertex;i++){
//         if(!visited[i]&&g->mat[v][i])
//             dfs(g,i,v);
//         else if(!g->mat[v][i])
//             continue;
//         else if(past!=i&&g->mat[v][i]&&visited[i])
//             cycle =TRUE;
//     } 
// }

// void f1(){
//     FILE* fp = fopen("in.txt","r");
//     Graph* g = (Graph*)malloc(sizeof(Graph));
//     int v;
//     int i,j;
//     int x;
//     int componenet = 0;
//     fscanf(fp,"%d",&v);
//     Ginit(g);
//     graph_insert_vertex(g,v);
//     while(!feof(fp)){
//         for(i=2;i<=v;i++){
//             for(j=1;j<=i-1;j++){
//                 fscanf(fp,"%d",&x);
//                 if(x==1)
//                     graph_insert_edge(g,i,j);
//             }
//         }
//     }
//     for(i=1;i<=g->vertex;i++){
//         if((!visited[i])){
//             dfs(g,i,0);
//             componenet++;
//         }
//     }
//     printf("%d\n",componenet);
//     if(cycle==TRUE)
//         printf("yes");
//     else
//         printf("no");
// }



// int main(void){
//     f1();
// }