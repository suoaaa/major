/*编写非递归的后序遍历算法*/
#include "head.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
/*后序遍历按照左右根的顺序进行，每个根节点在左右结点都遍历结束后进行访问
记录一棵树中所有“是某结点的左孩子的的结点”入栈，且一个结点的左孩子先出栈
这样可以保证一个结点是栈顶元素时，它的左孩子一定是不存在或者已经被访问过的
这时不能直接出栈，要将这个结点的右孩子作为一棵子树进行遍历，之后才能对该结点出栈访问
至此以该结点为根的子树遍历结束
使用双栈进行操作，一个记录结点，一个记录结点的访问状态
-1为左右结点未访问，0为访问左结点，1访问过左右结点*/
void post_order(BiTree T){
    stack<Node*> s;
    stack<int> si;
    s.push(T);
    si.push(-1);
    Node *p;
    int flag;
    while(!s.empty()){
        p=s.top();
        flag=si.top();
        si.pop();
        //p可能并不会出栈，而结点状态一定会刷新,状态出栈
        if(p==NULL){
            s.pop();
            continue;
        }
        switch (flag){
        case -1:    //未访问左结点
            s.push(p->lchild);
            break;
        case 0:     //未访问右节点
            s.push(p->rchild);
            break;
        case 1:
            s.pop();
            visit(p);//左右结点均访问，则直接访问p结点
            continue;
        }
        si.push(flag+1);//p状态刷新
        si.push(-1);    //新加入结点状态

    }
}
int main(){
    int val[31]={0};
    for(int i=0;i<31;i++){
        val[i]=i+1;
    }
    BiTree T;
    CreateBiTree(T,val,31,1);
    SequenceOrder(T);
    post_order(T);
}