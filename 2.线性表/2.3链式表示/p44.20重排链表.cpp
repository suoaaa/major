//线性表用带头结点的单链表存储为L=（a_1,a_2,a_3.......）
//设计一个空间复杂度为O（1）的算法，重新排列L中的各个结点，得到L'=（a_1,a_n,a_2......）
#include "head.h"
void reLine(LinkList list){
    LNode *p=list->next, *q=list->next, *r=list->next, *s;
    while(q!=NULL && q->next!=NULL){
        p=p->next;
        q=q->next->next;
    }
    q=p->next;
    p->next=NULL;
    p=NULL;
    while(q!=NULL){
        r=q->next;
        q->next=p;
        p=q;
        q=r;
    }
    PrintList(p);
    q=p;
    p=list->next;
    while(q!=NULL){
        r=p->next;
        p->next=q;
        p=p->next;
        q=r;
    }
}
int main(){
    List list={{7,4,5,2,1,1},5};
    LinkList l=CreatList(list);
    PrintList(l);
    reLine(l);
    PrintList(l);
    return 0;
}
