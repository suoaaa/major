/*分别采用基于深度优先遍历和广度优先遍历算法判别以邻接表方式存储的有向图中是否存在由顶点i到j的路径（i!=j）*/
#include "head.h"
#include <stack>
#include <queue>
#include <iostream>
#include <string.h>
using namespace std;
/*
分别对图从i顶点进行深度优先和广度优先遍历，最后看visited中j有没有被访问，被访问过说明有
参考head.h中的的dfs与bfs
*/
