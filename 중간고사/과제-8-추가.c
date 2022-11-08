#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100

typedef struct stack {
	int stack[MAX_STACK_SIZE];
	int topindex;
}Stack;

void stackinit(Stack* pstack) {
	pstack->topindex = -1;
}

int SisEmpty(Stack* pstack) {
	if (pstack->topindex == -1)
		return 1;
	else
		return 0;
}

void spush(Stack* pstack, int data) {
	pstack->stack[++pstack->topindex] = data;
}

int spop(Stack* pstack) {
	if (SisEmpty(pstack))
		return -1;

	return pstack->stack[pstack->topindex--];
}

int speek(Stack* pstack) {
	if (SisEmpty(pstack))
		return -1;
	return pstack->stack[pstack->topindex];
}

int GetOpPrec(char op){
    switch(op){
        case '*':
        case '/':
        case '%':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(':
            return 1;
    }

    return -1;
}

int WhoPrecOp(char op1,char op2){
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if(op1Prec>op2Prec)
        return 1;
    else if(op1Prec < op2Prec)
        return -1;
    else
        return 0;
}

void ConvToRPNExp(char exp[]){
    Stack stack;
    int expLen = strlen(exp);
    char*convExp = (char*)malloc(expLen+1);
    int i,idx=0;
    char tok,popOp;
    memset(convExp,0,sizeof(char)*expLen+1);
    stackinit(&stack);

    for(i=0;i<expLen;i++){
        tok = exp[i];
        if(isdigit(tok)){
            convExp[idx++] = tok;
        }
        else{
            switch(tok){
                case '(':
                    spush(&stack,tok);
                    break;
                case ')':
                    while(1){
                        popOp = spop(&stack);
                        if(popOp == '(')
                            break;
                        convExp[idx++] = popOp;
                    }
                    break;
                
                case '+': case'-': 
                case '*': case'/': case'%':
                    while(!SisEmpty(&stack)&&WhoPrecOp(speek(&stack),tok)>=0)
                        convExp[idx++]=spop(&stack);
                    spush(&stack,tok);
                    break;    
            }
        }
    }
    while(!SisEmpty(&stack))
        convExp[idx++]=spop(&stack);
    strcpy(exp,convExp);
    free(convExp);
}


int main(void)
{
	char expr[100];
	FILE* fp = fopen("in.txt", "r");
	fgets(expr, sizeof(expr), fp);
	ConvToRPNExp(expr);
	printf("%s\n", expr);

	fclose(fp);
	return 0;
}