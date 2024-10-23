/*图中出度大于入度的顶点称为K顶点。
设计算法int printVertices(MGraph G)输出G中所有的K顶点，并返回K顶点的个数*/
#include "head.h"
#include <string.h>
int printVertices(MGraph G){
    int degree[2][MaxVertexNum];
    int count=0;
    memset(degree,0,sizeof(degree));
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            degree[0][i]+=G.Edge[i][j];
            degree[1][j]+=G.Edge[i][j];
        }
    }
    for(int i=0;i<G.vexnum;i++){
        if(degree[0][i]>degree[1][i]) {
            count++;
            printf("%c ",G.VerticesList[i]);
        }
    }
    return count;
}