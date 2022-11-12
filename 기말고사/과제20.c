#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct element{
    int key;
    char word;
}Element;

void mergeTwo(Element E[],int left,int mid,int right,int sel){
    int fIdx = left;
    int rIdx = mid+1;
    int i;
    Element* sort_arr = (Element*)malloc(sizeof(Element));
    int sIdx = left;
    if(sel==1){
        while(fIdx<=mid && rIdx <=right){
            if(E[fIdx].key >= E[rIdx].key)
                sort_arr[sIdx++] = E[fIdx++];
            else
                sort_arr[sIdx++] = E[rIdx++];
        }
        if(fIdx>mid){
            for(i=rIdx;i<=right;i++,sIdx++)
                sort_arr[sIdx] = E[i];
        }
        else{
            for(i=fIdx;i<=mid;i++,sIdx++)
                sort_arr[sIdx] = E[i];
        }
        for(i=left;i<=right;i++)
            E[i] = sort_arr[i];
    }

    else if(sel==2){
        while(fIdx<=mid && rIdx <=right){
            if(E[fIdx].word >= E[rIdx].word)
                sort_arr[sIdx++] = E[fIdx++];
            else
                sort_arr[sIdx++] = E[rIdx++];
        }
        if(fIdx>mid){
            for(i=rIdx;i<=right;i++,sIdx++)
                sort_arr[sIdx] = E[i];
        }
        else{
            for(i=fIdx;i<=mid;i++,sIdx++)
                sort_arr[sIdx] = E[i];
        }
        for(i=left;i<=right;i++)
            E[i] = sort_arr[i];
    }


    free(sort_arr);
}

void mergeSort(Element E[],int left,int right,int sel){
    int mid;
    if(left<right){
        mid = (left+right)/2;

        mergeSort(E,left,mid,sel);
        mergeSort(E,mid+1,right,sel);
        mergeTwo(E,left,mid,right,sel);
    }
}

void f1(){
    FILE* fp = fopen("in.txt","r");
    Element E[MAX_SIZE];
    int n = 0;
    int sel;
    while(!feof(fp)){
        fscanf(fp,"%d %c",&E[n].key, &E[n].word);
        n++;
    }
    n= n-1;
    scanf("%d",&sel);
    mergeSort(E,0,n-1,sel);
    for(int i=0;i<n;i++)
        printf("%d %c\n",E[i].key,E[i].word);
}

