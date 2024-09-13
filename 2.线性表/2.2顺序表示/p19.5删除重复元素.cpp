//P19.5
//从有序顺序表中删除所有其值重复的元素,使表中所有元素的值均不同
#include"head.h"
void OlderlyDeleteSame(List& list) {
    if(!list.length){
        printf("error");
        return;
    }
	int k=0;
    for(int i=1;i<list.length;i++){
        if(list.data[i]==list.data[i-1]){
            k++;
        }
        list.data[i-k]=list.data[i];
    }
    list.length-=k;
}
int main()
{
	List list;
	list.length = 11;
	int Data[] = { 1,3,3,4,9,9,9,9,9,14,14,24 };
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
	PrintList(list);
	OlderlyDeleteSame(list);
	PrintList(list);
}