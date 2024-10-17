//自定义串
#include<stdio.h>
#define MAX 255
typedef struct{
    char ch[MAX+1];
    int length;
}SString;

//复制串
int StrAssign(char *d,const char *s){
	if(d==NULL) return -1;
    int i=0;
    *d++;
    while(*s!='\0'){
        *d=*s;
        *d++;
        *s++;
        i++;
    }
    return i;
}
void StrAssign(SString &d,const char *s){
	d.length=StrAssign(d.ch,s);
}

//求串长
int StrLength (SString s){
	int n=0;
	while(s.ch[n+1]!='\0') {
		n++;
	}
    s.length=n;
	return n;
}
//字符串比较
int StrCmp (SString s1,SString s2){
    int i=1;
    while(s1.ch[i]==s2.ch[i]){
        i++;
        if(s1.ch[i]=='\0')return 0;
    }
    if(s1.ch[i]>s2.ch[i]) return 1;
    else return -1;
}
