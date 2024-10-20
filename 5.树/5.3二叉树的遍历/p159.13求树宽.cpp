/*二叉树由二叉链表存储结构，设计一个算法，求非空二叉树b的宽度（即具有结点数最多的那一层的结点个数）*/
#include "head.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;
/*用数组存储每一层的结点个数*/
int width(BiTree T,int *num=NULL,int heigth=1){
    if(num==NULL) {
        num=(int*)malloc(sizeof(int)*100);
        for(int i=0;i<100;i++) num[i]=0;
    }
    if(T!=NULL) num[heigth]++;
    else return -1;
    width(T->lchild,num,heigth+1);
    width(T->rchild,num,heigth+1);
    if(heigth==1) {
        int max=0;
        for(int i=1;i<100;i++) max = max>num[i]?max:num[i];
        return max;
    }else return -1;
}
int main(){
    int val[31]={0};
    for(int i=0;i<31;i++){
        val[i]=i+1;
    }
    BiTree T;
    CreateBiTree(T,val,31,1);
    SequenceOrder(T);
    cout<<width(T);
}