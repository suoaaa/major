//使用O（1）的空间复杂度将带头结点的链表反转
#include "head.h"
void reverse(LinkList l){
  LNode *p,*q;
   p=l->next;
   l->next=NULL;
   while(p!=NULL){
    q=p->next;
    p->next=l->next;
    l->next=p;
    p=q;
   }
}
int main(){
    List list={{7,4,6,5,3,2,1},7};
    LinkList l=CreatList(list);
    PrintList(l);
  	reverse(l);
    PrintList(l);
}