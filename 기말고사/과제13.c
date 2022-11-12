#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct element{
    int key;
}Element;

typedef struct heap{
    Element heap[MAX_SIZE]; 
    int size;
}Heap;

void heap_insert(Heap* h,Element data){
    int i = ++(h->size);

    while(i!=1&&data.key>h->heap[i/2].key){
        h->heap[i] = h->heap[i/2];
        i/=2;
    }
    h->heap[i] = data;
}

Element heap_delete(Heap* h){
    Element del_h = h->heap[1];
    Element temp = h->heap[h->size--];
    int parent = 1;
    int child = 2;

    while(child<=h->size){
        if(child<h->size && h->heap[child].key < h->heap[child+1].key)
            child++;
        if(temp.key > h->heap[child].key)
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child*=2;
    }
    h->heap[parent] = temp;
    return del_h;
}

int main(void){
    FILE* fp = fopen("in.txt","r");
    Heap h;
    h.size = 0;
    int i;
    Element x;
    int del;
    int n =0;
    while(!feof(fp)){
        fscanf(fp,"%d",&x.key);
        heap_insert(&h,x);
        n++;
    }
    for(i=1;i<=h.size;i++){
        printf("%d ",h.heap[i].key);
    }
    printf("\n");
    for(i=0;i<n;i++){
        x = heap_delete(&h);
        printf("%d ",x.key);
    }
    printf("\n");

//    scanf("%d",&del);

}
// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// typedef struct element{
//     int data;
// }Element;

// typedef struct heap{
//     Element E[MAX_SIZE];
//     int size;
// }Heap;

// void insert_heap(Heap* h,Element item){
//     int i;
//     i = ++(h->size);

//     while((i!=1)&& (item.data > h->E[i/2].data)){
//         h->E[i] = h->E[i/2];
//         i/=2;
//     }
//     h->E[i] = item;
// }

// Element max_heap_delete(Heap* h){
//     int parent, child;
//     Element item,temp;

//     item = h->E[1];
//     temp = h->E[(h->size)--];
//     parent = 1;
//     child = 2;

//     while(child <= h->size){
//         if((child < h->size) && ((h->E[child].data)<h->E[child+1].data))
//             child++;

//         if(temp.data >= h->E[child].data)
//             break;

//         h->E[parent] = h->E[child];

//         parent =child;
//         child*=2;
//     }
//     h->E[parent] = temp;
//     return item;
// }

// void f1(){
//     FILE* fp = fopen("in.txt","r");
//     Heap* H = (Heap*)malloc(sizeof(Heap));
//     H->size = 0;
//     Element n;
//     int sel;

//     while(!feof(fp)){
//         fscanf(fp,"%d",&n.data);
//         insert_heap(H, n);
//     }

//     scanf("%d",&sel);
    
//     for(int i=0; i<sel;i++){
//         max_heap_delete(H);
//     }

//     for(int i=1;i<=H->size;i++){
//         printf("%d ", H->E[i].data);
//     }
// }

// int main(void){
//     f1();
// }