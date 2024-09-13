//定义三元组（a,b,c)的距离为D=|a-b|+|a-c|+|b-c|
//给定三个非空整数集合按照升序储存在数组中，每个数组中取一个元素构成三元组
//计算所有可能的三元组中的最小距离
#include "head.h"
#include <cmath>
int distance(int a,int b,int c){
    return abs(a-b)+abs(a-c)+abs(b-c);
}
int min(int a,int b){
    return a>b? b :a;
}
void mindistance(List a,List b,List c){
   	int i=0,j=0,k=0;
   	int dis=10000000;
	while(i<a.length&&j<b.length&&k<c.length){
        dis = min(dis,distance(a.data[i],b.data[j],c.data[k]));
		if(a.data[i]<b.data[j]&&a.data[i]<c.data[k]){
            i++;
        }else{
            if(b.data[j]<c.data[k]){
				j++;
            }else{
                k++;
            }
        }
    }
    printf("%d",dis);
}
int main(){
    List a={{-1,2,9},3};
    List b={{-25,0,10,11},4};
    List c={{1,11,17,30,41},5};
	mindistance(a,b,c);
    return 0;
}