#include <stdio.h>  
#include <stdlib.h>   
#include <string.h>
struct stack
{
    int data[40];
    int top;
};
typedef struct stack* s;
int in(s p,int a){
    if (p->top==9){
        return 0;
    }
    p->data[p->top+1]=a;
    p->top+=1;
    return 1;
}
int out(s p){
    int c=p->data[p->top];
    p->top--;
    return c;
}
int main(){
    s p=(s)malloc(sizeof(struct stack));
    p->top=-1;//初始化
    in(p,3);
    int c=out(p);
}
