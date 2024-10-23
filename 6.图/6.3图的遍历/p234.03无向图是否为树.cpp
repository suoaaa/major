/*设计一个算法，判断一个无向图G是否为一棵树。若是一个棵树，则算法返回true，否则返回false*/
#include "head.h"
#include <iostream>
#include <string.h>
using namespace std;
//无向图为树的条件是图有n-1条边的连通图
bool isTree(MGraph G){                      //使用邻接矩阵判断
    bool visited[MaxVertexNum];
    memset(visited,false,sizeof(visited));
    int Enum=0,Vnum=0;
}