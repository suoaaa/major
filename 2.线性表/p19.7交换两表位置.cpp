//P19.7
//已知在一维数组A[m + n]中依次存放两个线性表(a1, a2, a3…, am)和(b, b2, b3, …, bn)。试编
//写一个函数, 将数组中两个顺序表的位置互换, 即将(b1,b2,b3,…, bn)放在(a1，a2, a3, …, am)的前面
#include"head.h"
void swaplist(List& A, int m, int n, int size) {
	Reserve(A, 0, m + n - 1, size);
	Reserve(A, 0, n - 1, size);
	Reserve(A, n, m + n - 1, size);
}

int main()
{
	List list;
	list.length = 10;
	int Data[] = { 1,4,9,7,14,24,12,54,42,32 };
	_for(i, 0, list.length)
		list.data[i] = Data[i];
	PrintList(list);
	swaplist(list, 4, 6, list.length);
	PrintList(list);
}