//设有两个栈s1、s2都采用顺序栈方式, 并共享一个存储区[0, …, maxsize - 1]
//为了尽量利用空间, 减少溢出的可能, 可采用栈顶相向、迎面增长的存储方式。
//试设计s1,s2有关入栈和出栈的操作算法
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct stack{
    int data[MAX];
    int top[2];
}stack;

void initStack(stack &s){
    s.top[0]=-1;
    s.top[1]=MAX;
}
int push(stack &s,int top,int elem){
    if(s.top[1]-s.top[0]==1) return 0;//栈满
    switch (top)
    {
    case 0:     s.data[++s.top[top]]=elem;  return 1;
    case 1:     s.data[--s.top[top]]=elem;  return 1;
    default:    return 0;                      //参数错误
    }
}
int pop(stack &s,int i){
    switch (i)
    {
    case 0: 
        if(s.top[0]==-1) return 0;//栈空
        return s.data[s.top[0]--];
    case 1:
        if(s.top[1]==MAX) return 0;
        return s.data[s.top[1]++];    
    default:return 0;
    }
}
int main(){
    stack s;
    initStack(s);
    int i=0;
    for(i=0;i<50;i++){
        push(s,0,i);
        push(s,1,i);
    }
    for(int i=0;i<100;i++){
        printf("%d ",s.data[i]);
    }
    return 0;
}