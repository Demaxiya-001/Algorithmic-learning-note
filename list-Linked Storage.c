#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
struct listnode
{
    int data_space;
    struct listnode *next;//next 是这个指针变量的名称
};
typedef struct listnode *listpointer;
listpointer creat(int *a,int len){
    listpointer head=(listpointer)malloc(sizeof(struct listnode));
    head->data_space=a[0];
    int c=1;
    for (int i = 0; i < len-1; i++)
    {
        listpointer p=(listpointer)malloc(sizeof(struct listnode));
        p->next=head->next;
        head->next=p;
        p->data_space=a[c];
        c=c+1;
    }
    printf("\n");
    return head;
}
int find_node(listpointer p,int a){
    int c=1;
    for(int i=0;p!=NULL;i++){
        if (p->data_space==a){
        return c;
        }
        c=c+1;p=p->next;
    };
    return 0;
}
int insert_node(listpointer p,int a){
    listpointer e=(listpointer)malloc(sizeof(struct listnode));
    e->data_space=a;e->next=p->next;p->next=e;
    return 1;
}
int del(listpointer p,int a){
    listpointer e;
    for (int i = 0; p->next!=NULL; i++)
    {
        if (p->next->data_space==a){
            e=p->next;p->next=p->next->next;
            free(e);
            return 1;
            }
        p=p->next;
    }
    return 0;
    }
int clear_all(listpointer p){
    listpointer q;
    for (int i = 0; p!=NULL ; i++)
    {
        q=p->next;
        free(p);
        p=q;
    }
    return 0;
}
int main(){
    int a[]={1,2,3,4,5};listpointer head=creat(a,5);//创建链表
    clear_all(head);
    return 0;
}