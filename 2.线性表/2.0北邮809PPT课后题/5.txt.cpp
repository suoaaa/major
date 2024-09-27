// 已知L是带头结点的单链表，且P结点既不是首元结点，也不是尾元结点
// 试从下列语句中选择合适的序列。
//    1 删除P结点的直接后继结点    11,1,14/11,3,14
//    2 删除P结点的直接前驱结点    10,12,8,11,1,14
//    3 删除P结点                  10,12,7,11,3,14
//    4 删除首元结点               12,13,10,14
//    5 删除尾元结点               11,6,1,14


// 1 	P->next = Q->next;
// 2 	P->next = P;
// 3 	P->next = P->next->next;
// 4 	P = P->next->next;
// 5 	while (P!=NULL) P=P->next;
// 6 	while (Q->next!=NULL) {P=Q;Q=Q->next;}
// 7   while (P->next!=Q)  P=P->next;
// 8 	while (P->next->next!=Q)  P=P->next;
// 9 	while (P->next->next!=NULL) P=P->next;
// 10 	Q=P;  
// 11 	Q=P->next;
// 12 	P=L;
// 13  L=L->next;
// 14  delete Q;
