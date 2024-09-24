//设计一个算法用于判断带头结点的循环双链表是否对称
#include "head.h"
bool isSymmetry(DLinkList list){
    if(!list) return false;
    DLNode *p=list->next, *q=list->prior;
    while(p->next != q && p!=q){
        if(p->data != q->data) return false;
        p=p->next;
        q=q->prior;
    }
    if(p->data == q->data) return true;
    else    return false;
}
int main(){
    List list={{7,4,5,4,5,4,7},7};
    DLinkList l=CreatDList(list);
    PrintDList(l);
  	if(isSymmetry(l)) printf("yes");
    else printf("error");
}