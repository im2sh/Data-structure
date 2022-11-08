#include <stdio.h>
#include <stdlib.h>

int** make2arr(int** arr,int row,int col){
    arr = (int**)malloc(sizeof(int*)*row);
    for(int i=0;i<row;i++){
        arr[i]=(int*)malloc(sizeof(int)*col);
    }
    return arr;
}

void fill_arr(FILE* fp, int** arr,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            fscanf(fp,"%d",&arr[i][j]);
        }
    }
}

int find_row(int row1,int row2){
    if(row1>row2)
        return row1;
    else
        return row2;
}

int find_col(int col1,int col2){
    if(col1>col2)
        return col1;
    else
        return col2;
}

int main(void){
    FILE* fp1 = fopen("m1.txt","r");
    FILE* fp2 = fopen("m2.txt","r");
    int a_row;
    int a_col;
    int b_row;
    int b_col;
    int c_row;
    int c_col;
    int i,j,k;
    int sum=0;
    fscanf(fp1,"%d",&a_row);
    fscanf(fp1,"%d",&a_col);
    fscanf(fp2,"%d",&b_row);
    fscanf(fp2,"%d",&b_col);

    c_row = find_row(a_row,b_row);
    c_col = find_col(a_col,b_col);

    int** arr1 = make2arr(arr1,a_row,a_col);
    int** arr2 = make2arr(arr2,b_row,b_col);
    int** arr3 = make2arr(arr3,c_row,c_col);

    // for(int i=0;i<a_row;i++){
    //     for(int j=0;j<a_col;j++){
    //         fscanf(fp1,"%d",&arr1[i][j]);
    //     }
    // }

    // for(int i=0;i<b_row;i++){
    //     for(int j=0;j<b_col;j++){
    //         fscanf(fp2,"%d",&arr2[i][j]);
    //     }
    // }

    
    fill_arr(fp1,arr1,a_row,a_col);
    fill_arr(fp2,arr2,b_row,b_col);

    for(i=0;i<a_row;i++){
        for(j=0;j<b_col;j++){
            sum=0;
            for(k=0;k<a_col;k++){
                sum+=arr1[i][k] * arr2[k][j];
            }
            arr3[i][j]=sum;
        }
    }

    printf("%d %d\n",c_row,c_col);
    for(i=0;i<c_row;i++){
        for(j=0;j<c_col;j++)
            printf("%d ",arr3[i][j]);
        printf("\n");
    }
}