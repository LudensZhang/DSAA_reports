#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
#define maxsize 10
#define n_actions 2
#define num_episodes 20
#define OK 1
#define OVERFLOW 1

typedef int Status;

typedef struct node{
    char data;
    struct node *lchild,*rchild;
} node;
typedef node *bitree;


typedef struct {
    bitree a[maxsize];
    int first,tail;
}sequeue;

bool EnQueue(sequeue &Q,bitree t)
{
    if(Q.first==(Q.tail+1)%maxsize)return 0;
    Q.a[Q.tail]=t;
    Q.tail=(Q.tail+1)%maxsize;
}

bool DeQueue(sequeue &Q,bitree &t)
{
    if(Q.first==Q.tail)return 0;
    t=Q.a[Q.first];
    Q.first=(Q.first+1)%maxsize;
}

bool QStackEmpty(sequeue Q)
{
    if(Q.first==Q.tail)return true;
    return false;
}

bool QStackPush(sequeue &Q,bitree t)
{
    EnQueue(Q,t);
}

bool QStackPop(sequeue &Q,bitree &t)
{
    int i;
    if(Q.first==Q.tail)return 0;
    for(i=0;i<Q.tail-Q.first-1;i++)
    {
        DeQueue(Q,t);
        EnQueue(Q,t);
    }
    DeQueue(Q,t);
}

typedef struct {
    bitree a[maxsize];
    int top;
}seqstack;

bitree buildtree()          //构造二叉树
{
    char c;
    node *p;
    c=getchar();
    if(c=='0')return(0);
    p=new(node);
    p->data=c;
    p->lchild=buildtree();
    p->rchild=buildtree();
    return(p);
}

bitree buildtree_nonerecursive(char *a){
    seqstack stack;

}

int main(){
    char a[10] = "ab##c##";
}
