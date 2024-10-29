/*试设计一个算法, 判断一个数据序列是否构成一个小根堆*/
#include "head.h"
#include <iostream>
using namespace std;

bool IsHeap(List l) {
    int i=l.length/2;
    if(l.length%2==1) {
        if(l.data[i] < l.data[l.length]) i--;
        else return false;
    }
    for(;i>0;i--){
        if(l.data[i]>l.data[i*2] || l.data[i]>l.data[i*2+1]) return false;
    }
    return true;
}

int main()
{
    List list1={{ -1,2,4,5,21,45,21,44,22,87,2,4,8 },12};
    List list2={{ -1,2,4,3 },3};
    cout<<IsHeap(list1)<<" "<<IsHeap(list2)<<endl;
    return 0;
}
