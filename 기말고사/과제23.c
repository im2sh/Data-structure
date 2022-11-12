
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void adjustheap(int arr[],int root, int n){
    int child, rootkey;
    int temp;
    temp = arr[root];
    rootkey = arr[root];
    child = 2 * root;

    while(child<=n){
        if((child<n)&&(arr[child]>arr[child+1]))
            child++;
        if(rootkey < arr[child])
            break;
        else{
            arr[child/2] = arr[child];
            child*=2;
        }
    }
    arr[child/2] = temp;
}

void heapSort(int arr[],int n){
    int i;
    int temp;
    for(i=n/2;i>0;i--)
        adjustheap(arr,i,n);
    for(i=n-1;i>0;i--){
        temp = arr[1];
        arr[1] = arr[i+1];
        arr[i+1] = temp;
        adjustheap(arr,1,i);
    }
}

// void insertsort(int arr[],int n){
//     int i,j;
//     int insData;

//     for(i=1;i<n;i++){
//         insData = arr[i];

//         for(j=i-1;j>=0;j--){
//             if(arr[j] < insData)
//                 arr[j+1] = arr[j];
//             else
//                 break;
//         }
//         arr[j+1] = insData;
//     }
// }

void insert(int temp,int arr[],int i){
    arr[0] = temp;
    while(temp>arr[i]){
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = temp;
}

void insert_sort(int arr[],int n){
    int temp;
    for(int i=2;i<=n;i++){
        temp = arr[i];
        insert(temp,arr,i-1);
    }
}

void f1(){
    FILE* fp = fopen("in.txt","r");
    int arr[MAX_SIZE];
    int i;
    int n = 0;
    fscanf(fp,"%d",&n);
    for(i=1;i<=n;i++){
        fscanf(fp,"%d",&arr[i]);
    }
    heapSort(arr, n);
    for(i=1;i<=n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    fclose(fp);
}

void f2(){
    FILE* fp = fopen("in.txt","r");
    int arr[MAX_SIZE];
    int i;
    int n = 0;
    fscanf(fp,"%d",&n);
    for(i=1;i<=n;i++){
        fscanf(fp,"%d",&arr[i]);
    }
    insert_sort(arr, n);
    for(i=1;i<=n;i++){
        printf("%d ",arr[i]);
    }
    fclose(fp);
}

int main(void){
    f1();
    f2();
}