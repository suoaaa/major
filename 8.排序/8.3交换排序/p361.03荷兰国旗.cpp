/*荷兰国旗问题:设有一个仅由红、白、蓝三种颜色的条块组成的条块序列,
请编写一个时间复杂度为O(m)的算法, 使得这些条块按红、白、蓝的顺序排好, 即排成荷兰国旗图案*/
#include "head.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Flag_Arrange(List &list) {
	int i = 0, j = 0, k = list.length - 1;
	//j为工作指针，i之前为红色（0），k之后为蓝色（2）
	while (j <= k) {
		switch (list.data[j]){ 
			case 0: {
				swap(list.data[i++], list.data[j++]);
				break;
			}
			case 1:{
				j++;
				break;
			}
			case 2: {
				swap(list.data[j], list.data[k--]);
			}
		}
	}
}

int main()
{
	List list;
	//设红为0，白为1，蓝为2
	int data[] = { 1,0,1,2,2,1,2,0,1,2 };
	for(int i=0;i<10;i++){
		list.data[i]=data[i];
	}
	list.length=10;
	cout << "排序前为：" << endl;
	PrintList(list);
	cout << "排序后为：" << endl;
	Flag_Arrange(list);
	PrintList(list);
	return 0;
}