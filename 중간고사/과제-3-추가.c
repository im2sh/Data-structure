#include <stdio.h>
#include <stdlib.h>

int seq_search(char *arr,int target,int len){
    for(int i=0;i<len;i++){
        if(arr[i]==target){
            return i;
            break;
        }
    }
    return -1;
}

int iter_binary_search(char* arr,int target,int first,int last){
    int mid;
    while(first<=last){
        mid = (first+last)/2;
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]<target)
            first = mid+1;
        else
            last = mid-1;
    }
    return -1;
}

int recur_binary_search(char* arr,int target,int first,int last){
    int mid;
    if(first<=last){
        mid = (first+last)/2;
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]<target)
            return recur_binary_search(arr,target,mid+1,last);
        else
            return recur_binary_search(arr,target,first,mid-1);
    }
    return -1;
}

void f1(){
    int num;
    int result;
    int i;
    char target = 97;
    while(target>='0'){
        FILE* fp = fopen("in.txt","r");
        fscanf(fp,"%d",&num);
        char* arr = (char*)malloc(sizeof(char)*num+1);
        for(i=0;i<num;i++)
            fscanf(fp,"%c",&arr[i]);
        scanf("%c", &target);
        while(getchar()!='\n');
        if(!(97<=target&&target<=122))
            break;
        result = seq_search(arr,target,num);
        printf("%d\n",result);
        result = iter_binary_search(arr,target,0,num);
        printf("%d\n",result);
        result = recur_binary_search(arr,target,0,num);
        printf("%d\n",result);
        free(arr);
        fclose(fp);
    }
}

int main(void){
    f1();
}