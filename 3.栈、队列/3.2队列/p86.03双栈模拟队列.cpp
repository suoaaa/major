//利用两个栈S1, S2来模拟一个队列, 已知栈的4个运算定义如下
//	Push(s, x);				//元素x入栈S
//	Pop(s, X);				//S出栈并将出栈的值赋给x
//	StackEmpty(s);			//判断栈是否为空
//	Stackoverflow(s);		//判断栈是否满

//	如何利用栈的运算来实现该队列的3个运算(形参由读者根据要求自己设计) ?
//	Enqueue					//将元素x入队
//	Dequeue					//出队,并将出队元素存储在ⅹ中
//	QueueEmpty				//判断队列是否为空
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX 5

typedef struct stack{
    int data[MAX];
    int top;
}stack;

void init(stack &s){
    s.top=0;
}
void Push(stack &s,int elem){
    if(s.top>=0&&s.top<MAX){
        s.data[s.top]=elem;
        s.top++;
    }
}
void Pop(stack &s,int &x){
    if(s.top>0&&s.top<=MAX) {
        s.top--;
        x=s.data[s.top];
    }
}
bool StackEmpty(stack &s){
    if(s.top==0) return true;
    else return false;
}
bool Stackoverflow(stack &s){
    if(s.top>=MAX) return true;
    else return false;
}

void Enqueue(stack &s1,stack &s2,int x){
    if(!Stackoverflow(s1)){
        Push(s1,x);
        return ;
    }
    if(Stackoverflow(s1)&&!StackEmpty(s2)) return ;
    int n=0;
    while(!StackEmpty(s1)){
        Pop(s1,n);
        Push(s2,n);
    }
    Push(s1,x);
}
bool QueueEmpty(stack s1,stack s2){
    if(StackEmpty(s1)&&StackEmpty(s2)) return true;
    else return false;
}
void Dequeue(stack &s1,stack &s2,int &x){
    if(QueueEmpty(s1,s2)){
        x=-1;
        return ;
    }
    if(!StackEmpty(s2)){
        Pop(s2,x);
        return ;
    }
    int n=0;
    while(!StackEmpty(s1)){
        Pop(s1,n);
        Push(s2,n);
    }
    Pop(s2,x);
}

int main(){
	stack S1, S2;
    init(S1);
    init(S2);
    for(int i=0;i<9;i++){
        Enqueue(S1, S2, i);
    }
	int x=0;
    for(int i=S1.top-1;i>=0;i--){
        printf("%d ",S1.data[i]);
    }printf("%\n");
    for(int i=S2.top-1;i>=0;i--){
        printf("%d ",S2.data[i]);
    }printf("%\n");
    while (!QueueEmpty(S1,S2))
    {
        Dequeue(S1,S2,x);
        printf("%d  ",x);
    }
	return 0;
}

