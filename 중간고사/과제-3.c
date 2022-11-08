#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int seq_search(int *arr,int target,int last){
    int i;
    for(i=0;i<last;i++){
        if(arr[i]==target)
            return i;
    }
    return -1;
}

int iter_search(int *arr,int target,int first,int last){
    int mid;
    while(first<=last){
        mid = (first+last)/2;
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]<target)
            first = mid+1;
        else if(arr[mid]>target)
            last = mid-1;
    }
    return -1;
}

int recur_search(int *arr,int target,int first,int last){
    int mid;
    while(first<=last){
        mid = (first+last)/2;
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]<target)
            return recur_search(arr,target,mid+1,last);
        else if(arr[mid]>target)
            return recur_search(arr, target,first,mid-1);
    }
    return -1;
}

int main(void){
    clock_t start, finish;
    double elapsed;
    start = clock();
    FILE* fp = fopen("in.txt","r");
    int n;
    int number;
    int i=0;
    int a,b,c;
    fscanf(fp,"%d",&n);

    while(1){
        FILE* fp = fopen("in.txt","r");
        fscanf(fp,"%d",&n);
        int *arr =(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            fscanf(fp,"%d",&arr[i]);

        scanf("%d",&number);
        if(number < 0)
            break;
        
        start=clock();
        a = seq_search(arr,number,n);
        finish=clock();
        elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
		printf("Sequential: %d <%fms>\n", a, elapsed * 1000.0);
        
        start=clock();
        b = iter_search(arr,number,0,n);
        finish=clock();
        elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
		printf("Iter: %d <%fms>\n", b, elapsed * 1000.0);
        
        
        start=clock();
        c = recur_search(arr,number,0,n);
        finish=clock();
        elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
		printf("Recursion: %d <%fms>\n", c, elapsed * 1000.0);
        free(arr);
        fclose(fp);
    }
}