#include <stdio.h>
#include <stdlib.h>

int b,s;
int** hash_table;

void make_ht(){
    hash_table = (int**)malloc(sizeof(int*)*b);
    for(int i=0;i<b;i++)
        hash_table[i] = (int*)malloc(sizeof(int)*s);
}

void init_ht(){
    for(int i=0;i<b;i++){
        for(int j=0;j<s;j++)
            hash_table[i][j] = 0;
    }
}

int hash_fun(int key){
    int hash_key;
    while(1){
        hash_key = key%b;
        if(hash_table[hash_key][s-1]!=0)
            key++;
        else
            return hash_key;
    }
}

void hash_insert(int key){
    int hash_key = hash_fun(key);
    for(int i=0;i<s;i++){
        if(hash_table[hash_key][i]==0){
            hash_table[hash_key][i] = key;
            break;
        }
    }
}

int hash_search(int key){
    for(int i=0;i<b;i++){
        for(int j=0;j<s;j++){
            if(hash_table[i][j]==key)
                return i;
        }
    }
    return -1;
}

void f1(){
    FILE* fp = fopen("in.txt","r");
    fscanf(fp,"%d %d",&b,&s);
    make_ht();
    init_ht();
    int key;
    int search;
    int result;
    while(!feof(fp)){
        fscanf(fp,"%d",&key);
        hash_insert(key);
    }

    for(int i=0;i<b;i++){
        printf("%d: ",i);
        for(int j=0;j<s;j++){
            if(hash_table[i][j]!=0)
                printf("%d ",hash_table[i][j]);
        }
        printf("\n");
    }

    while(1){
        scanf("%d",&search);
        if(search==-999)
            break;
        result = hash_search(search);
        printf("%d\n",result);
    }

}

int main(void){
    f1();
}

// #include <stdio.h>
// #include <stdlib.h>

// int b,s;

// int** hash_table;

// void make_hash_table(){
//     int i,j;
//     hash_table = (int**)malloc(sizeof(int*)*b);
//     for(i=0;i<b;i++)
//         hash_table[i] = (int*)malloc(sizeof(int)*s);
//     for(i=0;i<b;i++){
//         for(j=0;j<s;j++)
//             hash_table[i][j] = 0;
//     }
// }

// int hash_function(int key){
//     while(1){
//         int hash_key = key%b;
//         if(hash_table[hash_key][s-1] != 0)
//             key++;
//         else
//             return hash_key;
//     }
// }

// void hash_insert(int key){
//     int hash_key = hash_function(key);
//     int i=0;
//     for(int i=0;i<s;i++)
//         if(hash_table[hash_key][i]==0){
//             hash_table[hash_key][i] =key;
//             break;
//         }
// }

// int hash_search(int key){
//     for(int i=0;i<b;i++){
//         for(int j=0;j<s;j++){
//             if(key == hash_table[i][j])
//                 return i;
//         }
//     }
//     return -1;
// }

// void f1(){
//     FILE* fp = fopen("in.txt","r");
    
//     int i,j;
//     int key;
//     int search;
//     int result;
//     fscanf(fp,"%d %d",&b,&s);
//     make_hash_table();
    
//     while(!feof(fp)){
//         fscanf(fp,"%d",&key);
//         hash_insert(key);
//     }

//     for(i=0;i<b;i++){
//         printf("%d: ",i);
//         for(j=0;j<s;j++){
//             if(hash_table[i][j]!=0)
//                 printf("%d ",hash_table[i][j]);
//         }
//         printf("\n");
//     }
//     while(1){
//         printf("탐색하고 싶은 KEY를 입력하세요: ");
//         scanf("%d",&search);
//         if(search==-999)
//             break;
//         result = hash_search(search);
//         printf("%d에서 발견되었습니다.\n",result);
//     }
//     fclose(fp);
// }


// int main(void){
//     f1();
// }


