//已知数组A[n]中元素为整型，设计算法将其调整为左右两部分，左边所有元素为奇数，右边所有元素为偶数。
#include <stdio.h>
void swap(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}
void Convert  (int A[], int n){
    int i=0,j=n-1;
    while(i<=j){
        while(A[i]%2==1) i++;
        while(A[j]%2==0) j--;
        if(i>=j) break;
        swap(A[i],A[j]);
    }
}
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,0};
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    Convert(a,10);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
