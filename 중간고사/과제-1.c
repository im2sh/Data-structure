#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE* fp =fopen("in.txt","r");
	FILE* fp1 = fopen("out.txt","w");
	int n;
	int *arr;
	int min;
	int max;
	int i=0;
	int x=-1;
	fscanf(fp,"%d",&n);
	arr = (int*)malloc(sizeof(int)*n);
	while(!(feof(fp))){
		fscanf(fp,"%d",&arr[i++]);
	}
	min = arr[0];
	max = arr[0];

	for(i=0;i<n;i++){
		if(max>arr[i])
			 max = arr[i];
		if(min < arr[i])
			min = arr[i];
	}
	printf("n: %d\n", n);
	printf("최소값: %d\n", min);
	printf("최대값: %d\n", max);

	while(x<=0){
		scanf("%d",&x);
	}
	printf("%d의 배수: ",x);
	for(i=0;i<n;i++){
		if(arr[i]%x==0){
			fprintf(fp,"%d", arr[i]);
			printf("%d",arr[i]);
		}
	}
	fclose(fp);
	fclose(fp1);
}