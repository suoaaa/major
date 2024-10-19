/*二叉树按照二叉链表形式存储，计算一颗给定二叉树的所有双分支结点的个数*/
#include "head.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
/*层序遍历记录个数*/
int DsonNodes(BiTree T){
    queue<Node *> q;
    Node *p;
    q.push(T);
    int num=0;
    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p->lchild&& p->rchild) {
            q.push(p->lchild);
            q.push(p->rchild);
            num++;
        }else {
            if(p->lchild)   q.push(p->lchild);
            if(p->rchild)   q.push(p->rchild);
        }
    }
    return num;
}

int main(){
    int val[31]={0};
    for(int i=0;i<31;i++){
        val[i]=i+1;
    }
    BiTree T;
    CreateBiTree(T,val,31,1);
    SequenceOrder(T);
    cout<<DsonNodes(T)<<endl;
    T->rchild->rchild->lchild->lchild=NULL;
    cout<<DsonNodes(T)<<endl;
}