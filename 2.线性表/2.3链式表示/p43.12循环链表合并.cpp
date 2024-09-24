//有两个循环单链表, 链表头指针分别为h1和h2
//编写一个函数将链表h2链接到链表h1之后, 要求链接后的链表仍保持循环链表形式
#include "head.h"
LinkList merge(LinkList h1, LinkList h2){
    LNode *p=h1, *q=h2;
    while(p->next != h1){
        p = p->next;
    }
    while(q->next != h2){
        q = q->next;
    }
    p->next = h2;
    q->next = h1;

    return h1;
}
int main(){
    List list={{7,4,5,4,5,4,7},7};
    LinkList l1=CreatCirList(list);
    LinkList l2=CreatCirList(list);
    
    PrintList(l1);
  	PrintList(merge(l1,l2));

}