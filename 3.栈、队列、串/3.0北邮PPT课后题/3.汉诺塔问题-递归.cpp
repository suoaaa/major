#include <stdio.h>
void move(char A,int n,char C){
    printf("%d from %c to %c\n",n,A,C);
}
void hanoi(int n,char A,char B,char C){
    if(n == 1){
        move(A,1,C);
    }
    else {
        hanoi(n-1,A,C,B);
        move(A,n,C);
        hanoi(n-1,B,A,C);
    }
}
int main(){
    hanoi(4,'A','B','C');
    return 0;
}