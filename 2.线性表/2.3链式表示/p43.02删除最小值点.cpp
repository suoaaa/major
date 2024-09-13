//删除链表中一个唯一的最小值
#include "head.h"
void deleteMin(LinkList l){
    if(l==NULL){
        return ;
    } else if(l->next==NULL) {
        return ;
    }
    LNode *p=l;
    LNode *q=l->next;
    LNode *pre;
    int min=q->data+1;
    while(q!=NULL){
        if(q->data<min){
			pre=p;
            //printf("%d\n",q->data);
        }
        p=p->next;
        q=p->next;
    }
    q=pre->next;
    pre->next=q->next;
    delete(q);
}
int main(){
    List list={{7,4,6,5,3,2,1},7};
    LinkList l=CreatList(list);
    PrintList(l);
  	deleteMin(l);
    PrintList(l);
}