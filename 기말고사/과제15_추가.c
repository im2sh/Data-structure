#include <stdio.h>
#include <stdlib.h>

int parent[10];

void weightedUnion(int i,int j){
    int temp = parent[i] + parent[j];
    if(parent[i]>=parent[j]){
        parent[i] = j;
        parent[j] = temp;
    }
    else{
        parent[j] = i;
        parent[i] = temp;
    }
}

int collaspingFind(int i){
    int root,trail,lead;
    for(root=i;parent[root]>=0;root = parent[root])
        ;
    for(trail = i; trail!=root;trail=lead){
        lead = parent[trail];
        parent[trail] = root;
    }
    return root;
}

void print_list(int n){
    for(int i=0;i<=n;i++)
        printf("%d ",parent[i]);
}
void f1(){
    FILE* fp = fopen("in.txt","r");
    int n;
    int i;
    char word;
    int x,y;
    int result;
    fscanf(fp,"%d",&n);
    for(i=0;i<=n;i++)
        parent[i] = -1;
    while(!feof(fp)){
        word = fgetc(fp);
        switch(word){
            case 'U':
                fscanf(fp,"%d %d",&x,&y);
                printf("%c %d %d: ",word,x,y);
                weightedUnion(x,y);
                print_list(n);
                printf("\n");
                break;
            case 'F':
                fscanf(fp,"%d",&x);
                printf("%c %d : ",word,x);
                result = collaspingFind(x);
                print_list(n);
                printf("\n");
                printf("%d\n",result);
        }
    }
}
int main(void){
    f1();
}

// #include <stdio.h>
// #include <stdlib.h>

// int parent[10];

// void weightedUnion(int i,int j){
//     int temp =parent[i] + parent[j];
//     if(parent[i] >= parent[j]){
//         parent[i] = j;
//         parent[j] = temp;
//     }
//     else{
//         parent[j] = i;
//         parent[i] = temp;
//     }
// }

// int collapsingFind(int i){
//     int root, trail, lead;
//     for(root = i; parent[root] >= 0; root = parent[root])
//         ;
//     for(trail = i;trail != root; trail = lead){
//         lead = parent[trail];
//         parent[trail] = root;
//     }
//     return root;
// }

// void print_p(int v){
//     for(int i=0;i<=v;i++){
//         printf("%d ",parent[i]);
//     }
//     printf("\n");
// }
// void f1(){
//     FILE* fp = fopen("in.txt","r");
//     int v;
//     int i;
//     char word;
//     int x,y;
//     int result = 0;
//     fscanf(fp,"%d",&v);
//     for(i=0;i<=v;i++)
//         parent[i] = -1;

//     while(!feof(fp)){
//         fscanf(fp,"%c",&word);
//         switch(word){
//             case 'U':
//                 fscanf(fp,"%d %d",&x,&y);
//                 printf("%c %d %d : ",word,x,y);
//                 weightedUnion(x,y);
//                 print_p(v);
//                 break;

//             case 'F':
//                 fscanf(fp,"%d",&x);
//                 printf("%c %d : ",word,x);
//                 result = collapsingFind(x);
//                 print_p(v);
//                 printf("%d\n", result);
//                 break;
            
//         }
//     }
// }

// int main(void){
//     f1();
// }