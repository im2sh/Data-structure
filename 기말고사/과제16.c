#include <stdio.h>
#include <stdlib.h>

typedef struct 

void f1(){
    
}

void f2(){

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
// int visited[MAX_VER];

// typedef struct graph{
//     int mat[MAX_VER][MAX_VER];
//     int vertex;
// }Graph;

// void Ginit(Graph* g){
//     g->vertex = 0;
//     for(int i=0;i<MAX_VER;i++){
//         for(int j=0;j<MAX_VER;j++){
//             g->mat[i][j]=0;
//         }
//     }
// }

// void graph_insert_vertex(Graph* g, int v){
//     g->vertex = v;

// }

// void graph_insert_edge(Graph* g,int x,int y){
//     g->mat[x][y] = 1;
//     g->mat[y][x] = 1;
// }

// void dfs(Graph* g,int v){
//     int i;
//     visited[v] = TRUE;
//     printf("%d ",v);
//     for(i=1;i<=g->vertex;i++){
//         if(!visited[i]&&g->mat[v][i])
//             dfs(g,i);
//     }
// }

// void dfs_init(Graph* g){
//     for(int i=0;i<MAX_VER;i++)
//         visited[i] = FALSE;
// }

// void f1(){
//     FILE* fp = fopen("in.txt","r");
//     int v;
//     int i,j;
//     int x;
//     int sel;
//     Graph* g = (Graph*)malloc(sizeof(Graph));
//     Ginit(g);
//     fscanf(fp,"%d",&v);
//     graph_insert_vertex(g,v);
//     while(!feof(fp)){
//         for(i=2;i<=v;i++){
//             for(j=1; j<=i-1; j++){
//                 fscanf(fp,"%d",&x);
//                 if(x==1){
//                     graph_insert_edge(g,i,j);
//                 }
//             }
//         }
//     }
//     while(1){
//         dfs_init(g);
//         scanf("%d",&sel);
//         if(sel==-1)
//             break;
//         dfs(g,sel);
//         printf("\n");
//     }
// }

// int main(void){
//     f1();
// }





