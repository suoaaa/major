/*二叉树相似是两棵树都是空的二叉树或者只有一个根节点；或者两棵树的左子树和右子树分别相似*/
#include "head.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
/*递归判断*/
bool similar(BiTree t1,BiTree t2){
    if(t1==t2) return true;                 //两棵树都为NULL，或者是同一棵树
    if(t1==NULL ^ t2==NULL ) return false;  //两棵树有棵为空，另一颗非空
    return similar(t1->lchild,t2->lchild)&&similar(t1->rchild,t2->rchild);
}

int main(){
    int val[31]={0};
    for(int i=0;i<31;i++){
        val[i]=i+1;
    }
    BiTree t1,t2;
    CreateBiTree(t1,val,31,1);
    CreateBiTree(t2,val,31,1);
    cout<<similar(t1,t2);
}