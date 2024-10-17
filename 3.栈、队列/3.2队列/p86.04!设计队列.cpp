/*请设计一个队列，要求满足：
1.初始时队列为空
2.入队时允许增加队列所占空间
3.出队后，出对元素所占用的空间可重复使用，即整个队列所占同的空间只增不减
4.入队操作和出队操作的时间复杂度始终保持为O(1)*/
#include <stdio.h>

#define MAX 50
#define ElemType int

typedef struct {
	int data[MAX];
	int length;
}List;

//定义队列结点
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode;

//定义链队列,带头结点和头尾指针的链表
typedef struct LinkQueue{
	ElemType data;
	struct LNode *front, *rear;
}LinkQueue;
//队列为空：头尾指针同指头结点
bool QueueEmpty(LinkQueue q){
    if(q.front==q.rear) return true;
    else return false;
}
//队列为满：尾指针指向结点的next指针为空
bool QueueFull(LinkQueue &q){
    if(q.rear->next==NULL) return true;
    else return false;
}

void initQueue(LinkQueue &q){
    q.front=new LNode;
    q.rear=q.front;
    q.rear->next=NULL;
}
//输出队列
void PrintList(LinkQueue q) {
    if(QueueEmpty(q)&&QueueFull(q)) return ;
	LNode *p=q.front->next;
    while(p!=q.rear){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}

void Enqueue(LinkQueue &q,int x){
    if(q.rear->next){
        q.rear=q.rear->next;
        q.rear->data=x;
    }else{
        LNode *p=new LNode;
        p->data=x;
        p->next=NULL;
        q.rear->next=p;
        q.rear=p;
    }
}

void Dequeue(LinkQueue &q,int &x){
    x=-1;
    if(QueueEmpty(q)) return ;
    if(q.front->next==q.rear) {
        x=q.rear->data;
        q.rear=q.front;
        return;
    }
    LNode *p=q.front->next;
    x=p->data;
    q.front->next=p->next;
    p->next=q.rear->next;
    q.rear->next=p;
}

int main(){
    LinkQueue q;
    initQueue(q);
    for(int i=0;i<10;i++){
        Enqueue(q,i);
    }
    PrintList(q);
    int n=0;
    for(int i=0;i<=10;i++){
        Dequeue(q,n);
        printf("%d ",n);
    }
}