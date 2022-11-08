#include <stdio.h>
#include <string.h>

int palindrome(char* arr,int start,int end){
    if(start>=end)
        return 1;
    else if(arr[start]!=arr[end])
        return 0;
    else
        return palindrome(arr,start+1,end-1);
}

int main(void){
    int len;
    while(1){
        char str[20];
        scanf("%s",str);
        if(str[0]=='#')
            break;
        len =strlen(str);
        printf("%d\n",len);
        if(palindrome(str,0,strlen(str)-1))
            printf("YES\n");
        else
            printf("NO\n");
    }    
}