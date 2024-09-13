
//P19.3
//对长度为n的顺序表L, 编写一个时间复杂度为O(n)空间复杂度为O(1)的算法,
//该算法删除线性表中所有值为x的数据元素
#include "head.h"
int deleteNoted(List &list,int num){
    if (!list.length) return -1;
    int i=0,j=0,k=0;
    for(;i<list.length;i++){
        if(list.data[i]!=num){
            swap(list.data[i],list.data[j++]);
        }else k++;
    }
    list.length-=k;
    return k;
}
int main(){
    List list;
    int data[]={1,2,3,4,5,6,7,6,5,4,3,2,1};
    for(int i=0;i<13;i++){
        list.data[i]=data[i];
    }
    list.length=13;
    PrintList(list);
    printf("\n%d\n",deleteNoted(list,6));
	PrintList(list);
    return 0;
}