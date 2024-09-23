#include <iostream>
#include<string>
using namespace std;
void get_next_val(string t,int nextval[]){
    int i=1,j=0;
    while(i<t.length()-1){

        if(j==0||t[i]==t[j]){
            printf("i=%d,j=%d,",i,j);
            ++i;++j;
            
            if(t[i]!=t[j])	nextval[i]=j;
            else nextval[i]=nextval[j];
            printf("i=%d,j=%d,nxtval[%d]=%d\n",i,j,i,nextval[i]);
        }
        
        else j=nextval[j];
        printf("j=%d\n",j);
        
    }
}
int main(){
    string t="1ababaabab";
    int nextval[10]={0};
    get_next_val(t,nextval);
    for(int i=0;i<10;i++){
        printf("%d ",nextval[i]);
    }return 0;
}