//在一个带头结点的单链表中，元素无序，删除所有介于给定两个值之间的元素。
#include "head.h"
void deleteBetween(LinkList list,int a,int b){
    if(!list||!list->next) return ;
    LNode *p=list;
    LNode *q=p->next;
    while(q){
        if(a<q->data&&b>q->data){
            p->next=q->next;
            delete(q);
            q=p->next;
        }else {
            p=q;
            q=q->next;
       }
       
    }
}
int main(){
    List list={{7,4,4,5,3,2,1},7};
    LinkList l=CreatList(list);
    PrintList(l);
  	deleteBetween(l,3,6);
    PrintList(l);
}