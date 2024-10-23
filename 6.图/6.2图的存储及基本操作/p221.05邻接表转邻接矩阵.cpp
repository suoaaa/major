#include "head.h"
void convert(ALGraph &G,int arcs[3][3]){
    ArcNode *p;
    for(int i=0;i<G.vexnum;i++){
        p=G.vertices[i].firstarc;
        while(p!=NULL){
            arcs[i][p->adjvex-1]=1;
            p=p->nextarc;
        }
    }
}
int main(){
    ALGraph g;
    g.arcnum=2;
    g.vexnum=3;
    g.vertices[0]=VNode('1');
    g.vertices[0].firstarc=new ArcNode(3);
    g.vertices[1]=VNode('2');
    g.vertices[1].firstarc=new ArcNode(3);
    g.vertices[2]=VNode('3');
    int arcs[3][3]={0};
    convert(g,arcs);
    printALGraph(g);
    printArcs(arcs,3);
}