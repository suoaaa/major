//递增有序链表中删除重复元素
#include "head.h"
void deleteEqual(LinkList list){
    if(!list||!list->next) return ;
    LNode *p=list->next;
    LNode *q=list->next;
    int data;
    while(p->next){
        data=q->data;
        p=p->next;
        if(p->data==data){
            q->next=p->next;
        }
        delete(p);
        q=q->next;
    }
}

int main(){
    List list={{7,4,4,5,5,2,1},7};
    LinkList l=CreatList(list);
    PrintList(l);
  	deleteEqual(l);
    PrintList(l);
}