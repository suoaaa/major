//背包承重为10，共有5件宝物他们的重量分别为2, 2, 6, 5, 4，
//它们的价值分别是6, 3, 5, 4, 6求解使用这个背包最多能带走多少财富。
//背包承重n，m件宝物，重量和价值为W[],v[]
#include <stdio.h>
#include <iostream>
using namespace std;
const int n=10;
const int m=5;
int pack(int f[m+1][n],int *w,int *v);
int main(){
    int f[m+1][n]={0};    
    int w[m+1]={0,2,2,6,5,4};
    int v[m+1]={0,6,3,5,4,6};
    printf("%d",pack(f,w,v));
}

int pack(int f[m][n], int *w, int *v){
    for(int i=1;i<m+1;i++){
        for(int j=0;j<n;j++){
            if(j>=w[i]) f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
            else f[i][j]=f[i-1][j];
        }
    }
    return f[m][n-1];
}
