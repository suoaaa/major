/*二叉树采用二叉链表存储，设计一个算法，求先序遍历中第K个节点的值（0<k<=结点个数）*/
#include "head.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
/**/
int Pre_Node_k(BiTree T,int k,int i=1){
    if(T==NULL) return -1;
    if(i==k) return T->val;
    int ret=Pre_Node_k(T->lchild,k,i*2);
    if(ret!=-1) return ret;
    else return Pre_Node_k(T->rchild,k,i*2+1);
}
int main(){
    int val[31]={0};
    for(int i=0;i<31;i++){
        val[i]=i+1;
    }
    BiTree T;
    CreateBiTree(T,val,31,1);
    SequenceOrder(T);
    cout<<Pre_Node_k(T,12);
}