#include <iostream>
#include <queue>
#include <stack>
using namespace std;


//定义单链表结点
template <class T> 
struct Node {
	T data;
	struct Node<T>* lch,*rch;
};

template <class T> class BiTree{
    protected:
		Node<T> *root;
        void Create     (Node<T>* &R, T data[], int i);
     	void Release    (Node<T> *R);
    public:
        BiTree(): root(NULL){}
        BiTree(T data[]);
	    void PreOrder   ();     //前序
	    void InOrder    ();     //中序
	    void PostOrder  ();     //后序
	    void LevelOrder ();     //层序
	    ~BiTree() {Release(root);};

        void PreOrder_   ();     //前序
	    void InOrder_    ();     //中序
	    void PostOrder_  ();     //后序
};

template <class T>  
void  BiTree<T>::Create(Node<T> *&R, T data[], int i){
    if (data[i-1]==0 || i>sizeof(data)){ 
        R = NULL;
        }
	else{                                           
		R=new Node<T>;
        R->lch=NULL;
        R->rch=NULL;
		R->data = data[i-1];
		Create(R->lch,data,2*i);
        Create(R->rch,data,2*i+1);
	}

}

template <class T>
inline BiTree<T>::BiTree(T data[]){
    Create(root,data,1);
}

// 先序遍历
template < class T > 
void BiTree<T>::PreOrder (){
    Node<T> *r=root;
    if (r!=NULL) {
		cout<<r->data<<" "; // 访问结点
        PreOrder(r->lch);   // 遍历左子树
        PreOrder(r->rch);   // 遍历右子树
    }
}

//中序遍历
template < class T > 
void BiTree<T>::InOrder (){
    Node<T> *r=root;
    if (r!=NULL) {
        InOrder(r->lch);    // 遍历左子树
        cout<<r->data;      // 访问结点
        InOrder(r->rch);    // 遍历右子树
    }
}

//后序遍历
template < class T > 
void BiTree<T>::PostOrder (){
    Node<T> *r=root;
    if (r!=NULL) {
        PostOrder(r->lch);  // 遍历左子树
        PostOrder(r->rch);  // 遍历右子树
        cout<<r ->data;     // 访问结点
    }
}

//层序遍历
template <class T> 
void BiTree<T>::LevelOrder (){
    queue<Node<T>>   q;
    Node<T> *r=root;
    if (r!=NULL)     q.push(r);
    while (!q.IsEmpty()){
        r=q.pop();
        cout<<r->data;
        if (r->lch!=NULL) q.push(r->lch);
        if (r->rch!=NULL) q.push(r->rch);
    }
}

// 析构函数
template < class T > 
void BiTree<T>::Release ( Node<T>  *Root ){
    if (Root!=NULL) {
        Release(Root ->lch); // 释放左子树
        Release(Root ->rch); // 释放右子树
        delete Root;            // 释放根结点
        Root = NULL;
    }
}
//二叉树叶子节点个数
template <class T> int Count_Leaf(Node<T> *R){
	if (R==NULL) return 0;
    if (R->lch==NULL && R->rch==NULL)
        return 1;
	else{
	    int m=Count_Leaf(R->lch);
		int n=Count_Leaf(R->rch);
		return m+n;
	}
}

//二叉树深度
template <class T> int Height(Node<T> *R){
	if (R==NULL) return 0;
	else{
 		int m=Height (R->lch);
        int n=Height (R->rch);
	    return m>n? m+1:n+1;
	}
}
