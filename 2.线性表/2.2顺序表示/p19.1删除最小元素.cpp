//P19.1
//从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。
//空出的位置由最后一个元素填补, 若顺序表为空则显示出错信息并退出运行

#include "head.h"

int DeleteMinum(List &list){
    if(list.length<=0){
        printf("error");
        exit(0);
    }
    int min=list.data[0];
    int j=0;
    for(int i=0;i<list.length;i++){
        if(min>list.data[i]){
            min=list.data[i];
            j=i;
        }
    }
    list.data[j]=list.data[list.length-1];
    list.length-=1;
    return min;
}