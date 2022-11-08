#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0
typedef int element;

typedef struct stack{
    element data[MAX_SIZE];
    int top;
}Stack;

void stackinit(Stack* pstack){
    pstack->top=-1;
}

int stackisempty(Stack* pstack){
    if(pstack->top==-1)
        return TRUE;
    else
        return FALSE;
}

int stackisfull(Stack* pstack){
    if(pstack->top==MAX_SIZE-1)
        return TRUE;
    else   
        return FALSE;
}

void spush(Stack* pstack,element data){
    if(stackisfull(pstack)){
        printf("Stack is Full!\n");
        exit(-1);
    }
    pstack->data[++pstack->top] = data;
}

element spop(Stack* pstack){
    if(stackisempty(pstack)){
        printf("Stack is Empty!\n");
        exit(-1);
    }
    return pstack->data[pstack->top--];
}

element speek(Stack* pstack){
    if(stackisempty(pstack)){
        printf("Stack is Empty!\n");
        exit(-1);
    }
    return pstack->data[pstack->top];
}

int calc_op(int op1,int op2,char word){
    switch(word){
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
        case '%':
            return op1%op2;
    }
    return -1;
}

int calc_exp(char* exp){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stackinit(stack);
    int explen = strlen(exp);
    int result;
    char op1,op2;
    char word;
    int i=0;
    while(i<explen){
        word = exp[i++];
        if(isdigit(word)){
            spush(stack,word);
        }    
        else{
            op2 = spop(stack);
            op1 = spop(stack);
            result = calc_op(op1-'0',op2-'0',word);
            spush(stack,result+'0');
        }
    }
    result = spop(stack);
    return result-'0';
}

void f1(){
    char exp[MAX_SIZE];
    FILE* fp = fopen("in.txt","r");
    fgets(exp,sizeof(exp),fp);
    int result = calc_exp(exp);
    printf("%d",result);
}

int main(void){
    f1();
}
