
//P19.2
//设计一个高效算法，将顺序表的所有元素逆置，要求算法的空间复杂度为O⑴
#include "head.h"
void reverse(List &list){
    if(!list.length){
        return ;    
    }
    for(int i=0;i<list.length/2;i++){
        swap(list.data[i],list.data[list.length-i-1]);
    }
}
int main()
{
	List list;
	list.length = 9;
	int Data[] = { 2,4,3,9,43,12,54,76,38 };
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
	PrintList(list);
	reverse(list);
	PrintList(list);
}