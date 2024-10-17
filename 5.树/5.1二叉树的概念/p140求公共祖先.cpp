//一颗二叉树按照顺序存储结构进行存储，设计一个算法，求编号为i和j的两个结点的最近的公共祖先结点的值。
#include <stdio.h>
#include <iostream>
using namespace std;
int public_ancestor(int i,int j){
    int m,n;
    m= i<j ? i:j;
    n=i+j-m;
    n/=2;
    if(m==n) return m;
    return public_ancestor(m,n);
}
int main(){
    cout<<public_ancestor(10,23);
}