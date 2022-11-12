#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{
    int key;
    char word;
}element;

void merge(element initList[],element mergedList[],int i,int m,int n,int sel){
    int j,k,t;
    j = m+1;
    k = i;
    if(sel == 1){
        while(i<=m && j<=n){
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
    else if(sel == 2){
        while(i<=m && j<=n){
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

void mergePass(element initList[],element mergedList[], int n,int s,int sel){
    int i,j;
    for(i=0;i<= n-2*s+1; i+=2*s)
        merge(initList,mergedList,i,i+s-1,i+2*s-1,sel);
    if(i+s-1<n)
        merge(initList,mergedList,i,i+s-1,n,sel);
    else{
        for(j=i;j<=n;j++)
            mergedList[j] = initList[j];
    }
}

void mergeSort(element a[],int n,int sel){
    int s= 1;
    element extra[MAX_SIZE];

    while(s<n){
        mergePass(a,extra,n,s,sel);
        s*=2;
        mergePass(extra,a,n,s,sel);
        s*=2;
    }
}

void f1(){
    FILE* fp = fopen("in.txt","r");
    FILE* fp1 = fopen("out.txt","w");
    char word;
    element E[MAX_SIZE];
    int n = 0;
    int sel;
    while(!feof(fp)){
        fscanf(fp,"%d %c\n",&E[n].key, &E[n].word);
        n++;
    }
    n=n-1;
    scanf("%d",&sel);
    mergeSort(E,n,sel);
    for(int i=0;i<=n;i++){
        printf("%d %c\n",E[i].key, E[i].word);
    }
}

int main(void){
    f1();
}
// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #include <string.h>
// #define MAX_SIZE 100

// void merge(char initList[], char mergedList[], int i, int m, int n) {
// 	int j, k, t;
// 	j = m + 1;
// 	k = i;

// 	while (i <= m && j <= n) {
// 		if (initList[i] >= initList[j])
// 			mergedList[k++] = initList[i++];
// 		else
// 			mergedList[k++] = initList[j++];
// 	}
// 	if (i > m)
// 		for (t = j; t <= n;t++)
// 			mergedList[t] = initList[t];
// 	else
// 		for (t = i;t <= m;t++)
// 			mergedList[k + t - i] = initList[t];

// }

// void mergePass(char initList[], char mergedList[], int n, int s) {
// 	int i, j;
// 	for (i = 0;i <= n - 2 * s + 1;i += 2 * s)
// 		merge(initList, mergedList, i, i + s - 1, i + 2 * s - 1);
// 	if (i + s - 1 < n)
// 		merge(initList, mergedList, i, i + s - 1, n);
// 	else
// 		for (j = i;j <= n;j++)
// 			mergedList[j] = initList[j];
// }

// void mergesort(char str[], int n) {
// 	int s = 1;
// 	char temp[MAX_SIZE];
// 	while (s < n) {
// 		mergePass(str, temp, n, s);
// 		s *= 2;
// 		mergePass(temp, str, n, s);
// 		s *= 2;
// 	}
// }

// int main(void) {
// 	FILE* fp = fopen("in.txt", "r");
// 	FILE* fp1 = fopen("out.txt", "w");
// 	char str[MAX_SIZE];
// 	memset(str, 0, MAX_SIZE * sizeof(char));
// 	int i = 0;
// 	char word;
// 	int size = 0;
// 	while (!feof(fp)) {
// 		word = fgetc(fp);
// 		if (word != '\n')
// 			str[i++] = word;
// 	}
// 	size = i - 1;
// 	mergesort(str, size);

// 	for (i = 0;i < size;i++) {
// 		fprintf(fp1, "%c\n", str[i]);
// 	}

// 	fclose(fp);
// 	fclose(fp1);
// 	return 0;
// }