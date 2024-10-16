#include <stdio.h>

int main(void){
    int n,d1,d2,d3,d4;
    n=12;
    scanf("%d",&n);
    d4=n%2; n/=2;
    d3=n%2; n/=2;
    d2=n%2; n/=2;
    d1=n%2; n/=2;
    printf("%d%d%d%d",d1,d2,d3,d4);
    return 0;
}