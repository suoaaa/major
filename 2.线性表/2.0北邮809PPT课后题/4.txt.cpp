// 已知L是无头结点的单链表，且P结点既不是首元结点，也不是尾元结点
// 试从下列语句中选择合适的序列。
   // 1 在P结点后插入S结点       4，3
   // 2 在P结点前插入S结点       7，11，8，4，3
   // 3 在表首插入S结点的序列    5
   // 4 在表尾插入S结点的序列    9，1


// 1 	P->next = S;
// 2 	P->next = P->next->next;
// 3 	P->next = S->next;
// 4 	S->next = P->next;
// 5 	S->next = L;
// 6 	S->next = NULL;
// 7 	Q = P;
// 8 	while (P->next!=Q) P=P->next;
// 9 	while (P->next!=NULL) P=P->next;
// 10 	P=Q  
// 11 	P=L
// 12 	L=S;
// 13 	L=P;