int main(void){
    f1();
}

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct element{
//     int key;
//     char word;
// }Element;

// void mergeTwo(Element E[],int left,int mid,int right,int select){
//     int L_idx = left;
//     int R_idx = mid+1;
//     int i;

//     Element* sortArr = (Element*)malloc(sizeof(Element)*right+1);
//     int sIdx = left;
//     if(select == 1){
//         while(L_idx<=mid && R_idx <= right){
//             if(E[L_idx].key >= E[R_idx].key)
//                 sortArr[sIdx] = E[L_idx++];
//             else
//                 sortArr[sIdx] = E[R_idx++];
//             sIdx++;
//         }
//         if(L_idx>mid){
//             for(i=R_idx;i<=right;i++,sIdx++){
//                 sortArr[sIdx] = E[i];
//             }
//         }
//         else{
//             for(i=L_idx;i<=mid;i++,sIdx++){
//                 sortArr[sIdx] = E[i];
//             }
//         }
//         for(i=left;i<=right;i++)
//             E[i] = sortArr[i];
//         free(sortArr);
//     }

//     else if(select == 2){
//         while(L_idx<=mid && R_idx <= right){
//             if(E[L_idx].word >= E[R_idx].word)
//                 sortArr[sIdx] = E[L_idx++];
//             else
//                 sortArr[sIdx] = E[R_idx++];
//             sIdx++;
//         }
//         if(L_idx>mid){
//             for(i=R_idx;i<=right;i++,sIdx++){
//                 sortArr[sIdx] = E[i];
//             }
//         }
//         else{
//             for(i=L_idx;i<=mid;i++,sIdx++){
//                 sortArr[sIdx] = E[i];
//             }
//         }
//         for(i=left;i<=right;i++)
//             E[i] = sortArr[i];
//         free(sortArr);
//     }
// }

// void mergesort1(Element E[], int left, int right, int select){
//     int mid;
//     if(left<right){
//         mid = (left+right)/2;
//         mergesort1(E,left,mid,select);
//         mergesort1(E,mid+1,right,select);

//         mergeTwo(E,left,mid,right,select);
//     }
// }

// void f1(){
//     FILE* fp = fopen("in.txt","r");
//     FILE* fp1 = fopen("out.txt","w");
//     Element E[100];
//     int n=0;
//     int sel;
//     while(!feof(fp)){
//         fscanf(fp,"%d %c\n",&E[n].key,&E[n].word);
//         n++;
//     }
//     n=n-1;
//     scanf("%d",&sel);
//     mergesort1(E,0,n,sel);
//     for(int i=0;i<=n;i++){
//         fprintf(fp1,"%d %c\n",E[i].key,E[i].word);
//     }
//     fclose(fp);
//     fclose(fp1);
// }

// int main(void){
//     f1();
// }

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// typedef struct element{
//     int key;
//     char word;
// }Element;

// void mergeTwo(Element E[],int left,int mid, int right,int select){
//     int fIdx = left;
//     int rIdx = mid+1;
//     int i;

//     Element* sortArr = (Element*)malloc(sizeof(Element)*right+1);
//     int sIdx = left;
//     if(select==1){
//         while(fIdx <= mid && rIdx <= right){
//             if(E[fIdx].key>=E[rIdx].key)
//                 sortArr[sIdx] = E[fIdx++];
//             else
//                 sortArr[sIdx] = E[rIdx++];
//             sIdx++;
//         }
//         if(fIdx>mid){
//             for(i=rIdx;i<=right;i++,sIdx++)
//                 sortArr[sIdx] = E[i];
//         }
//         else{
//             for(i=fIdx;i<=mid;i++,sIdx++)
//                 sortArr[sIdx] = E[i];
//         }
//         for(i=left;i<=right;i++)
//             E[i] = sortArr[i];

//         free(sortArr);
//     }
//     else{
//         while(fIdx <= mid && rIdx <= right){
//             if(E[fIdx].word>=E[rIdx].word)
//                 sortArr[sIdx] = E[fIdx++];
//             else
//                 sortArr[sIdx] = E[rIdx++];
//             sIdx++;
//         }
//         if(fIdx>mid){
//             for(i=rIdx;i<=right;i++,sIdx++)
//                 sortArr[sIdx] = E[i];
//         }
//         else{
//             for(i=fIdx;i<=mid;i++,sIdx++)
//                 sortArr[sIdx] = E[i];
//         }
//         for(i=left;i<=right;i++)
//             E[i] = sortArr[i];

//         free(sortArr);
//     }
// }

// void mergesort1(Element E[],int left,int right,int select){
//     int mid;
//     if(left<right){
//         mid = (left+right)/2;
//         mergesort1(E,left,mid,select);
//         mergesort1(E,mid+1,right,select);

//         mergeTwo(E,left,mid,right,select);
//     }
// }

// void f1(){
//     FILE* fp = fopen("in.txt","r");
//     FILE* fp1 = fopen("out.txt","w");
//     Element E[MAX_SIZE];
//     int select;
//     int i=0;
//     int size =0;
//     while(!feof(fp)){
//         fscanf(fp, "%d %c", &E[i].key,&E[i].word);
//         i++;
//     }
//     size = i-1;
//     scanf("%d",&select);
//     mergesort1(E,0,size-1,select);
//     for(i=0;i<size;i++){
//         fprintf(fp1,"%d %c\n",E[i].key,E[i].word);
//     }

// }

// int main(void){
//     f1();
// }