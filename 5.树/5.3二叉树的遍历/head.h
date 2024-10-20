#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
typedef struct node { //树的结点
    int val;
    node* lchild;
    node* rchild;
}Node, *BiTree;

void CreateBiTree(BiTree& T,int val[],int n,int i=1)
{
    if (i<=n&&i>0){
        T = new Node;
        T->val = val[i-1];
        T->lchild=NULL;
        T->rchild=NULL;
        CreateBiTree(T->lchild,val,n,2*i);
        CreateBiTree(T->rchild,val,n,2*i+1);
    }
}

void visit(Node* BiNode) {
    cout << BiNode->val << " ";
}

void InOrder(BiTree T){
    if (T != NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
void SequenceOrder(BiTree T){
    queue<Node *> q;
    Node *p;
    q.push(T);
    while(!q.empty()){
        p=q.front();
        q.pop();
        visit(p);
        if(p->lchild!=NULL) q.push(p->lchild);
        if(p->rchild!=NULL) q.push(p->rchild);
    }
    cout<<endl;
}