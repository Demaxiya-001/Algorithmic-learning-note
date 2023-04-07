#include <stdio.h>  
#include <stdlib.h>   
#include <string.h>
int find(char target[],int next[],int len){
    for (int i = 1; i < len; i++)//从第二个开始
    {
        int suan=i;
        int cur=next[suan-1];
        if (target[cur]==target[suan]){
            next[suan]=cur+1;
        }
        else{
            while (1)
            {
                if (target[cur]==target[suan]){
                        next[suan]=cur+1;
                        break;
                        }
                if(next[cur-1]==0){
                    if (target[suan]==target[0])
                    {
                        next[suan]=1;break;
                    }
                    else{
                        next[suan]=0;break;
                    }
                }
                cur=next[cur-1];
            }
        }
    }
    return 1;
}
int main(){
    char target[]="abab";int len=sizeof(target)-1;int next[4];next[0]=0;//初始化
    find(target,next,len);//next数组第一形态
    int o=len-1;
    for (int i = 0; i < len-1; i++)
    {
        next[o]=next[o-1];
        o--;
    }
    next[0]=-1;//next数组第二形态
    for (int i = 1; i < len; i++)
    {
        if (target[next[i]]==target[i])
        {
            next[i]=next[next[i]];
        }
    }//next已修改为nextval
    char big[]="abacabaeabab";
    int big_len=sizeof(big);
    int up=0;int down=0;
    while (1)
    {
        if(down==len){
            return down;
        }
        else{
            if(big[up]==target[down]){
                up++;down++;
            }
            if (big[up]!=target[down])
            {
                down=next[down];
                if (down==-1)
                {
                    up++;down=0;
                }
                
            }
            
        }

    }
    
    return 0;
}