#include <stdio.h>
#include <string.h> 
#define max 1000
typedef struct 
{
    int date;int cur;
}component,bottle [max];
int first_sue(bottle e){
    for (int i = 0; i < 125; i++)
    {
        e[i].cur=i+1;
    }
    e[124].cur=0;
    return 1;
}
int normal_add(bottle e,int c){
    int o=e[0].cur;e[o].date=c;//放入数据
    int a=124;int d;
    for (int i = 0; a!=0 ; i++)
    {
        d=a;a=e[a].cur;
    }
    e[0].cur=e[o].cur;
    e[d].cur=o;
    e[o].cur=0;
    e[124].cur=o;
    return 1;
}
int del_node(bottle e,int a){
    int b=124;
    for (int i = 0; e[b].cur!=a ; i++)
    {
        b=e[b].cur;
    }
    e[b].cur=e[a].cur;//前一个有元素的断掉
    int c=e[0].cur;e[0].cur=a;e[a].cur=c;
    return 1;
}
int main(){
    bottle r;
    first_sue(r);
    normal_add(r,10086);
    del_node(r,1);
    for (int i = 0; i < 125; i++) {
    printf("%d ", r[i].date);
    }
    return 0;
}
/*
不要在函数中新建数组，外面操作起来很麻烦
新建数组在函数外面，函数参数直接传函数名就行了
*/
