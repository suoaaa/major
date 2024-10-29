/*设顺序表用数组A[]表示, 表中元素存储在数组下标1 --- (m + n)的范围内, 前m个元素
递增有序, 后n个元素递增有序, 设计一个算法, 使得整个顺序表有序
1)给出算法的基本设计思想
2)根据设计思想, 采用C/C++描述算法, 关键之处给出注释
3)说明你所设计算法的时间复杂度与空间复杂度。*/
#include <iostream>
#include <string.h>
using namespace std;

//归并排序
void MergeSort(int A[], int m, int n) {

    int B[m + n + 1];
    memset(B,0,sizeof(B));
    int i = 1, j = m + 1, k = 1;
    while (i <= m && j <= m + n) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        }   
        else {
            B[k++] = A[j++];
        }
    }
    while (i <= m) {
        B[k++] = A[i++];
    }
    while (j <= m + n) {
        B[k++] = A[j++];
    }
    for(i=1;i<m+n+1;i++){
        A[i]=B[i];
    }
}

int main(){
    int A[] = { 0,2,5,21,54,64,12,25,34,62,87,91 };
    MergeSort(A, 5, 6);
    for(int i=1;i<=11;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}

