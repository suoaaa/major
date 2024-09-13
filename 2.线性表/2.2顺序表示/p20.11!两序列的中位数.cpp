//一个长度L的升序序列的中位数为第(L+1)/2个位置的数
//两个序列的中位数是他们合并并排序后的中位数
//设计一个算法求领个序列的中位数
#include"head.h"
int midofAB(List a,List b){
    int i=0,j=0;
    while(i+j<(a.length+b.length)/2-1){
		if(a.data[i]<b.data[j]){
            i++;
        }else j++;
    }
    return a.data[i]<b.data[j] ? a.data[i] : b.data[j];
}

int main()
{
	List list1, list2;
	list1.length = 9;
	int Data1[] = { 1,4,9,11,14,24,39,54,76,99 };
	for(int i=0; i<list1.length;i++)
		list1.data[i] = Data1[i];
	PrintList(list1);

	list2.length = 5;
	int Data2[] = { 11,24,43,65,71 };
	for(int i=0;i < list2.length;i++)
		list2.data[i] = Data2[i];
	PrintList(list2);
    printf("%d\n" ,midofAB(list1, list2));

}