#include <iostream>
#include "head.h"
using namespace std;
void get_next(SString s,int next[]){
    int i=1,j=0;
    next[1]=0;
    while(i<s.length){
        if(j==0 || s.ch[i]==s.ch[j]){
            i++;j++;
            next[i]=j;
        }else j=next[j];
    }
}
void get_nextval(SString s,int nextval[]){
    int i=1,j=0;
    nextval[1]=0;
    while(i<s.length){
        if(j==0 || s.ch[i]==s.ch[j]){
            i++;
            j++;
            if(s.ch[i]!=s.ch[j]) nextval[i]=j;
            else nextval[i]=nextval[j];
        }else j=nextval[j];
    }
}
int index_KMP(SString s, SString t){
    int next[MAX+1];
    int nextval[MAX+1];
    get_next(t,next);
    get_next(t,nextval);
    int i=1,j=1,k=1;
    while(i<=s.length && j<=t.length){
        if(j==0 || s.ch[i]==t.ch[j]){
            i++;j++;
        }else j=nextval[j];
    }
    if(j>t.length) return i-t.length;
    else return -1;
}
int main(){
    SString s1,s2;
    StrAssign(s1,"123453456");
    StrAssign(s2,"3456");
    cout<<s1.length<<s2.length;
    cout<<index_KMP(s1,s2);

}