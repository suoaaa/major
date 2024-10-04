//设单链表的表头指针为L, 结点结构由data和next两个域构成,
//其中data域为字符型。
//试设计算法判断该链表的全部n个字符是否中心对称。
//例如xyx、xyyx都是中心对称

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

#define MAX 50
#define ElemType int

typedef struct {
	int data[MAX];
	int length;
}List;

//定义单链表
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

//初始化链表
bool InitList(LinkList &L) {
	L = NULL;
	return true;
}

//使用尾插法建表
LinkList CreatList(List list) {
	if (list.length < 1) {
		return NULL;
	}
	LNode* head = (LinkList)malloc(sizeof(LNode));
	head->data = 0;
	head->next = NULL;
	LinkList p = head;
	for(int i=0 ; i< list.length; i++) {
		LNode* s = (LinkList)malloc(sizeof(LNode));
		s->data = list.data[i];
		s->next = NULL;
		p->next = s;
		p = s;
	}
	return head;
}

//获取链表长度（不算头结点）
int GetLength(LinkList list){
	if(!list) return -1;
	int i=0;
	LNode *p=list->next;
	while(p){
		i++;
		p=p->next;
	}
	return i;
}

//输出链表
void PrintList(LinkList list) {
	if(!list) return ;
	LNode *p=list->next;
	while (p != NULL && p != list) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}


bool symmetry(LinkList l,int n){
    LNode *p=l->next;
    char *s=new char[n/2];
    int i=0;
    for(i=0;i<n/2;i++){
        s[i]=p->data;
        p=p->next;
    }
    i--;
    if(n%2==1) p=p->next;
    while(p && s[i]==p->data){
        i--;
        p=p->next;
    }
    if(i==-1) return true;
    else return false;
}

int main(){
    List list={{7,4,6,5,6,4,7},7};
    LinkList l=CreatList(list);
    PrintList(l);
  	printf("%d",symmetry(l,7));
}