#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct mat{
    int row;
    int col;
    int val;
}Mat;

Mat sparse_mat[MAX_SIZE];
Mat tran_sparse_mat[MAX_SIZE];

void fastTraverse(Mat a[],Mat b[]){
    int i,j;
    int row_terms[MAX_SIZE];
    int startingpos[MAX_SIZE];
    int row = a[0].col;
    int col = a[0].row;
    int val = a[0].val;

    b[0].row = row;
    b[0].col = col;
    b[0].val = val;

    if(val>0){
        for(i=0;i<row;i++)
            row_terms[i]=0;
        for(i=1;i<=val;i++)
            row_terms[a[i].col]++;
        startingpos[0]=1;
        for(i=1;i<row;i++)
            startingpos[i] = startingpos[i-1] + row_terms[i-1];
        for(i=1;i<=val;i++){
            j=startingpos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].val = a[i].val;
        }
    }

}
int main(void){
    FILE* fp = fopen("m1.txt","r");
    FILE* fp1 = fopen("out.txt","w");
    int** arr = (int**)malloc(sizeof(int*)*10);
    int cnt=0;
    int i,j,k=1;
    for(int i=0;i<10;i++){
        arr[i] = (int*)malloc(sizeof(int)* 12);
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<12;j++){
            fscanf(fp,"%d",&arr[i][j]);
            if(arr[i][j]!=0)
                cnt++;
        }
    }

    sparse_mat[0].row =10;
    sparse_mat[0].col = 12;
    sparse_mat[0].val = cnt;

    for(i=0;i<10;i++){
        for(j=0;j<12;j++){
            if(arr[i][j]!=0){
                sparse_mat[k].row=i;
                sparse_mat[k].col=j;
                sparse_mat[k].val=arr[i][j];
                k++;
            }
        }
    }

    for(i=0;i<k;i++){
        printf("%d %d %d\n",sparse_mat[i].row,sparse_mat[i].col,sparse_mat[i].val);
    }

    fastTraverse(sparse_mat,tran_sparse_mat);

    for(i=0;i<k;i++){
        fprintf(fp1, "%d %d %d\n", tran_sparse_mat[i].row,tran_sparse_mat[i].col,tran_sparse_mat[i].val);
    }
    fclose(fp);
    fclose(fp1);
}