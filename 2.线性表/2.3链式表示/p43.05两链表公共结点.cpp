//找到两个链表的公共结点
//两个链表若有公共结点，则后半部分是相同的
//获取两个链表的长度，然后移动长链表到与短链表等长
//一起遍历，第一个相同结点及之后结点就是共同结点
#include "head.h"
LNode* getPublic(LinkList list1,LinkList list2){
    int m=GetLength(list1),n=GetLength(list2);
    if(m<=0||n<=0) return NULL;
    LNode *p,*q;
    if(m>=n) {
        p=list1;
        q=list2;
    } else{
        p=list2;
        q=list1;
    }
    for(int i=abs(m-n);i>0;i++){
        p=p->next;
    }
    while(p!=q&&q&&p){
        p=p->next;
        q=q->next;
    }
    return p;
}




int main(){
    List list1={{7,4,4,5,5,2,1},7};
    List list2={{7,3},2};

    LinkList l1=CreatList(list1);
    LinkList l2=CreatList(list2);
    LNode *p=l1,*q=l2;
    p=p->next;q=q->next;
    p=p->next;q=q->next;
    q->next=p->next;
    PrintList(l1);
    PrintList(l2);

  	p=getPublic(l1,l2);
    PrintList(p);
    return 0;
}