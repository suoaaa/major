//假设以I和O分别表示入栈和出栈操作。
//栈的初态和终态均为空, 入栈和出栈的操作序列可表示为仅由I和O组成的序列
//可以操作的序列称为合法序列, 否则称为非法序列,下面所示的序列中哪些是合法的
//A.IOIIOIOO 合法       B.IOOIOIIO
//C.IIIOIOIO            D.IIIOOIOO  合法
//2)通过对1)的分析, 写出一个算法, 判定所给的操作序列是否合法。
//若合法, 返回true否则返回 false(假定被判定的操作序列已存入一维数组中)
#include <stdio.h>
#include <iostream>
using namespace std;
bool isLegal(char a[]){
    int i=0,j=0;
    while(a[i]!='\0'){
        if(a[i]=='I') j++;
        if(a[i]=='O') j--;
        if(j<0) return false;
        i++;
    }
    if(j==0) return true;
    else return false;
}
int main()
{
	char str1[] = { "IOIIOIOO" };
	char str2[] = { "IOOIOIIO" };
	char str3[] = { "IIIOIOIO" };
	char str4[] = { "IIIOOIOO" };
	cout << isLegal(str1) << endl;
	cout << isLegal(str2) << endl;
	cout << isLegal(str3) << endl;
	cout << isLegal(str4) << endl;
	return 0;

}
