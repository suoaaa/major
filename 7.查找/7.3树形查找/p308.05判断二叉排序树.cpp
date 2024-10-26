/*试编写一个算法，判断给定的二叉树是否是二叉排序树*/
#include "head.h"
#include <iostream>
using namespace std;
/*左孩子<结点<右孩子*/
bool isBinarySortTree(BiTree T){
    if(!T) return true;
    bool flag1,flag2;
    if(T->lchild) flag1 = T->val < T->lchild->val;
    if(T->rchild) flag2 = T->val > T->rchild->val;
    return flag1 && flag2 && isBinarySortTree(T->lchild) && isBinarySortTree(T->rchild);
}
