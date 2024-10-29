/*已知线性表按顺序存储, 且每个元素都是不相同的整数型元素, 设计把所有奇数移动到
所有偶数前边的算法(要求时间最少, 辅助空间最少)*/
#include "head.h"
#include <iostream>
#include <algorithm>
using namespace std;

void move(List &list){
	int temp=list.data[0];
	int low=0,high=list.length-1;
	bool flag=true;
	while(low!=high){
		while(flag&&low!=high) {
			if(list.data[high]%2==1) {
				list.data[low++]=list.data[high];
				flag=false;
			}
			else high--;
		}
		while(!flag&&low!=high) {
			if(list.data[low]%2==0) {
				list.data[high--]=list.data[low];
				flag=true;
			}
			else low++;
		}
	}
	list.data[low]=temp;
}
int main()
{
	List list;
	int data[] = { 1,4,9,11,14,24,32,54,62,81 };
	for(int i=0;i<10;i++){
		list.data[i]=data[i];
	}
	list.length=10;
	PrintList(list);
	// MoveOddNum(list, 0, list.length - 1);
	move(list);
	PrintList(list);
	return 0;
}