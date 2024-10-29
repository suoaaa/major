#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

#define MAX 50

typedef struct List{
	int data[MAX];
	int length;
    List(){};
}List;

void swap(int& a, int& b) {
	int t;
	t = a;
	a = b;
	b = t;
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