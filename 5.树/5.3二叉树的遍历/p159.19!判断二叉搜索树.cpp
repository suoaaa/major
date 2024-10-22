/**/
#include "head.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define MAX_SIZE 100
/*对于一个非空二叉树采用顺序方式存储，结点值均为正整数，对于不存在的结点用-1表示。
设计一个尽可能高效的算法，判定一棵树采用这种方式存储的二叉树是否为二叉搜索树*/
typedef struct{
    int SqBiTNode[MAX_SIZE];
    int ElemNum;
}SqBiTree;

bool isBSearchTree(SqBiTree t,int &min,int &max,int n=0){
    if(n>=t.ElemNum) return  true;
    int lmax=t.SqBiTNode[n]-1,rmin=t.SqBiTNode[n]+1;
    if(2*n+1 >=t.ElemNum || t.SqBiTNode[2*n+1]==-1) {
        min=t.SqBiTNode[n];
    }else{
        if(!isBSearchTree(t,min,lmax,2*n+1)) return false;
    }
    if(2*n+2 >=t.ElemNum || t.SqBiTNode[2*n+2]==-1){
        max=t.SqBiTNode[n];
    }else{
        if(!isBSearchTree(t,rmin,max,2*n+2)) return false;
    }
    if(t.SqBiTNode[n]>rmin||t.SqBiTNode[n]<lmax) return false;
    else return true;
}
bool isBSearch(SqBiTree t){
    int min,max;
    return isBSearchTree(t,min,max);
}
int main(){
    int val[MAX_SIZE]={40,25,60,-1,30,-1,80,-1,-1,27};
    SqBiTree t;
    for(int i=0;i<10;i++){
        t.SqBiTNode[i]=val[i];
    }
    t.ElemNum=10;
    cout<<isBSearch(t);
}