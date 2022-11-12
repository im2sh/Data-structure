#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct element{
    int key;
    char word;
}Element;

void swap(Element E[],int n1,int n2){
    Element temp = E[n1];
    E[n1] = E[n2];
    E[n2] = temp;
}

int partition(Element E[],int left,int right,int sel){
    int low = left+1;
    int high = right;
    if(sel == 1){
        int pivot = E[left].key;
        while(low<=high){
            while(pivot >= E[low].key && low<=right)
                low++;
            while(pivot <= E[high].key && high >= (left+1))
                high--;
            if(low<=high)
                swap(E,low,high);
        }
        swap(E,left,high);
    }
    else if(sel == 2){
        int pivot = E[left].word;
        while(low<=high){
            while(pivot > E[low].word && low<=right)
                low++;
            while(pivot <= E[high].word && high >= (left+1))
                high--;
            if(low<=high)
                swap(E,low,high);
        }
        swap(E,left,high);
    }
    return high;
}

void quickSort(Element E[],int left,int right,int sel){
    if(left<=right){
        int pivot = partition(E,left,right,sel);

        quickSort(E,left,pivot-1,sel);
        quickSort(E,pivot+1,right,sel);
    }
}

void f1(){
    FILE* fp = fopen("in.txt","r");
    FILE* fp1 = fopen("out.txt","w");
    Element E[MAX_SIZE];
    char word;
    int n=0;
    int sel;
    while(!feof(fp)){
        fscanf(fp,"%d %c\n",&E[n].key,&E[n].word);
        n++;
    }   
    n = n-1;
    scanf("%d",&sel);
    quickSort(E,0,n,sel);
    for(int i=0;i<=n;i++){
        fprintf(fp1,"%d %c\n",E[i].key, E[i].word);
    }
}

int main(void){
    f1();
}



// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// typedef struct element{
//     int key;
//     char word;
// }Element;

// void swap(Element* E,int n1,int n2){
//     Element temp = E[n1];
//     E[n1] = E[n2];
//     E[n2] = temp;
// }

// int partition(Element E[],int left,int right,int select){
//     if(select == 1){
//         int pivot = E[left].key;
//         int low = left+1;
//         int high = right;
//         while(low<=high){
//             while(pivot >= E[low].key && low<=right)
//                 low++;
//             while(pivot <= E[high].key && high >= (left+1))
//                 high--;
//             if(low<=high)
//                 swap(E,low,high);
//         }
//         swap(E,left,high);
//         return high;
//     }

//     else if(select == 2){
//         int pivot = E[left].word;
//         int low = left+1;
//         int high = right;
//         while(low<=high){
//             while(pivot >= E[low].word && low<=right)
//                 low++;
//             while(pivot <= E[high].word && high >= (left+1))
//                 high--;
//             if(low<=high)
//                 swap(E,low,high);
//         }
//         swap(E,left,high);
//         return high;
//     }
// }

// void qsort1(Element E[],int left,int right,int select){
//     if(left<=right){
//         int pivot = partition(E,left,right,select);

//         qsort1(E,left,pivot-1,select);
//         qsort1(E,pivot+1,right,select);
//     }
// }

// void f1(){
//     FILE* fp = fopen("in.txt","r");
//     FILE* fp1 = fopen("out.txt","w");
//     Element E[MAX_SIZE];
//     int n=0;
//     int sel;
//     int i;
//     while(!feof(fp)){
//         fscanf(fp,"%d %c\n",&E[n].key, &E[n].word);
//         n++;
//     }
//     n = n-1;
//     scanf("%d",&sel);
//     qsort1(E,0,n,sel);
    
//     for(i=0;i<=n;i++){
//         fprintf(fp1,"%d %c\n", E[i].key, E[i].word);
//     }
// }

// int main(void){
//     f1();
// }