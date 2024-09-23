//将C线性表的奇偶位置的元素分别放入两个链表中
#include "head.h"
void splitOddEven(LinkList list,LinkList &odd,LinkList &even){
    if(!list) return ;
    odd=(LinkList)malloc(sizeof(LinkList));
    even=(LinkList)malloc(sizeof(LinkList));
    LNode *p=odd, *q=even, *r=list->next;

    for(int i=0;i<GetLength(list)/2;i++){
        p->next=r;
        p=p->next;
        r=r->next;
        q->next=r;
        q=q->next;
        r=r->next;
    }
    if(GetLength(list)%2) {
        p->next=r;
        p=p->next;
    }
    p->next=NULL;
    q->next=NULL;
    list->next=NULL;
}
int main(){
    List list={{7,4,3,4,5,2,1},7};
    LinkList l=CreatList(list),odd,even;
    PrintList(l);
  	splitOddEven(l,odd,even);
    PrintList(odd);
    PrintList(even);
}