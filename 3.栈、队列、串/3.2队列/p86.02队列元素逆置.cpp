//Q是一个队列, S是一个空栈, 实现将队列中的元素逆置的算法
#include <stdio.h>
#define MAX 10
typedef struct queue{
    int data[MAX];
    int front,rear;
}queue;
typedef struct stack{
    int data[MAX];
    int top;
}stack;
void init(queue &q){
    q.rear=0;
    q.front=0;
}
void init(stack &s){
    s.top=0;
}
void push(stack &s,int elem){
    if(s.top>=0&&s.top<MAX)
    s.data[s.top++]=elem;
}
int pop(stack &s){
    if(s.top>0&&s.top<=MAX) 
    return s.data[--s.top];
    else return -1;
}
void enqueue(queue &q,int elem){
    if((q.rear+1)%MAX==q.front) return ;
    q.data[q.rear]=elem;
    q.rear=(q.rear+1)%MAX;
}
int dequeue(queue &q){
    if(q.rear==q.front) return -1;
    int ret=q.data[q.front];
    q.front=(q.front+1)%MAX;
    return ret;
}

void reserve(queue &q,stack &s){
    while(q.front!=q.rear){
        push(s,dequeue(q));
    }
    while(s.top>0){
        enqueue(q,pop(s));
    }
}

int main()
{
    stack s;
    queue q;
    init(s);
    init(q);
    for (int i = 1; i < MAX; i++) {
        enqueue(q,i);
    }for(int i=0;i<MAX;i++){
        printf("%d ",q.data[i]);
    }
    printf("\n");

    reserve(q, s);
    while(q.front!=q.rear){
        printf("%d ",dequeue(q));
    }
    return 0;
}