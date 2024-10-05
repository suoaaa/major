/*头文件包括：
    顺序栈：	入栈、出栈
	链式栈：	入栈、出栈
	循环队列：	入队、出队
	链式队列：	入队、出队
	稀疏矩阵：	三元组转置的优化
*/
#include <iostream>
#include <stdlib.h>
const int  MAXSIZE = 100;

//定义链表结点
template <class T> struct Node {
	T data;
	struct Node<T>* next;
};

template <class T> class SeqStack {
public:
  	SeqStack ();
	int     Empty();
    T 	    GetTop();           //获取栈顶元素
	bool    Push(T);            //入栈
 	T 	    Pop();              //出栈
private:
	T 	    data[MAXSIZE];      //存储结构
	int 	top;
};

template <class T> class LinkStack {
public:
  	LinkStack ();  
    ~LinkStack ();  
	int 	Empty();
    T 		GetTop();      	//获取栈顶元素
	void 	Push(T);     	//入栈
 	T 		Pop();    		//出栈
private:
	Node<T>  *top;			
};

template <class T> class CirQueue 
{
public:
    CirQueue();  
    bool		Empty();
	bool 	Full();
    T 		GetQueue();    	//获取队头元素
    void 	EnQueue(T);    	//入队
    T 		DeQueue();     	//出队
    int 	QueueLen();

private:
    T  		data[MAXSIZE];
    int  	f, r;
};

template <class T> class LinkQueue {
public:
  	LinkQueue ();  
	bool 	Empty();
    T 		GetQueue();		//获取队头元素
	void 	EnQueue(T);		//入队
 	T 		DeQueue();		//出队
    ~LinkQueue ();  
private:
	Node<T>  *front, *rear;
};

template <class T> struct  SparseMatrix{
	struct element{
		int   row; 
		int   col;
		T     item;
	};
	element data[MAXSIZE];
	int m, n, t;  //行数、列数、非零元素数
};

template <class T>
inline SeqStack<T>::SeqStack(){
	top=-1;
}

template <class T>
inline int SeqStack<T>::Empty(){
	if(top==-1) return 1;
	else return 0;
}

template <class T>
inline T SeqStack<T>::GetTop(){
	if(Empty())
    	return data[top];
	else return -1; 
}

template <class T>
bool SeqStack<T>::Push(T x)
{
    if (top==MAXSIZE-1) return false;
 	data[++top] = x;
	return true;
}

template <class T> 
T SeqStack<T>::Pop(){
    T x = data[top--] ;
    return x;
}

template <class T>
inline LinkStack<T>::LinkStack(){
	top=NULL;
}

template <class T>
inline LinkStack<T>::~LinkStack(){
	while(!Empty()){
		Pop();
	}
	top=NULL;
}

template <class T>
inline int LinkStack<T>::Empty(){
    if (top==NULL)	return 1;
	else return 0;
}

template <class T>
inline T LinkStack<T>::GetTop(){
    return top->data;
}

template <class T>
inline void LinkStack<T>::Push(T t){
	Node<T> *p=new Node<T>;
	p->data=t;
	p->next=top;
	top=p;
}

template <class T>
inline T LinkStack<T>::Pop(){
	Node<T> *p=top;
	T t=p->data;
	top=top->next;
	delete(p);
	return t;
}

template <class T>
inline CirQueue<T>::CirQueue(){
	f=0;r=0;
}

template <class T>
inline bool CirQueue<T>::Empty(){
    if (r==f) return 1;
	else return 0;
}

template <class T>
inline bool CirQueue<T>::Full(){
	if((r+1)%MAXSIZE==f)    return 0;
	else return 1;
}

template <class T>
inline T CirQueue<T>::GetQueue(){
    if(Empty) return 0;
	return data[(f+1)%MAXSIZE];
}

template <class T>
inline void CirQueue<T>::EnQueue(T t){
	if(Full()) return ;
	data[(++r)%MAXSIZE]=t;
}

template <class T> 
T CirQueue <T>:: DeQueue(){
        if (Empty) return 0;
        return data [(++f)%MAXSIZE];
}
     
template <class T> 
int CirQueue <T>::QueueLen(){
    //已知r和f，还有队列存储空间QueueSize
    return (r-f+MAXSIZE)%MAXSIZE;
}

template <class T>
inline LinkQueue<T>::LinkQueue(){
	front = new Node<T>;
	front->next = NULL;
	rear = front;
}

template <class T>
inline bool LinkQueue<T>::Empty(){
    if(front==rear) return 0;
	else return 1;
}

template <class T>
inline T LinkQueue<T>::GetQueue(){
	if(Empty) return 0;
	else return front->next->data;
}

template <class T>
inline void LinkQueue<T>::EnQueue(T t){
	Node<T> *p=new Node<T> ;
	p->data=t;
	p->next=NULL;
	rear->next=p;
	rear=p;
}

template <class T>
inline T LinkQueue<T>::DeQueue(){
    Node<T> *p=front->next;
	T t=p->data;
	front->next=p->next;
	if(p==rear) rear=front;
	delete (p);
	return t;
}

template <class T>
inline LinkQueue<T>::~LinkQueue(){
	while(front->next) DeQueue();
	delete(front);
	front = NULL;
	rear = NULL;
}


//稀疏矩阵的转置
template<class T>
void Transpose(SparseMatrix<T> A, SparseMatrix<T> &B){   
    //初始化相关信息
    B.m = A.n;   	//行数
    B.n = A.m;   	//列数
    B.t = A.t;     //元素数
	int *num=new int[A.n];
	int *pot=new int[A.n];
	pot[0]=0;
	for(int i=1;i<A.n;i++){
		pot[i]=pot[i-1]+num[i-1];
	}
	for(int i=0;i<A.t;i++)
		num[A.data[i].col]++;
    if (B.t>0){
		for(int i=0;i<A.t;i++){
			int j=A.data[i].col;
			B.data[pot[j]].row = A.data[i].col;
			B.data[pot[j]].col = A.data[i].row;
			B.data[pot[j]].item = A.data[i].item;
			pot[j]++;
		}
    }
}


class Point{
public:
    Point(int x,int y);
    Point();
    int x;
    int y;
    bool operator == (Point B);
    void operator = (Point B);
};

Point::Point(int x, int y){
    this->x=x;
    this->y=y;
}

Point::Point(){
}

bool Point::operator==(Point B)
{
    if(B.x==x&&y==B.y)  return true;
    else return false;
}

inline void Point::operator=(Point B){
	this->x=B.x;
    this->y=B.y;
}
