#include <stdio.h>
#include <stdlib.h>

struct node { int num; struct node *next; };
struct node *stnode, *tmp, *fnNode;

struct node *createNodeCircular(int n);
void displayList();
void swapKth(int k);

int main(){
    int n,k;
    scanf("%d",&n);
    if(n>0)stnode=createNodeCircular(n);
    scanf("%d",&k);
    swapKth(k);
    displayList();
    return 0;
}

struct node *createNodeCircular(int n){
    int num;
    stnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&num);
    stnode->num=num; stnode->next=NULL;
    tmp=stnode;
    for(int i=2;i<=n;i++){
        fnNode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&num);
        fnNode->num=num;
        fnNode->next=(i==n)?stnode:NULL;
        tmp->next=fnNode;
        tmp=tmp->next;
    }
    return stnode;
}

void displayList(){
    struct node *t;
    if(stnode!=NULL){
        t=stnode;
        do{
            printf("%d\n",t->num);
            t=t->next;
        }while(t!=stnode);
    }
}

void swapKth(int k){
    int len=0;
    struct node *p=stnode;
    do{
        len++;p=p->next;
    }
    while(p!=stnode);

    if(k>len)return;

    struct node *x=stnode,*xprev=NULL;
    for(int i=1;i<k;i++){
        xprev=x;
        x=x->next;
    }

    struct node *y=stnode,*yprev=NULL;
    for(int i=1;i<len-k+1;i++){
        yprev=y;
        y=y->next;
    }

    if(xprev)xprev->next=y;
    if(yprev)yprev->next=x;

    struct node *t=x->next;
    x->next=y->next;
    y->next=t;
    if(k==1)stnode=y;
    if(k==len)stnode=x;
}
