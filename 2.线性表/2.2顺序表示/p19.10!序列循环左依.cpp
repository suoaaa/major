//P20.10
//〖2010统考真题〗设将n(n > 1)个整数存放到一维数组R中。设计一个在时间和空间两
//方面都尽可能高效的算法。将R中保存的序列循环左移p(0<p<n)个位置, 即将R中的
//数据由(X0,X1,…,Xn-1)变换为(Xp+Xp+1…,Xn-1,X0,X1…,Xp - 1)。要求
//1)给出算法的基本设计思想
//2)根据设计思想, 采用C或C++或Java语言描述算法, 关键之处给出注释
//3)说明你所设计算法的时间复杂度和空间复杂度
#include "head.h"
void moveleftx(List &list,int x){
	Reserve(list, 0, MoveStep - 1, MAX);
	Reserve(list, MoveStep, list.length - 1, MAX);
	Reserve(list, 0, list.length - 1, MAX);
}