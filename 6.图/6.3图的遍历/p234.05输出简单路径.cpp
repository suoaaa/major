/*假设图用邻接表表示，设计一个算法，输出从顶点i到顶点j的所有简单路径*/
#include "head.h"
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
/*
采用深度优先遍历算法，从i结点开始，查找与其相邻的点并继续
    若当前点为j，打印路径，并返回上一层
    若当前点不为j，则继续查找相邻的点
查找当前点所有的路径均不能到j，删除当前点的访问记录，返回上一层
*/
void printpath(int path[],int n){
    int i=0;
    while(path[i]!=n){
        cout<<path[i]<<" ";
        i++;
    } 
    cout<<path[i]<<endl;
}

void findpath(ALGraph G,int i,int j,bool visited[],int path[],int d){
    path[++d]=i;
    if(i==j) {
        printpath(path,j);
        return ;
    }
    visit(G,visited,i);
    ArcNode *p=G.vertices[i].firstarc;
    while (p){
        if(!visited[p->adjvex])
            findpath(G,p->adjvex,j,visited,path,d);
        p=p->nextarc;
    }
    unvisit(G,visited,i);
}