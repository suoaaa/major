//用带头结点的单链表保存单词，当两个单词有相同后缀时，可以共享相同的后缀存储空间
//设计一个时间上尽可能搞笑的算法，找到两个链表共同后缀的起始位置
//见p43.05

//两个链表若有公共结点，则后半部分是相同的
//获取两个链表的长度，然后移动长链表到与短链表等长
//一起遍历，第一个相同结点及之后结点就是共同结点
#include "head.h"
LNode* getPublic_(LinkList list1,LinkList list2){
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