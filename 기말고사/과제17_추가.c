#include <stdio.h>
#include <stdlib.h>

#define MAX_VER 10

int visited[MAX_VER];
#define TRUE 1
#define FALSE 0

typedef struct element{
	int x;
	int y;
	int w;
}Element;

typedef struct graph{
	int v;
	int mat[MAX_VER][MAX_VER];
}Graph;

void Ginit(Graph* g){
	g->v = 0;
	for(int i = 0; i<MAX_VER;i++){
		for(int j=0;j<MAX_VER;j++){
			g->mat[i][j] = 0;
		}
	}
}

void graph_insert_vertex(Graph* g,int v){
	g->v = v;
}

void graph_insert_edge(Graph* g,int x,int y,int w){
	g->mat[x][y] = w;
	g->mat[y][x] = w;
}

Element kruskal(Graph* g){
	Element temp;
	int min = 999;
	int i,j;
	for(i=1;i<=g->v;i++){
		for(j=1;j<=g->v;j++){
			if(min>g->mat[i][j]&&g->mat[i][j] != 0){
				min = g->mat[i][j]; 
				temp.x = i;
				temp.y = j;
				temp.w = min;
			}
		}
	}	
	return temp;
}


void f1(){
	FILE* fp = fopen("in.txt","r");
	Graph* g = (Graph*)malloc(sizeof(Graph));
	Graph* mst = (Graph*)malloc(sizeof(Graph));
	Ginit(g);
	Ginit(mst);
	Element temp;
	int v;
	int i,j;
	int x;
	fscanf(fp,"%d",&v);
	graph_insert_vertex(g,v);
	graph_insert_vertex(mst,v);
	while(!feof(fp)){
		for(i=2;i<=g->v;i++){
			for(j=1;j<=i-1;j++){
				fscanf(fp,"%d",&x);
				if(x!=0){
					graph_insert_edge(g,i,j,x);
				}
			}
		}
	}
	temp = kruskal(g);

	visited[temp.x] = TRUE;
	visited[temp.y] = TRUE;
	mst->mat[temp.x][temp.y] = temp.w;
	mst->mat[temp.y][temp.x] = temp.w;

	g->mat[temp.x][temp.y] = 0;
	g->mat[temp.y][temp.x] = 0;


	for(i=1;i<=g->v;i++){
		temp = kruskal(g);
		if((!visited[temp.x] && visited[temp.y]) || (visited[temp.x] && !visited[temp.y])){
			visited[temp.x] = TRUE;
			visited[temp.y] = TRUE;
			mst->mat[temp.x][temp.y] = temp.w;
			mst->mat[temp.y][temp.x] = temp.w;
			g->mat[temp.x][temp.y] = 0;	
			g->mat[temp.y][temp.x] = 0;
		}
	}

	for(i=2;i<=g->v;i++){
		for(j=1;j<=i-1;j++)
			printf("%d ",mst->mat[i][j]);
		printf("\n");
	}
}

int main(void){
	f1();
}