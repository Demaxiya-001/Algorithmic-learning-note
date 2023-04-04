#include <stdio.h>
#include <string.h> 
#define MAXSIZE 20
typedef struct {
    int list[MAXSIZE];
    int length;
} list;
int insert_list(list *l,int site,int insert_object)
{
    char a[]="插入位置越界";char b[]="数组已满";char c[]="OK";
    if (site>l->length||site<0)
    {
        printf("%s\n", a);
        return 0;
    }
    if(l->length==MAXSIZE)
    {
        printf("%s\n", b);
        return 0;
    }
    if (site!=l->length){
        int z=l->length-site;
        for (int i = 0; i < z; i++)
        {
            l->list[l->length-i]=l->list[l->length-1-i];
        }
    }
    l->list[site]=insert_object;
    l->length++;
    printf("%s\n", c);
    return 1;
}
int del_list(list *l,int site){
    char a[]="删除位置越界";char e[]="删除成功";
    if (site>l->length-1||site<0)
    {
        printf("%s\n", a);
        return 0;
    }
    int b=site;
    for (int i = 0; i < l->length-site; i++)
    {
        l->list[b]=l->list[b+1];b++;
    }
    l->length--;
    printf("%s\n",e);
    return 1;
}
int query(list *l,int site){
    int a;a=l->list[site];
    return a;
}
int main(void){
    list l = {{1,2,3,4,5,6,7,8,9},9};
    int a= query(&l,2);
    printf("%d\n",a);
    printf("The updated list is: ");
    for (int i = 0; i < l.length; i++) {
        printf("%d ", l.list[i]);
    }
}
/*
#Attention
1、注意通过长度查看线性表满了没有，是不是空表
2、结束后长度要变化
*/
