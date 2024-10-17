#include "head.h"
#include <iostream>
using namespace std;
void printf_arr(int arr[10][10]);
int next(int arr[10][10],Point cur,Point end){
    if(cur == end) {
        printf_arr(arr);
        return 1;
    }
    arr[cur.x][cur.y]=2;
    if(arr[cur.x+1][cur.y]==0)
        if(next(arr,Point(cur.x+1,cur.y),end)) 
            return 1;

    if(arr[cur.x-1][cur.y]==0)
        if(next(arr,Point(cur.x-1,cur.y),end)) 
            return 1;

    if(arr[cur.x][cur.y+1]==0)
        if(next(arr,Point(cur.x,cur.y+1),end)) 
            return 1;

    if(arr[cur.x][cur.y-1]==0)
        if(next(arr,Point(cur.x,cur.y-1),end)) 
            return 1;

    arr[cur.x][cur.y]=1;
    return 0;
}
void MasePath(int arr[10][10],Point start,Point end){
    LinkStack<Point> stack;
    Point p=start;
    arr[p.x][p.y]=2;
    while(p.x!=end.x && p.y!=end.y){
        stack.Push(p);
        if(arr[p.x+1][p.y]==0)          arr[++p.x][p.y] =2;
		else if (arr[p.x-1][p.y]==0)	arr[--p.x][p.y] =2;
        else if (arr[p.x][p.y+1]==0)    arr[p.x][++p.y] =2;
		else if (arr[p.x][p.y-1]==0)    arr[p.x][--p.y] =2;
        else{
            p=stack.Pop();
            arr[p.x][p.y]=1;
            if(stack.Empty()) break;
            p=stack.Pop();
        }
    }
    printf_arr(arr);
}
int main(){
    int a[10][10]={{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
        ,{-1,0,0,-1,0,0,0,-1,0,-1}
        ,{-1,0,0,-1,0,0,0,-1,0,-1}
        ,{-1,0,0,0,0,-1,-1,0,0,-1}
        ,{-1,0,-1,-1,-1,0,0,0,0,-1}
        ,{-1,0,0,0,-1,0,0,0,0,-1}
        ,{-1,0,-1,0,0,0,-1,0,0,-1}
        ,{-1,0,-1,-1,-1,0,-1,-1,0,-1}
        ,{-1,-1,0,0,0,0,0,0,0,-1}
        ,{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};
    int b[10][10]={{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
        ,{-1,0,0,-1,0,0,0,-1,0,-1}
        ,{-1,0,0,-1,0,0,0,-1,0,-1}
        ,{-1,0,0,0,0,-1,-1,0,0,-1}
        ,{-1,0,-1,-1,-1,0,0,0,0,-1}
        ,{-1,0,0,0,-1,0,0,0,0,-1}
        ,{-1,0,-1,0,0,0,-1,0,0,-1}
        ,{-1,0,-1,-1,-1,0,-1,-1,0,-1}
        ,{-1,-1,0,0,0,0,0,0,0,-1}
        ,{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};
    next(a,Point(1,1),Point(8,8));
    cout<<endl;
    MasePath(b,Point(1,1),Point(8,8));
}

void printf_arr(int arr[10][10])
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(arr[i][j]==-1) printf("■\t");
			else if(arr[i][j]==2) printf("*\t");
			else printf("\t");
        }
        printf("\n");
    }
}