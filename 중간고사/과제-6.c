#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct poly{
    float coef;
    int expon;
}Poly;

Poly terms[MAX_SIZE];
int avail = 0;

char compare(int num1,int num2){
    if(num1>num2)
        return '>';
    else if(num1 < num2)
        return '<';
    else 
        return '=';
}

void poly_add(int as,int ae,int bs,int be,int* cs,int* ce){
    float tempcoef;
    *cs = avail;
    while(as<=ae&&bs<=be){
        switch(compare(terms[as].expon,terms[bs].expon)){
            case '>':
                terms[avail].coef = terms[as].coef;
                terms[avail].expon = terms[as].expon;
                avail++;
                as++;
                break;
            case '=':
                tempcoef = terms[as].coef + terms[bs].coef;
                if(tempcoef){
                    terms[avail].coef = tempcoef;
                    terms[avail].expon = terms[as].expon;
                    avail++;
                }
                as++;
                bs++;
                break;
            case '<':
                terms[avail].coef = terms[bs].coef;
                terms[avail].expon = terms[bs].expon;
                avail++;
                bs++;
                break;
        }
    }
    for(;as<=ae;as++){
        terms[avail].coef = terms[as].coef;
        terms[avail].expon = terms[as].expon;
        avail++;
    }
    for(;bs<=be;bs++){
        terms[avail].coef = terms[bs].coef;
        terms[avail].expon = terms[bs].expon;
        avail++;
    }

    *ce = avail;
}

void print_poly(int cs,int ce){
    for(int i=cs;i<ce;i++){
        printf("%.lf %d ",terms[i].coef,terms[i].expon);
    }
}

void f1(){
    FILE* fp = fopen("a.txt","r");
    FILE* fp1 = fopen("b.txt","r");
    int a_num;
    int b_num;
    int cs,ce;
    int i,j;
    int x,y;
    fscanf(fp,"%d",&a_num);
    fscanf(fp1,"%d",&b_num);

    for(i=0;i<a_num;i++){
        fscanf(fp,"%f %d",&terms[avail].coef,&terms[avail].expon);
        avail++;
    }
    for(;i<a_num+b_num;i++){
        fscanf(fp1,"%f %d",&terms[avail].coef,&terms[avail].expon);
        avail++;
    }

    poly_add(0,a_num-1,a_num,a_num+b_num-1,&cs,&ce);
    print_poly(cs,ce);
}

int main(void){
    f1();
    return 0;
}
