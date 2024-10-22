/*以孩子兄弟表示法为存储结构，请设计递归算法求树的深度*/
#include "head.h"
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
/*对于一个树的深度，等于左子树和右子树的深度的最大值
对于一个结点的左孩子，为二叉链表法的左孩子
对于右孩子，为其兄弟结点
递归公式：h（n）=max（h(n-1)左+1，h(n-1)右）*/
//          1
//      2         3
//    4    5   6     7
//                     8
//深度为3
int max(int a,int b){if(a>b) return a;else return b;}
int getDepth(BiTree t){
    if(t==NULL) return 0;
    else return max(getDepth(t->lchild)+1,getDepth(t->rchild));
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
    cout<<getDepth(root);
}
