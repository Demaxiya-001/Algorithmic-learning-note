#include <stdio.h>  
#include <stdlib.h>   
#include <string.h>
struct node
{
    int data;
    struct node* next;
};
typedef struct node* p;
struct point
{
    p head;
    p end;
    int count;
};
typedef struct point* e;
int add(e t,int a){
    p o=(p)malloc(sizeof(struct node));
    o->next=t->end;
    o->data=a;
    t->end=o;
    if(t->count==0){
        t->head=o;
    }
    t->count++;
    return 1;
};
int out(e t){
    int a=t->head->data;
    p w=t->head->next;
    free(t->head);
    t->head=w;
    t->count--;
    return a;
}
int main(){
    e t=(e)malloc(sizeof(struct point));
    t->end=NULL;t->head=NULL;t->count=0;
    add(t,25241);
    out(t);
    return 0;
}