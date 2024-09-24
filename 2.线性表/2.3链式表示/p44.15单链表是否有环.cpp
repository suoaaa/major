//单链表是否有环是指单链表最后一个结点的指针指向了某个节点，编写算法判断单链表是否有环
#include "head.h"
bool existLoop(LinkList list){
    LNode *p=list, *q=list;
    while(q != NULL && q->next != NULL){
        p=p->next;
        q=q->next->next;
        if(p == q) return true;
    }
    return false;
}