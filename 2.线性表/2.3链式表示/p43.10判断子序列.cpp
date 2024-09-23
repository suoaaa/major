//两个整数序列A = a1,a2,a3…, an和B = b1, b2, b3, …, bn已经存入两个单链表中
//设计一个算法, 判断序列B是否是序列A的连续子序列
#include "head.h"
bool isSubsequence(LinkList list1,LinkList list2){
    int m=GetLength(list1),n=GetLength(list2);
    if(m<n||n<=0||m<0) return false;
    LNode *p=list1->next, *q=list2->next;
    bool ret=false;
    while(p->data !=q->data){
        p=p->next;
    }
    while(p && q){
        ret=true;
        if(p->data == q->data){
            p = p->next;
            q = q->next;
        }else{
            p=p->next;
            if(q!=list2->next) {
                ret =false;
                break;
            }
        }
    }
    ret = ret && (q==NULL);
    return ret;
}
int main(){
    List list1={{1,2,3,5,7,9,9},7};
    List list2={{3,5,7,9},4};

    LinkList l1=CreatList(list1);
    LinkList l2=CreatList(list2);

    PrintList(l1);
    PrintList(l2);

  	if(isSubsequence(l1,l2)) printf("1");
    else printf("2");
    
}