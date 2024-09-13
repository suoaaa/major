//给定一个长度为n的序列，找出未出现的最小正整数元素
#include "head.h"
void findlost(List list){
    int box[MAX]={0};
    for(int i=0;i<list.length;i++){
        if(list.data[i]>=0) box[list.data[i]]++;
    }
    for(int i=1;i<MAX;i++){
        if(!box[i]){	
            printf("%d",i);
            break;
        }
    }
}
int main(){
    List list={{1,2,3,4,-1,6,2,1,3},9};
    PrintList(list);
    findlost(list);
    return 0;
}