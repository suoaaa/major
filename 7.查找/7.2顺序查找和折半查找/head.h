#include <stdio.h>

#define ElemType int
#define MaxSize 100
typedef struct STable{
    ElemType data[MaxSize];
    int length;
}STable;

typedef struct LSTable{
    ElemType data;
    LSTable *next;
    LSTable():next(NULL){};
    LSTable(ElemType data):data(data),next(NULL){};
}LSTable;

typedef struct MSTable{
    ElemType data[MaxSize][MaxSize];
    int length;
}MSTable;