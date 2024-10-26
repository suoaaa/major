/*已知一个n阶矩阵A和一个目标值k。该矩阵无重复元素，每行从左到右升序排列，每列从上到下升序排列。
请设计一个在时间上尽可能高效的算法，判断矩阵中是否存在目标值k
例如：      1  4  7
        A = 2  5  8 ，目标值为8，判断存在
            3  6  9                         */
#include "head.h"
//从矩阵右上角开始比较，若小于目标值，下移，大于目标值，左移
bool MFindKey(MSTable A,ElemType key){
    int i=0,j=A.length-1;
    while(i<A.length-1 && j>=0){
        if(A.data[i][j]==key) return true;
        if(A.data[i][j]>key) j--;
        else i++;
    }
    return false;    
}