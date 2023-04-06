#include <stdio.h>  
#include <stdlib.h>   
#include <string.h>
struct stack
{
    int data;
    struct stack * next;
};
struct top_node
{
    int count;
    struct stack *next;
};
typedef struct stack *p;
typedef struct top_node *t;
int in(t top,int a){
    p t=(p)malloc(sizeof(struct stack));
    t->data=a;
    t->next=top->next;
    top->next=t;
    top->count++;
    return 1;
}
int out(t top){
    if (top->count==0){
        return 0;
    }
    int a=top->next->data;
    p z=top->next;top->next=top->next->next;
    free(z);
    return a;
}
int main(){ 
    t top=(t)malloc(sizeof(struct top_node));
    top->count=0;top->next=NULL;
    in(top,454);
    int e=out(top);
    return 0;
}