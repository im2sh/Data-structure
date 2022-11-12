#include <stdio.h>
#include <stdlib.h>

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
    if(sel==1){
        int pivot = E[left].key;
        while(low<=high){
            while(pivot>=E[low].key && low<=high)
                low++;
            while(pivot<=E[high].key && high>=(left+1))
                high--;
            if(low<=high)
                swap(E,low,high);
        }
        swap(E,left,high);
    }
    else if(sel==2){
        int pivot = E[left].word;
        while(low<=high){
            while(pivot>=E[low].word && low<=high)
                low++;
            while(pivot<=E[high].word && high>=(left+1))
                high--;
            if(low<=high)
                swap(E,low,high);
        }
        swap(E,left,high);
    }
    return high;
}

void q_sort(Element E[],int left,int right,int sel){
    if(left<=right){
        int pivot = partition(E,left,right,sel);

        q_sort(E,left,pivot-1,sel);
        q_sort(E,pivot+1,right,sel);
    }
}

void f1(){
    FILE* fp = fopen("in.txt","r");
    char word;
    int n=0;
    Element E[100];
    int s;
    while(!feof(fp)){
        fscanf(fp,"%d %c",&E[n].key,&E[n].word);
        n++;
    }
    n=n-1;
    scanf("%d",&s);
    q_sort(E,0,n-1,s);
    for(int i=0;i<n;i++)
        printf("%d %c\n",E[i].key, E[i].word);
}

int main(void){
    f1();
}


// #include <stdio.h>
// #include <stdlib.h>
// typedef struct element{
//     char word;
// }Element;

// void swap(Element* E, int n1,int n2){
//     Element temp = E[n1];
//     E[n1] = E[n2];
//     E[n2] = temp;
// }

// int partition(Element* E,int left,int right){
//     int pivot = E[left].word;
//     int low = left+1;
//     int high = right;
//     while(low<=high){
//         while(pivot>=E[low].word&&low<=right)
//             low++;
//         while(pivot<=E[high].word&&high>=(left+1))
//             high--;
//         if(low<=high)
//             swap(E,low,high);
//     }
//     swap(E,left,high);
//     return high;
// }

// void quicksort(Element *E, int left, int right){
//     if(left<=right){
//         int pivot = partition(E,left,right);

//         quicksort(E,left,pivot-1);
//         quicksort(E,pivot+1,right);
//     }
// }
// void f1(){
//     FILE* fp = fopen("in.txt","r");
//     Element* E = (Element*)malloc(sizeof(Element));
//     int i=0;
//     int size = 0;
//     char word;
//     while(!feof(fp)){
//         word = fgetc(fp);
//         if(word!='\n')
//             E[i++].word = word;
//     }
//     size = i-1;
//     quicksort(E,0,size-1);
//     for(i=0;i<size;i++){
//         printf("%c\n",E[i].word);
//     }
// }

// int main(void){
//     f1();
// }