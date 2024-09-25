//长度为n（偶数）的不带头结点的单链表，结点值大于0，求最大孪生和
//孪生和为一个节点与其孪生节点值之和
//对于第i个结点（从0开始），其孪生节点为第n-i-1个结点
#include "head.h"
int twinAdd(LinkList list){
    int n = GetLength(list)+1;
    int ret = 0;
    int nums[n/2] = {0};
    LNode *p =list;
    for(int i=0; i < n/2 ; i++){
        nums[i] = p->data;
        p= p->next;

    }
    for(int i=n/2-1; i >= 0; i--){
        nums[i] += p->data;
        ret = ret > nums[i] ? ret : nums [i];
        p= p->next;
    }
    return ret;
}
int main(){
    List list={{3,2,3,5,5,6,7,8,9},9};
    LinkList l=CreatList(list);
    PrintList(l);
    int n =twinAdd(l);
    printf("%d\n",n);
}