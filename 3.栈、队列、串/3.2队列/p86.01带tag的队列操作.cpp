//若希望循环队列中的元素都能得到利用, 则需设置一个标志域tag, 并以tag的值为0
//或1来区分队头指针 front和队尾指针rear相同时的队列状态是“空”还是“满”。试
//编写与此结构相应的入队和出队算法
#include <stdio.h>
#define MAX 5
typedef struct queue{
    int data[MAX];
    int front,rear,tag;
}queue;
int dequeue(queue &q){
    if(q.front==q.rear&&q.tag==0)   return -1;
    q.tag=0;
    int ret=q.data[q.front];
    q.front=(q.front+1)%MAX;
    return ret;
}
void enqueue(queue &q,int elem){
    if(q.front==q.rear&&q.tag==1) return ;
    q.tag=1;
    q.data[q.rear]=elem;
    q.rear=(q.rear+1)%MAX;
}
void initqueue(queue &q){
    q.front=0;
    q.rear=0;
    q.tag=0;
};
int main()
{
    queue q;
	initqueue(q);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    printf("%d",dequeue(q));
    printf("%d",dequeue(q));
    printf("%d",dequeue(q));
    printf("%d",dequeue(q));
    printf("%d",dequeue(q));
    printf("%d",dequeue(q));
    printf("%d",dequeue(q));
	return 0;
}
