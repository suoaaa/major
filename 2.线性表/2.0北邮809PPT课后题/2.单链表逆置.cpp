//以单链表为存储结构，写出就地逆置的算法
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 50

typedef struct {
	int data[MAX];
	int length;
}List;

//定义单链表
template <class T> 
struct Node {
	T data;
	struct Node<T>* next;
};

template <class T> class LinkList{
public:
    LinkList();
    LinkList(T a[],int n,int flag);//尾插法
    ~LinkList();
    int Length();
    T Get(int);
    int Locate(T);
    void Insert(T,int);
    T Delete(int);
private:
    Node<T> *first;
    void HeadCreat(T a[],int n);
    void TailCreat(T a[],int n);
};

template<class T> 
LinkList<T>::LinkList(){
    first = new Node<T>;
    first->next = NULL;
}

template<class T> 
LinkList<T>::LinkList(T a[],int n,int flag){
    LinkList();
    switch (flag)
    {
    case 0:
        HeadCreat(a,n);
        break;
    case 1:
        TailCreat(a,n);
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
