//以单链表为存储结构，写出就地逆置的算法
#include "head.h"
int main(){
    List<int> list={{7,4,4,5,5,2,1},7};
    LinkList<int> l=LinkList(list.data,list.length,1);
    l.Printf();
  	l.Reverse();
    l.Printf();
}