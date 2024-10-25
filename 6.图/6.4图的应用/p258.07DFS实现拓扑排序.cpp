//试说明利用DFS如何实现有向无环图拓扑排序
#include <iostream>
#include <string.h>
#include "head.h"
using namespace std;

bool visited[MaxVertexNum];
int topo[MaxVertexNum];
int j = 0;

void DFS(ALGraph G, int i) {         
    ArcNode* p;
    visited[i] = true;         		
    p = G.vertices[i].firstarc;       
    while (p) {                    
        if (!visited[p->adjvex])    
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
    topo[j++] = i;
}

void DFSTraverse(ALGraph G) {
    memset(visited, false, sizeof(visited));
    for(int i=0; i< G.vexnum;i++)
        if (!visited[i])
            DFS(G, i);	            			
}

void Print_TopologicalSorting(ALGraph G) {
    for (int i = G.vexnum - 1; i >= 0; i--) {
        cout << G.vertices[topo[i]].data << " ";
    }
    cout << endl;
}
