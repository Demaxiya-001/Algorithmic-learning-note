#include <stdio.h>  
#include <stdlib.h>   
#include <string.h>
struct stack_share
{
    int a[40];
    int top1;
    int top2;
};
typedef struct stack_share *p;
int in(p p,int choose,int c){
    if (p->top1==p->top2-1){
        return 0;
    }
    if (choose==1){
        p->a[p->top1+1]=c;
        p->top1++;
        return 1;
    }
    if (choose==2){
        p->a[p->top2-1]=c;
        p->top2--;
        return 1;
    }
}
int out(p p,int choose){
    if (p->top1==-1 || p->top2-1==10){
        return 0;
    }
    if (choose==1){
        int c=p->a[p->top1];
        p->top1--;
        return c;
    }
    if (choose==2){
        int c=p->a[p->top2];
        p->top2++;
        return c;
    }
}
int main(){
    p t=(p)malloc(sizeof(struct stack_share));
    t->top1=-1;t->top2=10;
    int u=in(t,1,440);
    int y=out(t,1);
}