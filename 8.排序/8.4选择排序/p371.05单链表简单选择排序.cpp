/*编写一个算法, 在基于单链表表示的待排序关键字序列上进行简单选择排序*/
#include "head.h"
#include <iostream>
#include <vector>
using namespace std;

void SortList(LinkList &head) {
//带头结点的单链表进行简单选择排序
	LNode *p, *pre ,*min, *minpre;
	LNode *h=head;
	while (h) {
		p=h->next;
		min=p;
		while(p){
			if(p->data < min->data){
				min=p;
				minpre=pre;
			}
			pre=p;
			p=p->next;
		}
		if(min!=h->next){
			minpre->next=min->next;
			min->next=h->next;
			h->next=min;
		}
		h=h->next;
	}
}

int main()
{
	List list={{ 3,54,26,18,34,47,19,57 },8};
	LinkList head=CreatList(list);
	cout << "排序前：" << endl;
	PrintList(head);
	cout << "排序后：" << endl;
	SortList(head);
	PrintList(head);
	return 0;
}
