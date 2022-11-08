#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int main(void){
    FILE* fp = fopen("in.txt", "r");
    int array[MAX_SIZE];
    int array1[MAX_SIZE]; 
    int i; 
    int j;
    int k=0; 
    int cnt;
    int same=0; 
    int help;
    int cnt1=0;
    while(!(feof(fp))){
        fscanf(fp,"%d",&array[i]);
        i++;
    }
    cnt = i;

    for(i=0;i<cnt;i++){
        same = 0; 
        help = array[i];
        for(j=i+1;j<cnt;j++){
            if(help == array[j])
                same++;
        }
        if(same>0){
            array1[k++] = array[i];
            cnt1++;
        }
    }

     for(i=0;i<cnt1;i++){
        same = 0; 
        help = array1[i];
        for(j=i+1;j<cnt1;j++){
            if(help == array1[j])
                same++;
        }
        if(same>0){
            printf("%d ",array1[i]);
        }
    }


    fclose(fp);
}