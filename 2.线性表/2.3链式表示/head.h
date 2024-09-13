#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

#define MAX 50
#define ElemType int

typedef struct {
	int data[MAX];
	int length;
}List;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

void swap(int& a, int& b) {
	int t;
	t = a;
	a = b;
	b = t;
}

//初始化链表
bool InitList(LinkList &L) {
	L = NULL;
	return true;
}

//判断是否为空
bool IsEmpty(LinkList L) {
	return (L == NULL);
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
//输出链表
void PrintList(LinkList list) {
	while (list != NULL) {
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}