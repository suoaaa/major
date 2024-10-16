//北邮数据结构以类和模板为基础实现单链表操作
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 50

template <class T> 
struct List{
	T data[MAX];
	int length;
};

//定义单链表结点
template <class T> 
struct Node {
	T data;
	struct Node<T>* next;
};

template <class T> class LinkList{
public:
    LinkList();
    LinkList(T a[],int n,int flag);
    ~LinkList();
    int Length();
    T Get(int);         //查找
    int Locate(T);      //定位
    void Insert(T,int); //插入 
    T Delete(int);      //删除
    void Reverse();     //转置
    void Printf();
    Node<T> *first;
private:
    void HeadCreat(T a[],int n);//头插法
    void TailCreat(T a[],int n);//尾插法
    void CirCreat(T a[],int n); //建立循环链表
};

template<class T> 
LinkList<T>::LinkList(){
    first = new Node<T>;
    first->next = NULL;
}

template<class T> 
LinkList<T>::LinkList(T a[],int n,int flag){
    first = new Node<T>;
    first->next = NULL;
    switch (flag)
    {
    case 0:
        HeadCreat(a,n);
        break;
    case 1:
        TailCreat(a,n);
        break;
    case 2:
        CirCreat(a,n);
        break;
    }
}

template <class T>
LinkList<T>::~LinkList(){
    Node<T> *p;
    while(first){
        p=first;
        first=first->next;
        delete(p);
    }
}

template <class T>
int LinkList<T>::Length(){
    int length=0;
    Node<T> *p=first;
    while(p){
        p=p->next;
        length++;
    }
    return length;;
}

template <class T>
T LinkList<T>::Get(int n){
    if(n<0) return -1;
    Node<T> *p=first;
    int i=1;
    while(i!=n && p!=NULL){
        p=p->next;
        i++;
    }
    return p->data;
}

template <class T>
int LinkList<T>::Locate(T data){
    Node<T> *p=first;
    int j=1;
    while(p){
        if(p->data == data) return j;
        p=p->next;
        j++;
    }
    return -1;
}

template <class T>
void LinkList<T>::Insert(T x, int i){     
    Node<T> *p=first;       
    int j = 0;
    while (p && j!=i-1){//找到编号i-1的结点
        p=p->next;             
        j++;   
    }
    if (p==NULL)  return ;
    else {
        Node<T> *q=new Node<T>;
        p->data=x;
        q->next=p->next;
        p->next=q;
    }
}

template <class T>
T LinkList<T>::Delete(int i){
    Node<T> *p=first;
    int j = 0;
    while (p->next && j!=i-1){
        p=p->next;
        j++;   
    }
    if(p->next==NULL)
        return -1;
    else {
        Node<T> *q=p->next;
        p->next=q->next;
        T ret=q->data;
        delete(q);
        return ret;
    }

}

template <class T>
void LinkList<T>::Reverse(){
    Node<T> *p=first->next, *q;
    first->next = NULL;
    while(p){
        q=p->next;
        p->next=first->next;
        first->next=p;
        p=q;
    }
}

template <class T>
inline void LinkList<T>::Printf(){
    Node<T> *p=first->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

template<class T> 
void LinkList<T>::HeadCreat(T a[], int n){
    Node<T> *p;
    for(int i=0;i<n;i++){
        p=new Node<T>;
        p->data=a[i];
        p->next=first->next;
        first->next=p;
    }
}

template<class T> 
void LinkList<T>::TailCreat(T a[], int n){
    Node<T> *p,*q=first;
    for(int i=0;i<n;i++){
        p=new Node<T>;
        p->data=a[i];
        p->next=NULL;
        q->next=p;
        q=p;
    }
}

template <class T>
inline void LinkList<T>::CirCreat(T a[], int n){
    first->data=a[0];
    Node<T> *p,*q=first;
    for(int i=1;i<n;i++){
        p=new Node<T>;
        p->data=a[i];
        p->next=first;
        q->next=p;
        q=p;
    }
}
