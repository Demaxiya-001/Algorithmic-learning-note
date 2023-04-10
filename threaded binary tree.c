#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *Lchild;
    bool Ltag;
    struct node *Rchild;
    bool Rtag;
};//链树成员
typedef struct node* p;
p before;
struct duilie
{
    p a[100];
    int head;int end;
};
typedef struct duilie *duilie_p;
int in(duilie_p e,p w){
    e->a[e->head]=w;
    e->head++;
    return 0;
};
p out(duilie_p e){
    p q=e->a[e->end];e->end++;
    return q;
}
int bianli(p o){
    if (!o) {
        return 0;
    }
    if (!o->Lchild)
    {
        o->Ltag=1;
    }
    else{
        o->Ltag=0;
    }
    if (!o->Rchild)
    {
        o->Rtag=1;
    }
    else{
        o->Rtag=0;
    }
    bianli(o->Lchild);
    bianli(o->Rchild);
    return 0;
}
int xiansuo(p o){
    if (!o) {
        return 0;
    }
    xiansuo(o->Lchild);
    if (!o->Lchild)
    {
        o->Lchild=before;
    }
    if (!before->Rchild)
    {
        before->Rchild=o;
    }
    before=o;
    xiansuo(o->Rchild);
    return 0;
}
int main(){
    int a[]={1,2,3,4,5,6,7,8,9,10};duilie_p e=(duilie_p)malloc(sizeof(struct duilie));e->end=0;e->head=0;//大队列e，放指向node的指针
    p t=(p)malloc(sizeof(struct node));t->data=a[0];in(e,t);int i=1;
    while (1)
    {
        p p0=out(e);
        p p1=(p)malloc(sizeof(struct node));p1->data=a[i];i++;p0->Lchild=p1;in(e,p1);
        if (i==10)
        {
            break;
        }
        p p2=(p)malloc(sizeof(struct node));
        p2->data=a[i];i++;p0->Rchild=p2;in(e,p2);
    }
    bianli(t);
    before=t;
    xiansuo(t);
    p began=t->Lchild->Lchild->Lchild;
    while (1)
    {
        printf("%d\n",began->data);
        if (began->Rchild)
        {
            began=began->Rchild;
        }
        if(!began->Rchild){
            break;
        }
    }   
    return 0;
}