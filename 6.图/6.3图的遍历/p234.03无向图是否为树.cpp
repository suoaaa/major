/*设计一个算法，判断一个无向图G是否为一棵树。若是一个棵树，则算法返回true，否则返回false*/
#include "head.h"
#include <iostream>
#include <string.h>
using namespace std;
//无向图为树的条件是图有n-1条边的连通图,需要对图进行深度优先遍历，记录遍历过的边和点的个数
void DFS(MGraph G,int v,bool visited[],int &en,int &vn);
int next(MGraph G,int v,int j=0);

bool isTree(MGraph G){                      //使用邻接矩阵判断
    bool visited[MaxVertexNum];
    memset(visited,false,sizeof(visited));
    int en=0,vn=0;
    DFS(G,1,visited,en,vn);
    if(en==vn-1&&vn==G.vexnum) return true;
    else return false;
}

void DFS(MGraph G,int v,bool visited[],int &en,int &vn){
    visited[0]=1;
    vn++;
    int w=next(G,v);
    while(w!=-1){
        if(!visited[w]){
            en++;
            DFS(G,w,visited,en,vn);
        }
        w=next(G,v,w);
    }
}

int next(MGraph G,int v,int j=0){
    for(int i=j+1;i<G.vexnum;i++){
        if(G.Edge[v][i]==1) return i;
    }
    return -1;
}