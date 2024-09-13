//在三个等长递增无重复元素的序列中找出三个序列中都有的元素并打印
#include"head.h"
void printSameX(List a,List b,List c){
    int n=a.length;
    int i=0,j=0,k=0;
    while(i<n&&j<n&&k<n){
        if(a.data[i]==b.data[j]&&a.data[i]==c.data[k]){
            printf("%d",a.data[i]);
            i++;
            j++;
            k++;
        }
        if(a.data[i]<b.data[j]) i++;
        if(b.data[j]<c.data[k]) j++;
        if(c.data[k]<a.data[i]) k++;
    }
}
int main(){
    int data1[]={1,2,3,4,5,7,9};
    int data2[]={1,3,5,6,7,8,9};
    int data3[]={1,2,3,4,6,7,9};
    List l1,l2,l3;
    int i=0;
    for(i=0;i<7;i++){
        l1.data[i]=data1[i];
        l2.data[i]=data2[i];
        l3.data[i]=data3[i];
    }
    l1.length=i;
    l2.length=i;
    l3.length=i;
    printSameX(l1,l2,l3);
    return 0;

}