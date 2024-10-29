/*试编写一个算法, 使之能够在数组L[1…n]中找出第小的元素(即从小到大排序后处于第k个位置的元素)*/
#include "head.h"
#include <iostream>
#include <algorithm>
using namespace std;

int Kth_Elem(List& list, int low, int high, int k) {
	int pivot = list.data[low];
	int low_temp = low;
	int high_temp = high;
	while (low < high) {
		while (low < high && list.data[high] >= pivot)
			high--;
		list.data[low] = list.data[high];
		while (low < high && list.data[low] <= pivot)
			low++;
		list.data[high] = list.data[low];
	}
	list.data[low] = pivot;
	if (low == k)
		return list.data[low];
	else if (low > k)
		return Kth_Elem(list, low_temp, low - 1, k);
	else
		return Kth_Elem(list, low + 1, high_temp, k);
}

int main()
{
	List list;
	int data[] = { 0,14,4,9,11,1,24,32,54,62,81 };//0不算
	for(int i=0;i<11;i++){
		list.data[i]=data[i];
	}
	list.length=10;
	PrintList(list);
	int k = 6;
	cout << "第" << k << "小的元素为：" << Kth_Elem(list, 1, list.length , k) << endl;
	return 0;
}