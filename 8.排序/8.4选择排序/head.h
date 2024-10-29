#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

#define MAX 50

void swap(int& a, int& b) {
	int t;
	t = a;
	a = b;
	b = t;
}

typedef struct List{
	int data[MAX];
	int length;
}List;

//定义单链表
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, *LinkList;

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
	if(!list) return ;
	LNode *p=list->next;
	while (p != NULL && p != list) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//给定一个List，传入List的大小，要逆转的起始位置
void Reserve(List& list, int start, int end, int size) {
	if (end <= start || end >= size) {
		return;
	}
	int mid = (start + end) / 2;
	for( int i=0; i<=mid - start; ++i){
		swap(list.data[start + i], list.data[end - i]);
	}
}

void PrintList(List list) {
	for(int i= 0;i< list.length;i++) {
        printf("%d ",list.data[i]);
	}
	printf("\n");
}
bool listIsNull(List list){
	return !list.length;
}