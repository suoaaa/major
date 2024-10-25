#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string.h>
#include <iostream>
using namespace std;

#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;

typedef struct MGraph{                  //图的定义
    int vexnum,arcnum;  
    VertexType VerticesList[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
}MGraph;

//以下为图的邻接表存储结构
typedef struct ArcNode{                 //边表结点
    int adjvex;                         //该弧所指向的顶点的位置
    struct ArcNode *nextarc;            //指向下一条弧的指针
    int info;
    ArcNode(VertexType adjvex):adjvex(adjvex),nextarc(NULL){};
    ArcNode():nextarc(NULL){};
}ArcNode;

typedef struct VNode{                   //顶点表结点                
    VertexType data;                    //顶点信息
    ArcNode *firstarc;                  //指向第一条依附该顶点的弧的指针
    VNode(VertexType data):data(data),firstarc(NULL){};
    VNode():firstarc(NULL){};
}VNode,AdjList;

typedef struct ALGraph{                 
    AdjList vertices[MaxVertexNum];     //领接表
    int vexnum,arcnum;                  //图的顶点数和弧数
}ALGraph;                               //ALGraph是以邻接表存储的图类型

void visit(ALGraph G, bool visited[], int i);
void unvisit(ALGraph G, bool visited[], int i);
void DFSTraverse(ALGraph G);                            //邻接表的深度遍历操作
void DFS(ALGraph G, bool visited[], int i);             //邻接表的深度优先递归
void BFS(ALGraph G, bool visited[], int i);             //邻接表的广度优先递归

void printALGraph(ALGraph g){
    for(int i=0;i<g.vexnum;i++){
        ArcNode *p=g.vertices[i].firstarc;
        printf("%c: ",g.vertices[i].data);
        while(p){
            printf("%c ",p->adjvex);
            p=p->nextarc;
        }
        printf("\n");
    }
}
void printArcs(int arcs[3][3],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arcs[i][j]);
        }
        printf("\n");
    }
}


void visit(ALGraph G, bool visited[], int i){
    visited[i] = true;         		                    //访问过了该顶点，标记为TRUE 
    //cout<<G.vertices[i].data<<" ";
}

void visit(ALGraph G, bool visited[], int i){
    visited[i] = false;
    //cout<<G.vertices[i].data<<" ";
}
void DFS(ALGraph G, bool visited[],int i){      //邻接表的深度优先递归
    visit(G,visited,i);
       ArcNode* p= G.vertices[i].firstarc;      //让p指向边表第一个结点 
    while (p) {                                 //在边表内遍历 
        if (!visited[p->adjvex])                //对未访问的邻接顶点递归调用 
            DFS(G, visited,p->adjvex);
        p = p->nextarc;
    }
}

void BFS(ALGraph G, bool visited[], int i){     //邻接表的广度优先递归
    queue<AdjList> q;
    q.push(G.vertices[i]);
    visit(G,visited,i);
    ArcNode* p;                                 //让p指向边表第一个结点 
    while (!q.empty()) {
        p=q.front().firstarc;
        q.pop();
        do{
            if (p!=NULL&&!visited[p->adjvex]){
            visit(G, visited,p->adjvex);
            q.push(G.vertices[p->adjvex]);
            }
            p=p->nextarc;
        }while(p->nextarc!=NULL);
    }

}
void DFSTraverse(ALGraph G) {                   //邻接表的深度遍历操作
    bool visited[MaxVertexNum];
    memset(visited,false,sizeof(visited));      //初始设置为未访问 
    for(int i=0;i< G.vexnum;i++)
        if (!visited[i])
            DFS(G, visited, i);	                //对未访问的顶点调用DFS，若是连通图只会执行一次 			
}
