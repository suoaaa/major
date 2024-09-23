//设A、B是两个单链表，其中元素递增有序。
//设计一个算法从A、B中的公共元素产生单链表C，要求不破坏A、B的结点
#include "head.h"
LinkList getSameNode(LinkList list1,LinkList list2){
    LinkList list = (LinkList) malloc(sizeof(LinkList));
    LNode *p=list1->next, *q=list2->next, *r=list;
    while(p&&q){
        if(p->data==q->data){
            r->next=(LNode *) malloc(sizeof(LNode));
            r=r->next;
            r->data=p->data;
            p=p->next;
            q=q->next;
        }else{
            if(p->data > q->data) q = q->next;
            else p = p->next;
        }
    }
    r->next=NULL;
    return list;
}
int main(){
    List list1={{1,2,3,5,6,7,8},7};
    List list2={{1,3,4,6,7,9,10},7};

    LinkList l1=CreatList(list1);
    LinkList l2=CreatList(list2);

    PrintList(l1);
    PrintList(l2);

  	
    PrintList(getSameNode(l1,l2));
}