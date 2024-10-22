/*编程求以孩子兄弟表示法存储的森林的叶结点数*/
#include "head.h"
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
/*森林中的叶节点在二叉树中没有左孩子*/
//          1
//      2         3
//    4    5   6     7
//                       8
int getLeaf(BiTree t){
    if(t==NULL) return 0;
    if(t->lchild==NULL) return 1+getLeaf(t->rchild);
    else return getLeaf(t->lchild)+getLeaf(t->rchild);
}
int main(){
    BiTree root=new node();
    root->lchild=new node();
    root->rchild=new node();

    root->lchild->lchild=new node();
    root->lchild->rchild=new node();
    
    root->rchild->lchild=new node();
    root->rchild->rchild=new node();
    root->rchild->rchild->rchild=new node();
    cout<<getLeaf(root);
}
