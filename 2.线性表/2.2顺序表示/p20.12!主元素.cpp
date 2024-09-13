//一个长度为n，元素大小均在0－n之间的序列，如有一个元素出现次数超过n/2
//则这个元素称为该序列的主元素
//写出寻找一个序列的主元素的算法，输出主元素或者输出－1
#include "head.h"
void mainelement(List list){
    int box[list.length]={0};
    for(int i=0;i<list.length;i++){
    	box[list.data[i]]++;
        if(box[list.data[i]]>list.length/2){
            printf("%d",list.data[i]);
            break;
        }
    }
    printf("-1");
}
int main(){
    List list={{1,2,3,4,5,2,3,3,3,3,3},11};
    mainelement(list);
    return 0;
}