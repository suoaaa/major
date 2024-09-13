//在带头结点的单链表L中删除所有值为x的结点并释放空间（假设值为x的结点不唯一）
#include "head.h"
void deleteNodeByData(LinkList list,int x){
    LNode *p=list;
    LNode *q=p->next;
	while(q!=NULL){
		if(q->data==x){
            p->next=q->next;
            delete(q);
            q=p->next;
        }else{
            p=p->next;
            q=p->next;
        }
    }
}
int main(){
    List list={{1,2,3,4,5,6,7,4,3,1},10};
    LinkList l=CreatList(list);
    PrintList(l);
   deleteNodeByData(l,2);
    PrintList(l);
}