/*编写一个递归算法，在一棵具有n个结点的、随即建立起来的二叉排序树上查找第k小的元素，并返回指向该结点的指针
要求算法的平均时间复杂度为O（logn）。
二叉排序树的每个结点中除data、lchild、rchiled等数据成员外，增加一个count成员，保存以该结点为根的子树上的节点个数*/
#include "head.h"
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
/*对于根节点，左孩子的count为在以根节点构成的树中，根节点的值为第count+1位*/
//若无左孩子，count=0
//如果count+1=k，返回当前结点的值
//count+1>k在左子树寻找，否则在右子树寻找
//递归过程中，应当更新k的值，对于在左子树，k值不变，对于右子树k=k-count-1
Node* search_small(BiTree T,int k){
    if(k<1 || k>T->count) return NULL;
    int n=1;
    if(T->lchild) n=T->lchild->count+1;
    if(n==k) return T;
    if(n<k) return search_small(T->rchild,k-n);
    else return search_small(T->lchild,k);
}
