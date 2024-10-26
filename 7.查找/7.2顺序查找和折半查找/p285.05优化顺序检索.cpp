#include "head.h"

int SeqSearch(STable s,ElemType key){
    for(int i=0;i<s.length;i++){
        if(s.data[i]==key){
            if(i!=0){
                ElemType t=s.data[i-1];
                s.data[i-1]=s.data[i];
                s.data[i]=t;
                return i-1;
            }
        }
    }
}

LSTable *SeqSearch(LSTable *s,ElemType key){
    //r->q->p,若p为查找成功的点，交换顺序 r->p->q
    LSTable *p=s->next;
    LSTable *q=s;
    LSTable *r=NULL;
    while(p){
        if(p->data!=key){
            r=q;
            q=p;
            p=p->next;
        }else{
            if(r==NULL) return p;
            else{
                q->next=p->next;
                r->next=p;
                p->next=q;
                return p;
            }
        }
    }
    return NULL;
}