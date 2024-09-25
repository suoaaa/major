//一个带头结点的单链表，不改变链表的前提下，设计一个尽可能高效的算法，查找链表中倒数第k个位置上的结点
//若查找成功，算法输出该结点的data域的值，返回1；否则返回0
#include "head.h"
int countdownK(LinkList list, int k){
    LNode *p=list->next, *q=list->next;//新建两个指针，一个在前一个在后遍历整个链表，其中第二个在第一个后k个位置
    int i=0;
    for(i=0;i<k-1&&p!=NULL;i++){
        p=p->next;
    }
    if(i < k-1) return 0;
    while(p->next!=NULL){
        p=p->next;
        q=q->next;
    }
    printf("value:%d\n",q->data);
    return 1;
}
int main(){
    List list={{7,4,5,2,1},5};
    LinkList l=CreatList(list);
    PrintList(l);
    countdownK(l,3);
    PrintList(l);
    return 0;
}
