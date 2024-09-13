//P20.9
//线性表(a1,a2,a3,..,an)中的元素递增有序且按顺序存储于计算机内。
//要求设计一算法, 完成用最少时间在表中查找数值为x的元素, 若找到则将其与后继元素位置相交换,
//若找不到则将其插入表中并使表中元素仍递增有序
#include"head.h"
void searchAndSwap(List &list,int x){
	int low=0,high=list.length-1,mid=0;
    while(low<high){
        mid=(low+high)/2;
        if(x==list.data[mid]) {
            low=mid;high=mid;
        	break;
        }if(x<list.data[mid]){
            high=mid-1;
        }else low=mid+1;
    }
    if(low==high){
		swap(list.data[mid],list.data[mid+1]);
    }else{
        for(int i=list.length;i>low;i--){
			list.data[i]=list.data[i-1];
        }
        list.length+=1;
        list.data[low]=x;
    }
}

int main()
{
	List list;
	list.length = 10;
	int Data[] = { 1,4,9,11,14,24,32,54,62,81 };
	_for(i, 0, list.length)
		list.data[i] = Data[i];
	PrintList(list);
    searchAndSwap(list,32);
	PrintList(list);
}