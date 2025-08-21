/*二叉树按照二叉链表形式存储，试编写一个判别给定二叉树是否是完全二叉树的算法*/
#include "head.h"
#include <iostream>
#include <queue>
/*完全二叉树：仅最后一层有叶节点，其他层的度均为2，且每个结点的度为0或2*/
//层序遍历，当发现有度不为2的结点，其后的结点应度都为0，且遍历过程中不应当有度为1的结点
bool is_complete(BiTree T){
    queue<Node *> q;
    Node *p;
    q.push(T);
    bool flag=false;        //当出现没有孩子的结点时，为false
    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p->lchild==NULL && p->rchild!=NULL) return false;    //有右无左孩子
        if(p->lchild&& p->rchild&& flag) return false;          //之前出现过没有孩子的结点，以后的结点有孩子
        if(p->lchild&& p->rchild) {
            q.push(p->lchild);
            q.push(p->rchild);
        }else flag =true;
    }
    return true;
}
bool isComplete(BiTree T){
    queue<Node *> q;
    Node *p;if(!T) return true;
    q.push(T);
    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p){
            q.push(p->lchild);
            q.push(p->rchild);
        }else{
            while(!q.empty()){
                p=q.front();
                q.pop();
                if(p)   return false;
            }
        }
    }
    return true;
}
int main(){
    int val[31]={0};
    for(int i=0;i<31;i++){
        val[i]=i+1;
    }
    BiTree T;
    CreateBiTree(T,val,31,1);
    SequenceOrder(T);
    cout<<is_complete(T)<<isComplete(T)<<endl;
    T->rchild->rchild->lchild->lchild=NULL;
    T->rchild->rchild->lchild->rchild=NULL;

    cout<<is_complete(T)<<isComplete(T)<<endl;

}