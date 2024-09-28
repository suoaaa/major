#include <stdio.h>
#include <stdlib.h>
void DtoB(int n){
    if(n == 0) return ;
    DtoB(n/2);
    printf("%d",n%2);
}
int main(){
    DtoB(77);
    return 0;
}