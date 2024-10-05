#include "head.h"
#include <iostream>
using namespace std;
int simple_match(SString s1,SString s2){


    int i=1,j=1;
    while(i<=s1.length && j<=s2.length){
        if(s1.ch[i] == s2.ch[j]) {
            i++;
            j++;
        }else{
            i=i-j+2;
            j=1;
        }
    }
    if(j>s2.length) return i-j+1;
    else return -1;
}
int main(){
    SString s1,s2;
    StrAssign(s1,"123453456");
    StrAssign(s2,"3456");
    cout<<s1.length<<s2.length;
    cout<<simple_match(s1,s2);

}