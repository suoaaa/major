/*将二叉树的叶节点按从左到右的顺序连城一个单链表，表头为head
二叉树按二叉链表方式存储，连接时用叶节点的右指针来存放单链表指针*/
#include "head.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
/*不论什么遍历方式，遍历，遇到叶节点就放到单链表后边*/
Node *pre,*head;
Node* leaftolink(BiTree T){
    if(T){
        leaftolink(T->lchild);
        if(T->lchild==NULL&&T->rchild==NULL)
            if(pre==NULL){
                head=T;
                pre=T;
            }else{
                pre->rchild=T;
                pre=T;
            }
        leaftolink(T->rchild);
        pre->rchild=NULL;
    }
    return head;
}
int main(){
    int val[31]={0};
    for(int i=0;i<31;i++){
        val[i]=i+1;
    }
    BiTree T;
    CreateBiTree(T,val,31,1);
    SequenceOrder(T);
    Node *p=leaftolink(T);
    while(p!=NULL){
        cout<<p->val<<" ";
        p=p->rchild;
    }
}