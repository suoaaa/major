#include <iostream>
#include<string.h>
using namespace std;

int main(){
    int a[10]={-1};
    memset(a,-1,sizeof(a));
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
}