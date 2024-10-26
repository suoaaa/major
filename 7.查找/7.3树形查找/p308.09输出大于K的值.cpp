/*设计一个算法，从大到小输出二叉排序树中所有值不小于k的关键字*/
#include "head.h"
#include <stack>
#include <iostream>
using namespace std;
/*应当按照右-中-左的遍历顺序对二叉排序树进行遍历，遍历到小于等于k的结点停止*/
void greaterK(BiTree T, int key){
    stack<Node*> s;
    Node *p=T;
    bool flag=true;
    while ((p != NULL || !s.empty() ) && flag ) {  
        while (p!=NULL) {  
            s.push(p);  
            p = p->rchild;  
        }
        p = s.top();  
        s.pop(); 
        if(p->val>key) visit(p);
        p = p->lchild;  
    }  
}
int main() {  
    BiTree root = new Node(1);  
    root->rchild = new Node(3);  
    root->rchild->lchild = new Node(2);  
    greaterK(root, 1);
    return 0;  
}