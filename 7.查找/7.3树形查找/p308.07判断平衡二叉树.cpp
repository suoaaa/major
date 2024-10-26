/*利用二叉树遍历的思想编写一个判断二叉树是否是平衡二叉树的算法*/
#include "head.h"
#include <iostream>
using namespace std;
/*设置标记变量balance和h，balance用于记录当前节点的左右子树是否平衡，h记录左右子树的高者高度加一*/

void isVAL(BiTree T,bool &balance,int &h){
    if(T==NULL){
        balance=true;
        h=0;
    }
    else{
        bool balancel,balancer;
        int hl,hr;
        isVAL(T,balancel,hl);
        isVAL(T,balancer,hr);
        h=(hl>hr?hl:hr)+1;
        balance=(hl - hr <2 && hr - hl <2 && balancel && balancer);
    }
}
