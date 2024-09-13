//P19.4
//从有序顺序表中删除其值在给定值s与t之间(要求s < t)的所有元素, 如果s或t不合
//理或顺序表为空, 则显示出错信息并退出运行
#include"head.h"
void deleteRangeST(List &list,int s,int t){
    if(!list.length||s>=t){
        printf("error");
        return ;
    }
    int k=0;
    for(int i=0;i<list.length;i++){
        list.data[i-k]=list.data[i];
        if(list.data[i]>=s&&list.data[i]<=t){
            k++;
        }
    }
    list.length-=k;
}
int main()
{
	List list;
	list.length = 9;
	int Data[] = { 2,4,6,39,11,12,24,34,44 };
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
	PrintList(list);
	deleteRangeST(list, 4, 24);
	PrintList(list);
}