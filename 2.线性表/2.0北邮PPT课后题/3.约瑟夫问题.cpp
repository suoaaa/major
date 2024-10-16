//设有编号为1、2、3、…、n的n个人围成一个圈，从第一个人开始报数，报到m的人出圈，
//再从他的下一个人起从新报数，报到m的人出圈，如此下去，直到所有人全部出圈位置。
//给定任意的n和m，设计算法求n个人出圈的次序。
#include "head.h"
void Josephus (int a[], int n, int m){
 	int k=0;        //记录出局人数
    int num=-1;      //记录当前报数的人的编号
    while(k<n){
        for(int i=0;i<m;){
            num=(num+1)%n;
            if(a[num]!=0) i++;
        }
        cout<<a[num]<<" ";
        a[num]=0;
        k++;
    }
    cout<<endl;
}
//先创建一个循环链表，从first的下一个结点开始报数
//每报M个数删除报该数的结点，继续报数至链表中除头结点无其他结点
template<class T>
void Josephus (List<T> list,int m){
    LinkList<T> l=LinkList(list.data,list.length,2);
    Node<T> *p=l.first, *q;
    int k=0;
    while(k<list.length-1){
        for(int i=1;i<m-1;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        cout<<q->data<<" ";
        delete(q);
        p=p->next;
        k++;
    }
    cout<<p->data<<endl;
    l.first=NULL;
}
int main(){
    List<int> list={{1,2,3,4,5,6,7},7};
    Josephus(list,3);
    Josephus(list.data,list.length,3);
}