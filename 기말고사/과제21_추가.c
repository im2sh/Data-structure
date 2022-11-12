#include <stdio.h>
#include <stdlib.h>

#define BUCKET_NUM 16
#define MAX_SIZE 100

typedef struct queue{
    int data[MAX_SIZE];
    int front;
    int rear;
}Queue;

void Qinit(Queue* q){
    q->front = 0;
    q->rear = 0;
}

int QisFull(Queue* q){
    return (q->rear+1) % MAX_SIZE == q->front;
}

int QisEmpty(Queue* q){
    return q->front == q->rear;
}

void enqueue(Queue* q, int key){
    if(QisFull(q)){
        printf("Q is Full!\n");
        exit(-1);
    }

    q->rear = (q->rear+1) %MAX_SIZE;
    q->data[q->rear]= key;
}

int dequeue(Queue* q){
    if(QisEmpty(q)){
        printf("Q is Empty!\n");
        exit(-1);
    }
    q->front = (q->front+1)%MAX_SIZE;
    return q->data[q->front];
}

void radix_sort(int arr[],int n,int len){
    Queue buckets[BUCKET_NUM];
    int i,j;
    int di;
    int div=1;
    int radix;
    for(i=0;i<BUCKET_NUM;i++)
        Qinit(&buckets[i]);
    for(j=0;j<len;j++){
        for(di=0;di<n;di++){
            radix = (arr[di]/div)%10;
            enqueue(&buckets[radix],arr[di]);
        }
        for(i=0,di=0;i<BUCKET_NUM;i++){
            while(!QisEmpty(&buckets[i])){
                arr[di++] = dequeue(&buckets[i]);
            }
        }
        div*=10;
    }
}
void f1(){
    FILE* fp = fopen("in.txt","r");
    int arr[100];
    int n=0;
    while(!feof(fp)){
        fscanf(fp,"%x",&arr[n++]);
    }
    radix_sort(arr,n,5);
    for(int i=0;i<n;i++){
        printf("%04X\n",arr[i]);
    }
}

int main(void){
    f1();
    return 0;
}