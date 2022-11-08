#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int binary(int n,int count){
    if(n==0)
        return count;
    else{
        if(n%2==1)
            count++;
        return binary(n/2,count);
    }
}

void f1(){
    int x;
    int count;
    while(1){
        count = 0;
        scanf("%d",&x);
        if(x==-1)
            break;
        count = binary(x,count);
        printf("%d",count);
    }
}
int main(void){
    f1();
}