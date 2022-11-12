#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{
    int key;
    char word;
}element;

void merge(element initList[],element mergedList[],int i,int m,int n,int select){
    int j,k,t;
    j = m+1;
    k=i;
    if(select == 1){
        while(i<=m && j<= n){
            if(initList[i].key >= initList[j].key)
                mergedList[k++] = initList[i++];
            else
                mergedList[k++] = initList[j++];
        }

        if(i>m){
            for(t=j;t<=n;t++)
                mergedList[t] = initList[t];
        }
        else{
            for(t=i;t<=m;t++)
                mergedList[k+t-i] = initList[t];
        }
    }
    else if(select == 2){
        while(i<=m && j<= n){
            if(initList[i].word >= initList[j].word)
                mergedList[k++] = initList[i++];
            else
                mergedList[k++] = initList[j++];
        }

        if(i>m){
            for(t=j;t<=n;t++)
                mergedList[t] = initList[t];
        }
        else{
            for(t=i;t<=m;t++)
                mergedList[k+t-i] = initList[t];
        }
    }
}

void mergePass(element initList[], element mergedList[],int n,int s,int select){
    int i,j;
    for(i=0;i<=n-2*s+1; i+= 2*s)
        merge(initList,mergedList,i,i+s-1,i+2*s-1,select);
    if(i+s-1<n)
        merge(initList,mergedList,i,i+s-1,n,select);
    else{
        for(j=i;j<=n;j++)
            mergedList[j] = initList[j];
    }
}

void mergeSort(element a[],int n,int select){
    int s = 1;
    element extra[MAX_SIZE];

    while(s<n){
        mergePass(a,extra,n,s,select);
        s*=2;
        mergePass(extra,a,n,s,select);
        s*=2;
    }
}


void f1(){
    FILE* fp = fopen("in.txt","r");
    FILE* fp1 = fopen("out.txt","w");
    element E[MAX_SIZE];
    int i;
    int n=0;
    int sel;
    char word;
    while(!feof(fp)){
        fscanf(fp,"%d %c\n",&E[n].key,&E[n].word);
        n++;
    }
    scanf("%d",&sel);
    n = n-1;
    mergeSort(E,n,sel);
    for(i=0;i<=n;i++){
        fprintf(fp1,"%d %c\n",E[i].key, E[i].word);
    }

}

int main(void){
    f1();
}