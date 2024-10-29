/*〖2016统考真题】已知由n(n≥2)个正整数构成的集合A = { ak|0 ≤ k ≤ n }, 将其划分为两
个不相交的子集A1和A2, 元素个数分别是n1和n2, A1和A2中的元素之和分别为S1和S2
设计一个尽可能高效的划分算法, 满足|n1 - n2|最小且| S1 - S1|最大。要求
1)给出算法的基本设计思想
2)根据设计思想, 采用C或C++语言描述算法, 关键之处给出注释
3)说明你所设计算法的平均时间复杂度和空间复杂度*/
#include "head.h"
#include <iostream>
#include <algorithm>
using namespace std;
//和查找第k小的元素相似，将数组中最小的n/2个元素放入s1，其余放入s2即可
//即进行快速排序，找第n/2小的元素即可

int Partiton(List& list) {

	int low = 0, low0 = 0, high = list.length - 1, high0 = list.length - 1, k = list.length / 2;
	bool NoFind = true;
	while (NoFind) {
		int pivot = list.data[low];
		while (low < high) {
			while (low < high && list.data[high] >= pivot)
				high--;
			if (low != high)
				list.data[low] = list.data[high];
			while (low < high && list.data[low] <= pivot)
				low++;
			if (low != high)
				list.data[high] = list.data[low];
		}
		list.data[low] = pivot;
		if (low == k - 1)
			NoFind = false;
		else {
			if (low < k - 1) {
				low0 = ++low;
				high = high0;
			}
			else {
				high0 = --high;
				low = low0;
			}
		}
	}
	
	int s1 = 0, s2 = 0;
	for(int i=0; i<k;i++)
		s1 += list.data[i];
	for(int i=k; i<list.length;i++)
		s2 += list.data[i];
	return s2 - s1;

}

int main()
{
	List list;
	int data[] = { 14,11,4,9,1,24,32,54,62,81 };
	for(int i=0;i<10;i++){
		list.data[i]=data[i];
	}
	list.length=10;
	cout << "list为：" << endl;
	PrintList(list);
	cout << "S2-S1最大值为：" << Partiton(list) << endl;
	return 0;
}