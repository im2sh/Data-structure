#include <stdio.h>
#include <stdlib.h>

void f1(){
    FILE* fp = fopen("in.txt","r");
    FILE* fp1 = fopen("key.txt","r");
    int cnt=0;
    int n;
    int key_num;
    fscanf(fp1,"%d",&key_num);
    int* key = (int*)malloc(sizeof(int)*key_num);
    int row=10;
    int col = 10;
    int i,j,k;
    int key_row=-1;
    int key_col=-1;
    int** arr = (int**)malloc(sizeof(int*)*row);
    for(i=0;i<row;i++){
        arr[i] = (int*)malloc(sizeof(int)*col);
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            fscanf(fp,"%d",&arr[i][j]);
        }
    }

    for(i=0;i<key_num;i++){
        fscanf(fp1,"%d",&key[i]);
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            n=j;
            cnt =0;
            if(arr[i][j]==key[0]){
                for(k=0;k<key_num;k++){
                    if(arr[i][n++]==key[k])
                        cnt++;
                }
            }
            if(cnt==key_num){
                key_row = i;
                key_col = j;
            }
        }
    }
    printf("(%d %d)",key_row,key_col);
}

int main(void){
    f1();
}