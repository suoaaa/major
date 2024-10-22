/*设计一个算法，将给定的表达式树转换为等价的中缀表达式并输出*/
#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;
/**/
typedef struct node{
    char data[10];
    struct node *left,*right;
    node(const char c[]){
        memset(data,0,10);
        for(int i=0;i<sizeof(c)/sizeof(char)&&i<10;i++){
            data[i]=c[i];
        }
        left=NULL;
        right=NULL;
        }

}*BTree;
void BtreeToExp(BTree root,int deep=1){
    if(root==NULL)return ;
    if(root->left==NULL && root->right==NULL){ 
        cout<<root->data;
        return ;
    }
    if(deep!=1) cout<<"(";
    BtreeToExp(root->left,deep+1);
    cout<<root->data; 
    BtreeToExp(root->right,deep+1);
    if(deep!=1) cout<<")"; 
}
int main(){
    BTree root=new node("*");
    root->left=new node("+");
    root->right=new node("*");

    root->left->left=new node("a");
    root->left->right=new node("b");
    
    root->right->left=new node("c");
    root->right->right=new node("-");
    root->right->right->right=new node("d");
    BtreeToExp(root);
}