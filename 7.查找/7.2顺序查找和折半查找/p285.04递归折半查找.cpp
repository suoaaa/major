#include <iostream>
#include "head.h"
using namespace std;

int BinSearch(STable s,ElemType key, int low,int high){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(s.data[mid]==key) return mid;
    if(s.data[mid]>key)  return BinSearch(s,key,low,mid-1);
    else return BinSearch(s,key,mid+1,high);
}