#include <stdio.h>
#include <stdlib.h>

int** make2arr(int** arr,int row,int col){
    arr = (int**)malloc(sizeof(int*)*row);
    for(int i=0;i<row;i++){
        arr[i] = (int*)malloc(sizeof(int)*col);
    }
    return arr;
}

void freearr(int** arr,int row){
    for(int i=0;i<row;i++){
        free(arr[i]);
    }
    free(arr);
}

int main(void){
    FILE* fp1=fopen("m1.txt","r");
    FILE* fp2 =fopen("m2.txt","r");
    int a_row;
    int a_col;
    int b_row;
    int b_col;
    int i,j;
    int x;
    fscanf(fp1,"%d",&a_row);
    fscanf(fp1,"%d",&a_col);
    fscanf(fp2,"%d",&b_row);
    fscanf(fp2,"%d",&b_col);
    
    //int** arr=make2arr(arr,a_row,a_col);
    int** arr1=make2arr(arr1,a_row,a_col);
    int** arr2=make2arr(arr2,b_row,b_col);
    
    for(i=0;i<a_row;i++){
        for(j=0;j<a_col;j++){
            fscanf(fp1,"%d",&arr1[i][j]);
        }
    }

    for(i=0;i<b_row;i++){
        for(j=0;j<b_col;j++){
            fscanf(fp2,"%d",&arr2[i][j]);
        }
    }
    for(i=0;i<a_row;i++){
        for(j=0;j<a_col;j++){
            
            printf("%d ",arr1[i][j]+arr2[i][j]);
        }
        printf("\n");
    }

    fclose(fp1);
    fclose(fp2);
    freearr(arr1,a_row);
    freearr(arr2,b_row);
    return 0;
}