//L为带头节点的非循环双链表L，每个节点中除有pre、data、next域外，还有一个访问频度域freq，其值初始化为0
//编写函数Local(L,x),返回找到节点的地址，类型指针型
//每当在链表中进行一次Local运算，令值为x的节点中freq域的值增1
//并使此链表中的节点保持按照访问频度递减的顺序排列，且最近访问的节点排在频度相同的结点之前
#include "head.h"
DLinkList freqSearch(DLinkList L, int x){
    DLNode *p = L->next;
    while(p != L && p !=NULL){
        if(p->data == x){
            p->freq ++;
            while(p->prior->freq <= p->freq){
                DLNode *q = p->prior;
                q->prior->next = p;
                p->next->prior = q;
                p->prior=q->prior;
                q->next=p->next;
                p->next=q;
                q->prior=p;
            }
            return p;
        }
        p=p->next;
    }
    return NULL;
}
int main(){
    List list={{1,2,3,4,5,6,7},7};
    DLinkList l=CreatDList(list);
    PrintDList(l);
    freqSearch(l,2);
    PrintDList(l);
    freqSearch(l,3);
    PrintDList(l);
    freqSearch(l,2);
    PrintDList(l);
}