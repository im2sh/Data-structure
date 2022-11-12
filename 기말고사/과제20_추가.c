#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct element{
    int key;
    char word;
}Element;

typedef struct heap{
    Element E[MAX_SIZE];
    int size;
}Heap;

void heap_insert(Heap* h,Element E,int select){
    int i = ++(h->size);
    if(select==1){
        while(i!=1 && E.key>h->E[i/2].key){
            h->E[i] = h->E[i/2];
            i/=2;
        }
        h->E[i] = E;
    }

    else if(select==2){
        while(i!=1 && E.word>h->E[i/2].word){
            h->E[i] = h->E[i/2];
            i/=2;
        }
        h->E[i] = E;
    }
}

Element delete_heap(Heap* h,int select){
    Element del_h = h->E[1];
    Element temp = h->E[h->size--];

    int parent = 1;
    int child = 2;
    if(select == 1){
        while(child<=h->size){
            if(child<h->size && h->E[child].key<h->E[child+1].key)
                child++;
            if(temp.key > h->E[child].key)
                break;
            
            h->E[parent] = h->E[child];
            parent = child;
            child *= 2;
        }
        h->E[parent] = temp;
        return del_h;
    }

    else if(select == 2){
        while(child<=h->size){
            if(child<h->size && h->E[child].word < h->E[child+1].word)
                child++;
            if(temp.word > h->E[child].word)
                break;
            
            h->E[parent] = h->E[child];
            parent = child;
            child *= 2;
        }
        h->E[parent] = temp;
        return del_h;
    }
}

void f1(){
    FILE* fp = fopen("in.txt","r");
    Heap h;
    h.size = 0;
    Element E;
    int n= 0;
    int sel;
    scanf("%d",&sel);
    while(!feof(fp)){
        fscanf(fp,"%d %c\n", &E.key,&E.word);
        heap_insert(&h,E,sel);
    }
    for(int i=0;i<4;i++){
        E = delete_heap(&h,sel);
        printf("%d %c\n",E.key,E.word);
    }
    fclose(fp);
}

int main(void){
    f1();
}