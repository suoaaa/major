//已知两个链表A和B分别表示两个集合, 其元素递增排列。
//编制函数, 求A与B的交集, 并存放于A链表中
#include "head.h"
void getUnite(LinkList listA,LinkList listB){
    LNode *p = listA->next, *q = listB->next, *r=listA;
    while(p && q){
        if(p->data==q->data){
            r=r->next;
            p=p->next;
            q=q->next;
        }else{
            if(p->data < q->data){
                r->next = p->next;
                delete(p);
                p=r->next;
            }else{
                q=q->next;
            }
        }
    }
}
int main(){
    List list1={{1,2,2,4,5,6,9},7};
    List list2={{3,5,7,9},4};

    LinkList l1=CreatList(list1);
    LinkList l2=CreatList(list2);

    PrintList(l1);
    PrintList(l2);

  	getUnite(l1,l2);
    PrintList(l1);
}