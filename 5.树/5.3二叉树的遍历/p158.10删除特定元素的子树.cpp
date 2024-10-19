/*链表以二叉链表存储，设计一个算法，删除树中所有以元素值为x的结点为根的子树*/
#include "head.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
/*遍历查找元素x，删除子树*/
void deleteTree(BiTree &T);//删除以T为根的树
void delete_X_Intree(BiTree &T,int x){
    if(T->val==x) return deleteTree(T);
    queue<Node*> q;
    q.push(T);
    Node *p;
    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p->lchild) if(p->lchild->val==x){
            deleteTree(p->lchild);
            p->lchild=NULL;
        } else q.push(p->lchild);
        if(p->rchild) if(p->rchild->val==x){
            deleteTree(p->rchild);
            p->rchild=NULL;
        } else q.push(p->rchild);
    }
}
void deleteTree(BiTree &T){
    queue<Node*> q;
    q.push(T);
    Node *p;
    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p->lchild) q.push(p->lchild);
        if(p->rchild) q.push(p->rchild);
        delete(p);
    }
    T=NULL;
}
int main(){
    int val[31]={0};
    for(int i=0;i<31;i++){
        val[i]=i+1;
    }
    // val[10]=9;
    BiTree T;
    CreateBiTree(T,val,31,1);
    SequenceOrder(T);
    delete_X_Intree(T,9);
    SequenceOrder(T);

}