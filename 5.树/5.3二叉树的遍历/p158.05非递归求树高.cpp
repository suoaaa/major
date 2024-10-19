//假设二叉树用二叉链表存储，设计一个非递归算法求二叉树的高度
#include "head.h"
#include <stack>
#include <queue>
//用了pair结构，两种数据类型组成一对，分别用first和second指向成员变量
//这里将树的结点和结点对应的层数配对
//思想：用队列对树进行层序遍历，并且在队列中树的结点和树的层数一起入栈
//最后获得层序遍历的最后一个结点的层数，即树高
int get_heigh(BiTree T){
    if(!T) return 0;
    int h=0;
    Node *p;
    queue<pair<Node*,int>> q;
    q.push(make_pair(T,h+1));
    while(!q.empty()){
        p=q.front().first;
        h=q.front().second;
        q.pop();
        if(p->lchild!=NULL){
            q.push(make_pair(p->lchild,h+1));
        }
        if(p->rchild!=NULL){
            q.push(make_pair(p->rchild,h+1));
        }
    }
    return h;
}
/*王道
设置一个level变量记录树高
对树进行层序遍历
last指向当前层数的最右边的结点
当遍历到last指向的结点时说明一层已经遍历结束，level可以加1
然后level指向下一层的最后一个指针，继续进行遍历
当遍历完树的最后一个结点时，level为树高
*/
#define MaxSize 100
int Btdeptj(BiTree T){
    if(!T) return 0;
    int front=-1,rear=-1;
    int last=0,level=0;
    BiTree Q[MaxSize];
    Q[++rear]=T;
    BiTree p;
    while(front<rear){
        p=Q[++front];
        if(p->lchild)
            Q[++rear]=p->lchild;

        if(p->rchild)
            Q[++rear]=p->rchild;
            if(front==last){
                level++;
                last=rear;
            }
    }
    return level;
}
int main(){
    int val[20]={0};
    for(int i=0;i<20;i++){
        val[i]=i+1;
    }
    BiTree T;
    CreateBiTree(T,val,20,1);
    SequenceOrder(T);
    cout<<get_heigh(T);
}