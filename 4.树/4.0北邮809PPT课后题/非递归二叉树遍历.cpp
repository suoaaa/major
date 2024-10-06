#include "head.h"
#include <iostream>
using namespace std;
template <class T>  
struct SNode {  
    Node<T> *r;  
    int tag; // 1表示未访问完，2表示已访问完  
};  
template <class T>
inline void BiTree<T>::PreOrder_(){
    stack<Node<T>*> s;
    Node<T> *r=root;
    while(!s.empty() || r!=NULL){
        if(r!=NULL){
            s.push(r);
            cout<<r->data<<" ";
            r=r->lch;
        }else{
            r=s.top()->rch;
            s.pop();
        }
    }
    cout<<endl;
}
template <class T>
inline void BiTree<T>::InOrder_(){
    stack<Node<T>*> s;
    Node<T> *r=root;
    while(!s.empty() || r!=NULL){
        if(r!=NULL){
            s.push(r);
            r=r->lch;
        }else{
            r=s.top();
            s.pop();
            cout<<r->data<<" ";
            r=r->rch;
        }
    }
    cout<<endl;
}
template <class T>
inline void BiTree<T>::PostOrder_(){
    SNode<T> s[100]; 		        //栈
    Node<T> *r=root;
	int top=-1;       		    //栈顶指针
	do{
		while(r!=NULL) {        //入栈，设置访问左子树
		    s[++top].r = r;    	
            s[top].tag = 1; 	 
            r= r->lch;       
		}
		while((top!=-1) &&(s[top].tag==2)) {//访问栈顶元素，出栈 
			cout<< s[top].r ->data << " ";		 
            top--;  
 		}
		if((top!=-1)&&(s[top].tag==1)){ //访问右子树 
	        r = s[top].r->rch;    
			s[top].tag = 2; 		
		}
	}while(top!=-1);
}
int main(){
    int a[]={1,2,3,4,5,6,7,8};
    BiTree b=BiTree(a);
    b.PreOrder_( );
    b.InOrder_( );
    b.PostOrder_();
}