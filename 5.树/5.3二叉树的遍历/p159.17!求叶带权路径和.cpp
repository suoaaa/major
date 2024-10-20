/*〖2014统考真题】二叉树的带权路径长度(WPL)是二叉树中所有叶结点的带权路径长
度之和。给定一棵二叉树T, 采用二又链表存储, 结点结构为
    left
    weight
    right
其中叶结点的weight域保存该结点的非负权值。设root为指向T的根结点的指针,
请设计求T的WPL的算法, 要求
1)给出算法的基本设计思想
2)使用C或C++语言, 给出二叉树结点的数据类型定义。
3)根据设计思想, 采用C或C + 语言描述算法, 关键之处给出注释*/
#include "head.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
/**/
int get_weight(BiTree T,int depth=0){
    if(T==NULL) return 0;
    if(T->lchild==NULL && T->rchild==NULL) return (T->val)*depth;
    else return get_weight(T->rchild,depth+1)+get_weight(T->lchild,depth+1);
}
int main(){
    int val[31]={0};
    for(int i=0;i<31;i++){
        val[i]=i+1;
    }
    BiTree T;
    CreateBiTree(T,val,5,1);
    SequenceOrder(T);
    cout<<get_weight(T);
}