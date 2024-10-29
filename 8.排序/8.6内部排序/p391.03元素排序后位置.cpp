/*设有一个数组中存放了一个无序的关键序列K1, K2, …, Kn。现要求将Kn放在将元素排序
后的正确位置上, 试编写实现该功能的算法, 要求比较关键字的次数不超过n。*/
#include <iostream>
using namespace std;

//快排一次
int Partition(int A[],int low,int high) {
    int pivot = A[high];
    while (low < high) {
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
    }
    A[high] = pivot;
    return low+1;
}

int main(){
    int A[] = { 61,2,5,21,24,64,12,15,34,32,47,9 };
    cout<<Partition(A, 0, 11)<<endl;
    return 0;
}
