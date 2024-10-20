/*二叉树以二叉链表存储，打印值为x的结点的所有祖先，值为x的结点最多有1个*/
#include "head.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
/*递归
如果一个结点的值为x返回true
不然左右孩子继续递归
当左右孩子的递归返回true时打印当前结点的值
*/
//本质是递归的后序遍历，王道用非递归后序遍历
bool get_Parent(BiTree T,int x){
    if(T==NULL) return false;
    if(T->val==x) return true;
    if(get_Parent(T->lchild,x)||get_Parent(T->rchild,x)){
        cout<<T->val<<" ";
        return true;
    }else return false;
}
int main(){
    int val[31]={0};
    for(int i=0;i<31;i++){
        val[i]=i+1;
    }
    BiTree T;
    CreateBiTree(T,val,31);
    SequenceOrder(T);
    get_Parent(T,21);
}