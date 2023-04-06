#include <stdio.h>  
#include <stdlib.h>   
#include <string.h> 
struct d_node
{
    int data;
    struct d_node *before;
    struct d_node *after;
};
typedef struct d_node *p;
p creat(int *a,int len){
    p hou_node;p qian_node;p head;
    head=(p)malloc(sizeof(struct d_node));head->data=a[0];
    qian_node=head;//第一个前面node是头结点
    for (int i = 1; i < len; i++)
    {
        hou_node=(p)malloc(sizeof(struct d_node));hou_node->data=a[i];//赋值，创建新点
        qian_node->after=hou_node;hou_node->before=qian_node;
        qian_node=hou_node;
    }
    head->before=hou_node;hou_node->after=head;//最后一个节点和第一个节点连起来
    p z=head;
    return z;
} 
int main(){
    int a[]={1,2,3,54,6,78,3,7};
    p e=creat(a,8);
    printf("%d",e->after->data);
    return 0;
}
