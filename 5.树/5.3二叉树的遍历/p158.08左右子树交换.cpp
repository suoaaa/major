/*二叉树采用二叉链表存储，将树中的所有节点的左右子树进行交换*/
#include "head.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
/*层序遍历并进行交换*/
void swapNode(Node *p){
    Node *t=p->lchild;
    p->lchild=p->rchild;
    p->rchild=t;
}
void swapTree(BiTree &T){
    queue<Node*> q;
    q.push(T);
    Node *p;
    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p==NULL) continue;
        swapNode(p);
        q.push(p->lchild);
        q.push(p->rchild);
    }
}
int main(){
    int val[31]={0};
    for(int i=0;i<31;i++){
        val[i]=i+1;
    }
    BiTree T;
    CreateBiTree(T,val,31,1);
    SequenceOrder(T);
    swapTree(T);
    SequenceOrder(T);

}