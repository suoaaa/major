//给出二叉树自下而上、从右到左的层次遍历算法
#include <iostream>
#include <stack>
#include <queue>
#include "head.h"
using namespace std;
void back_sequence(BiTree T){
    Node *p;
    stack<Node*> s;
    queue<Node*> q;
    stack<int> s2;
    q.push(T);
    while(!q.empty()){
        p=q.front();
        q.pop();
        s.push(p);
        if(p->lchild !=NULL){
            q.push(p->lchild);
        }
        if(p->rchild != NULL){
            q.push(p->rchild);
        }
    }
    while(!s.empty()){
        p=s.top();
        s.pop();
        visit(p);
    }
}
int main(){
    int val[20]={0};
    for(int i=0;i<20;i++){
        val[i]=i+1;
    }
    BiTree T;
    CreateBiTree(T,val,20,1);
    InOrder(T);
    cout<<endl;
    back_sequence(T);
}