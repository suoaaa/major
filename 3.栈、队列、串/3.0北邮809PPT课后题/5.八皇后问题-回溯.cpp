//在8×8格的国际象棋上摆放8个皇后，使其不能互相攻击
//即任意两个皇后都不能处于同一行、同一列或同一斜线上
//问有多少种摆法。
#include "head.h"
#include <iostream>
void printf_arr(int arr[8][8],int n);
bool safe(int arr[8][8],int row,int col);
void queen(int a[8][8],int *n,int row){
    if(row>7){
        (*n)++;
        printf_arr(a,*n);
        return ;
    }
    for(int i=0;i<8;i++){
        if(safe(a,row,i)){
            a[row][i]=1;
            queen(a,n,row+1);
            a[row][i]=0;
        }
    }
}
int main(){
    int a[8][8]={0};
    int *n=new int;
    (*n)=0;
    queen(a,n,0);
    printf("共有%d种解法",*n);
    return 0;
}
void printf_arr(int arr[8][8],int n){
    printf("第%d种解法：\n",n);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j]==0) printf("▢\t");
			else if(arr[i][j]==1) printf("●\t");
        }
        printf("\n");
    }
}

bool safe(int arr[8][8], int row, int col){
    for(int i=1;i<8;i++){
        //if(row+i<8) if(arr[row+i][col]) return 0;
        //if(col+i<8) if(arr[row][col+i]) return 0;
        if(row-i>=0)if(arr[row-i][col]) return 0;
        if(col-i>=0)if(arr[row][col-i]) return 0;

        //if(row+i<8&&col+i<8) if(arr[row+i][col+i]) return 0;
        //if(row+i<8&&col-i>=0) if(arr[row+i][col-i]) return 0;
        if(row-i>=0&&col+i<8)if(arr[row-i][col+i]) return 0;
        if(row-i>=0&&col-i>=0)if(arr[row-i][col-i]) return 0;
    }
    return 1;
}
