//P19.7
//将两个有序顺序表合并为一个新的有序顺序表, 并由函数返回结果顺序表
#include"head.h"
List MergeList(List A, List B) {
	List c;
    int i=0,j=0,k=0;
    while(i<A.length&&j<B.length){
		if(A.data[i]<B.data[j]){
            c.data[k++]=A.data[i++];
        }else c.data[k++]=B.data[j++];
    }
    while (i < A.length) {
		c.data[k++] = A.data[i++];
	}
	while (j < B.length) {
		c.data[k++] = B.data[j++];
	}
	c.length = k;
	return c;
}

int main()
{
	List list1, list2;
	list1.length = 9;
	int Data1[] = { 1,4,9,11,14,24,39,54,76,99 };
	_for(i, 0, list1.length)
		list1.data[i] = Data1[i];
	PrintList(list1);

	list2.length = 5;
	int Data2[] = { 11,24,43,65,71 };
	_for(i, 0, list2.length)
		list2.data[i] = Data2[i];
	PrintList(list2);
	PrintList(MergeList(list1, list2));
}