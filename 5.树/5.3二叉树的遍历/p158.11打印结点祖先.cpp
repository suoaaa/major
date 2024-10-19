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

int main(){
    int val[31]={0};
    for(int i=0;i<31;i++){
        val[i]=i+1;
    }
    BiTree T;
    CreateBiTree(T,val,31,1);
    SequenceOrder(T);
}