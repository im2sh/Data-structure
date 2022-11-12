#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct element{
    int el;
    char str[MAX_SIZE];
}Element;

typedef struct heap{
    Element key[MAX_SIZE];
    int size;
}Heap;

void heap_insert(Heap* h,Element data){
    int i = ++(h->size);

    while(i!=1 && data.el < h->key[i/2].el){
        h->key[i] = h->key[i/2];
        i/=2;
    }

    h->key[i] = data;
}

Element heap_delete(Heap* h){
    Element del_h = h->key[1];
    Element temp = h->key[h->size--];
    int parent = 1;
    int child = 2;

    while(child<=h->size){
        if(child<h->size && h->key[child].el > h->key[child+1].el)
            child++;
        if(temp.el < h->key[child].el)
            break;
        h->key[parent] = h->key[child];
        parent = child;
        child*=2;
    }

    h->key[parent] = temp;
    return del_h;
}

void f1(){
    FILE* fp = fopen("in.txt","r");
    Heap h;
    h.size = 0;
    int i;
    Element temp;
    int n = 0;
    while(!feof(fp)){
        fscanf(fp,"%d %s",&temp.el, temp.str);
        heap_insert(&h,temp);
        n++;
    }
    
    for(i=0;i<n;i++){
        temp = heap_delete(&h);
        printf("%d %s\n",temp.el, temp.str);
    }
    fclose(fp);
}

int main(void){
    f1();
}

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// typedef struct element{
//     int key;
//     char str[MAX_SIZE];
// }Element;

// typedef struct heap{
//     Element E[MAX_SIZE];
//     int size;
// }Heap;

// void insert_heap(Heap* h,Element data){
//     int i = ++(h->size);

//     while((i!=1)&&data.key<h->E[i/2].key){
//         h->E[i] = h->E[i/2];
//         i/=2; 
//     }

//     h->E[i] = data;
// }

// Element delete_heap(Heap* h){
//     Element del_h = h->E[1];
//     Element temp = h->E[h->size--];
//     int parent = 1;
//     int child = 2;

//     while(child<=h->size){
//         if(child<h->size && h->E[child].key > h->E[child+1].key)
//             child++;
//         if(temp.key <= h->E[child].key)
//             break;
//         h->E[parent] = h->E[child];
//         parent = child;
//         child*=2;
//     }
//     h->E[parent] = temp;
//     return del_h;
// }

// void f1(){
//     FILE* fp = fopen("in.txt","r");
//     Heap h;
//     Element x;
//     int i;
//     h.size = 0;
//     int n=0;
//     Element temp;
//     while(!feof(fp)){
//         fscanf(fp,"%d %s",&x.key, x.str);
//         insert_heap(&h,x);
//         n++;
//     }

//     for(i=0;i<n;i++){
//         x = delete_heap(&h);
//         printf("%d %s\n", x.key,x.str);
//     }    
// }

// int main(void){
//     f1();
// }