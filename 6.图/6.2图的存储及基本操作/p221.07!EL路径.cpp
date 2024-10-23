/*当G中度为奇数的顶点个数为不大于2的偶数时，G存在包含所有边，且长度为|E|的路径称为EL路径
设计算法int IsExsitEL(MGraph G),判断G是否存在EL路径，若存在返回1，不存在返回0*/
#include "head.h"
int IsExsitEL(MGraph G){
    int degree,count=0;
    for(int i=0;i<G.vexnum;i++){
        degree=0;
        for(int j=0;i<G.vexnum;j++){
            degree+=G.Edge[i][j];
            if(degree%2==1) count++;
        }
    }
    if(count==0 || count==1) return 1;
    else return 0;
}