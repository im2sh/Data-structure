#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int liter_fibo(int* a,int n){
    int i;
    if(n==0)
        return 0;
    for(i=2;i<=n;i++){
        a[i] = a[i-1] + a[i-2];
    }
    return a[i-1];
}

int recursion_fibo(int n){
    if(n==0)
        return 0;
    else if (n==1)
        return 1;
    else
        return recursion_fibo(n-1)+recursion_fibo(n-2);        
}

int main(void){
    clock_t start, finish;
    double elapsed;
    start = clock();
    int interation_fibo;
    int recur_fibo;
    int n=-1;
    while(1){
        scanf("%d",&n);
        if(n<0&&n>30)
            break;
        int* a = (int*)malloc(sizeof(int)*(n+1));
        a[0] = 0;
        a[1] = 1;

        start = clock();
		interation_fibo = liter_fibo(a,n);
        printf("%d\n",interation_fibo);
		finish = clock();
		elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
		printf("time:%f\n", elapsed * 1000.0);


		//Recursion
		start = clock();
		recur_fibo = recursion_fibo(n);
		printf("%d\n", recur_fibo);

		finish = clock();
		elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
		printf("time:%f\n", elapsed * 1000.0);
    }


    
}