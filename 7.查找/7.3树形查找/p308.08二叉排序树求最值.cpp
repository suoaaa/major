/*设计一个算法，求出给定二叉排序树中最小和最大的关键字*/
#include "head.h"
#include <iostream>
using namespace std;
/*树的最左侧和最右侧分别为最大和最小关键字*/
int getMIN(BiTree T){
    node *p=T;
    while(p->lchild)  p=p->lchild;
    return p->lchild->val;
}
int getMAX(BiTree T){
    node *p=T;
    while(p->rchild)  p=p->rchild;
    return p->rchild->val;
}
int main(){
}
