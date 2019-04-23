#include <iostream>
#include <cstdlib>
using namespace std;
#define LEN sizeof(struct LNode)
#define OK 1
#define ERROR -1
#define OVERFLOW -2
#define ElemType int

typedef int Status;

typedef struct LNode{
      ElemType a;
      struct LNode *next;
}LNode;

LNode* InitLink_Link(int l){
    LNode* LinkList;
    LNode* pnew;
    LNode* plast;

    for(int i =0;i<l;++i){
        pnew = (LNode*)malloc(sizeof(LNode));

        if(i == 0)
            pnew->next = NULL;
        else
            pnew -> next = plast;

        cin>>pnew->a;
        plast = pnew;
    }
    LinkList = plast;

    return LinkList;
}
Status LinkPrint(LNode* L){
    for(LNode* r = L; r != NULL;r = r->next){
        cout<<r->a<<" ";
    }
    return OK;
}

LNode* Link(LNode* r1,LNode* r2)
{
    LNode* r = NULL;
    LNode* MoveR = NULL;
    LNode* pa =NULL;
    LNode* pb = NULL;

    if(r1->a < r2->a){
        r = r1;
        MoveR = r1;
        pa = r1->next;
        pb = r2;
    }else{
        r = r2;
        MoveR = r2;
        pb = r2->next;
        pa = r1;
    }
    while(pa&&pb){
        if(pa->a <= pb->a){
            MoveR -> next =pa;
            MoveR = pa;
            pa = pa->next;
        }else{
            MoveR ->next = pb;
            MoveR = pb;
            pb = pb->next;
        }

    }
    MoveR ->next = pa ? pa : pb;
    return r;
}
LNode *make(LNode *head){
    LNode *p1,*p2,*data,*p3,*p4;
    p4=p2=(LNode *)malloc(LEN);
    p2->a=head->a;
    data=p2;
    for(p1=head->next;p1!=NULL;p1=p1->next){
        int b=1;
        for(p3=head;p3!=p1;p3=p3->next)
        {
            if(p3->a==p1->a)
               {
                   b=0;
               }
        }
        if(b==1)
        {
                p2=(LNode *)malloc(LEN);
                p2->a=p1->a;
                p4->next=p2;
                p4=p2;
        }
    }
    p4->next=NULL;
    return data;
}
int main()
{
    int l1,l2;

    cin>> l1;
    LNode* r1 = InitLink_Link(l1);

    cin>> l2;
    LNode* r2 = InitLink_Link(l2);

    LNode* r =Link(r1,r2);
    LinkPrint(make(r));
    return 0;
}
