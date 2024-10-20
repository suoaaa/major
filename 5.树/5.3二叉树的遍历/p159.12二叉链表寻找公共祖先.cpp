/*二叉树的结点结构为（LLINK,INFO,RLINK），root为指向该二叉树根结点的指针，
p，q分别指向该二叉树中任意两个结点的指针，
试编写算法ANCESTOR(ROOT,p,q,r),找到p和q的最近的公共祖先结点r*/
#include "head.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
Node* Ancestor(BiTree root,Node *p,Node *q);    //非递归实现
Node* _Ancestor(Node* root, Node* p, Node* q);  //递归实现 
/*非递归后序遍历，找到第一个结点后，将该结点赋值给r，另一个结点赋值给right指针，继续遍历
若遍历的结点与r相同，则r指向当前栈的栈顶元素（栈顶元素是当前结点的父结点）
这样保证r一直是左结点的祖先，并且在r指向其他结点之前，遍历的结点都在r的右侧
若遍历到p、q中的右节点时，r的左孩子中有左结点，右孩子中有右节点，符合pq的最近公共祖先*/
Node* Ancestor(BiTree root,Node *p,Node *q){
    stack<Node*> s;
    stack<int> si;
    s.push(root);
    si.push(-1);
    Node *node;
    Node *right=NULL;
    int flag;
    Node *r=NULL; //使用r记录在右侧的结点，初始pq左右关系未知为NULL
    while(!s.empty()){
        node=s.top();
        flag=si.top();
        si.pop();
        //p可能并不会出栈，而结点状态一定会刷新,状态出栈
        if(node==NULL){
            s.pop();
            continue;
        }
        //当未发现左结点时，right为null，寻找左结点
        //当发现左结点后，寻找右节点，当找到时，r为qp的最近公共祖先
        if(right==NULL){
            if(node == p) right=q;
            if(node == q) right=p;
            if(right!=NULL) r=node;
        }else if(right==node)  return r;
        switch (flag){
        case -1:    //未访问左结点
            s.push(node->lchild);
            break;
        case 0:     //未访问右节点
            s.push(node->rchild);
            break;
        case 1:
            s.pop();
            if(node==r&&!s.empty()) r=s.top();//若左结点访问结束后未发现公共祖先，将r上移一位
            continue;
        }
        si.push(flag+1);//p状态刷新
        si.push(-1);    //新加入结点状态
    }
    return NULL;
}
//最终返回的是左右子树均有p、q其中一个结点的的结点
Node* _Ancestor(Node* root, Node* p, Node* q){
    // 如果根节点为空，或者根节点是 p 或 q，则返回根节点  
    if (root == nullptr || root == p || root == q) {  
        return root;  
    }  
      
    // 在左子树和右子树中递归寻找 p 和 q  
    Node* left = _Ancestor(root->lchild, p, q);  
    Node* right = _Ancestor(root->rchild, p, q);  
      
    // 如果 left 和 right 都不为空，说明 p 和 q 分别位于当前节点的左右子树中  
    // 因此当前节点是最近公共祖先  
    if (left != nullptr && right != nullptr) {  
        return root;  
    }  
      
    // 否则，返回非空的那个指针（它可能是 p 或 q，或者是 nullptr）  
    return left != nullptr ? left : right;  
}  
int main(){
    int val[31]={0};
    for(int i=0;i<31;i++){
        val[i]=i+1;
    }
    BiTree T;
    CreateBiTree(T,val,31,1);
    SequenceOrder(T);
    Node *r=Ancestor(T,T->lchild->lchild->lchild,T->lchild->lchild->lchild->rchild);
    visit(r);
}