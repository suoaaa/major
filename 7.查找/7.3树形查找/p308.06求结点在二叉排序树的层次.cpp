/*设计一个算法，求出指定结点在给定二叉排序树中的层次*/
#include "head.h"
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
/*使用递归算法，参数传入当前结点层次，本结点查找失败，层次加一进入下一层继续递归*/
int level(BiTree T,int key,int d=1){
    if(T->val==key) return d;
    else {
        if(T->val > key) return level(T->rchild,key,d+1);
        else return level(T->lchild,key,d+1);
    }
}

int leve(BiTree T,Node *p){
    int n=0;
    Node* q=T;
    if(T)  while(q->val!=p->val){
        if(q->val > p->val) q=q->lchild;
        else q=q->rchild;
        n++;
    }
    return n;
}
