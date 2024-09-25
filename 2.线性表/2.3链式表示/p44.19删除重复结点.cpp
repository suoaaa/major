//单链表存储m个整数，且|data|<=n。
//设计一个时间复杂度尽可能低的算法，对于链表中data的绝对值相同的结点
//仅保留第一次出现的结点而删除其余绝对值相等的结点
#include "head.h"
void deleteEqualAbs(LinkList list,int n){
    int *num=(int *) malloc(sizeof(int)*(n+1));
    for(int i=0;i<n+1;i++){
        *(num+i)=0;
    }
    LNode *p=list->next, *q=list;
    int d=0;
    while(q->next!=NULL){
        d=p->data > 0 ?p->data : -p->data;
        if(*(num+d)==0){
            *(num+d)=1;
             q=q->next;
        }else {
            q->next=p->next;
            free(p);
        }
        p=q->next;
    }
    free(num);
}
int main(){
    List list={{7,4,-4,2,4},5};
    LinkList l=CreatList(list);
    PrintList(l);
    deleteEqualAbs(l,10);
    PrintList(l);
    return 0;
}
