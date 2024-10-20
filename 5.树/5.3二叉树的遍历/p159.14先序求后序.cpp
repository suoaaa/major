/*二叉树由二叉链表存储，已知其先序序列，设计一个算法求其后序序列*/
#include "head.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
/*中左右->左右中,递归*/
void pretopost(int pre[],int l1,int h1,int post[],int l2,int h2){
    if(l1>h1) return ;
    post[h2]=pre[l1];
    int half=(h1-l1)/2;
    pretopost(pre,l1+1,l1+half,post,l2,l2+half-1);
    pretopost(pre,l1+half+1,h1,post,l2+half,h2-1);
}

int main(){
    int pre[7]={0};
    for(int i=0;i<7;i++){
        pre[i]=i+1;
    }
    int post[7]={0};
    pretopost(pre,0,6,post,0,6);
    for(int i=0;i<7;i++){
        cout<<post[i]<<" ";
    }
}