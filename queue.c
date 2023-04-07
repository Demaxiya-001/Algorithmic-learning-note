#include <stdio.h>  
#include <stdlib.h>   
#include <string.h>
struct queue
{
    int a[40];
    int head;
    int end;
};
typedef struct queue* p;
int in(p c,int r){
    c->a[c->end]=r;
    c->end++;
};
int len(p t){
    int q=(t->end-t->head+10)%10;
    return q;
};
int out(p c){
    int q=c->a[c->head];
    c->head++;
    return q;
}
int main(){
    p t=(p)malloc(sizeof(struct queue));
    t->head=0;t->end=0;
    in(t,2345);
    int y=len(t);
}
