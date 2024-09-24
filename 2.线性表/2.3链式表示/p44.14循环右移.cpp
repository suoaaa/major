//将n个整数存放到不带头结点的单链表L中，设计算法将L中保存的序列循环右移K位（0<k<n）
#include "head.h"
void moveRight(LinkList &L, int k){
    LNode *p=L, *q=L;
    int n = GetLength(L)+1; //GetLength是带头节点的链表的长度，要加1
    for(int i=0;i<n-k-1%n;i++){   //循环，查找第k-1个位置
        p=p->next;
    }
    //跳出循环后，p/r所指的位置为新链表第一个节点的前一个节点
    q=p;
    while(p->next!=NULL){//使p指向原链表的尾部
        p=p->next;
    }
    //链接p(旧链表尾)、q(旧链表头)
    p->next=L;
    //L指向新链表头
    L=q->next;
    //新链表头尾断开
    q->next=NULL;
}
//可以先循环遍历链表找到尾部结点使得链表成环再分段
int main(){
    List list={{7,4,5,2,1},5};
    LinkList l=CreatList(list);
    PrintList(l);
  	moveRight(l,2);
    PrintList(l);
    return 0;
}
