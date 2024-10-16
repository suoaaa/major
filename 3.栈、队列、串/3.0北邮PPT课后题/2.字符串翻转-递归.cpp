#include <stdio.h>
#include <stdlib.h>
void Reverse(const char *c){
    if(*c == '\0') return ;
    Reverse(c+1);
    printf("%c",c[0]);
}
int main(){
    Reverse("123456");
    return 0;
}