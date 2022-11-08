#include <stdio.h>
#define TRUE 1
#define FALSE 0

int prime(int x,int y){
    if(x==1||y==1)
        return TRUE;
    else if(x!=1&&y!=1&&x==y)
        return FALSE;
    else if(x!=1&&y!=1&&x<y)
        return prime(x,y-x);
    else if(x!=1&&y!=1&&x>y)
        return prime(x-y,y);
}

int main(void){
    int a=0,b=0;
    FILE *fp = fopen("in.txt","r");
    fscanf(fp,"%d", &a);
    fscanf(fp,"%d", &b);
    int result = prime(a,b);
    if(result == TRUE)
        printf("TRUE");
    else if(result == FALSE)
        printf("FALSE");
    fclose(fp);
}