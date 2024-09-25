//线性表用带头结点的单链表存储为L=（a_1,a_2,a_3.......）
//设计一个空间复杂度为O（1）的算法，重新排列L中的各个结点，得到L'=（a_1,a_n,a_2......）
#include "head.h"

void reLine(LinkList h){
    LNode * p, *q, *r, *s;
    p=q=h;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
        if(q->next!=NULL) q=q->next;
    }
    q=p->next;
    p->next=NULL;
    while(q!=NULL){
        r=q->next;
        q->next=p->next;
        p->next=q;
        q=r;
    }
    s=h->next;
    q=p->next;
    p->next=NULL;
    while(q!=NULL){
        r=q->next;
        q->next=s->next;
        s->next=q;
        s=q->next;
        q=r;
    }


}
int main(){
    List list={{7,4,5,2,1,1},5};
    LNode *l=CreatList(list);
    PrintList(l);
    reLine(l);
    PrintList(l);
    return 0;
}
