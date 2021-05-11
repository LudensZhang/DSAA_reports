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

void preorder(bitree t)//这是非递归先序实现
{
    sequeue Q;
    Q.first=Q.tail=0;//置栈空

    //seqstack s;
    //s.top = -1;//置栈空
    while((t)||!QStackEmpty(Q))
    {
        while(t)
        {
            printf("%c", t->data);
            if(t->rchild!=NULL)
                QStackPush(Q,t->rchild);
            //s.a[++s.top] = t->rchild;//入栈
            t = t->lchild;
        }
        if (!QStackEmpty(Q)) {

            QStackPop(Q,t);
            //  t = s.a[s.top--];//出栈
        }
    }
}

void midorder(bitree t) //这是非递归中序实现，也适合先序
{
    if(!t)return;
    seqstack s;
    s.top = -1;//置栈空
    while((t)||(s.top!=-1))
    {
        while(t)
        {   //printf(" %c  ", t->data);//也适合先序
            s.a[++s.top] = t;//入栈
            t = t->lchild;
        }
        if (s.top>-1) {
            t=s.a[s.top--];
            printf("%c", t->data);
            t=t->rchild;
        }
    }
}

void postorder(bitree t)//这是非递归后序实现，也适合先序/中序
{
    if(!t)return;
    bitree lastvist=t;//初始化，只要是地址,且不为0即可!
    seqstack s;
    s.top = -1;//置栈空
    while(t||s.top != -1)
    {
        while(t)
        {
            //printf("%c", t->data);//也适合先序
            s.a[++s.top] = t;//入栈
            t=t->lchild;
        }
        t=s.a[s.top];
        if(t->rchild!=lastvist)
        {
            //printf("%c", t->data);//也适合中序
            t=t->rchild;
            if(!t)
                lastvist=t;
        }
        else
        {
            printf("%c", t->data);//适合后序
            s.top--;    //出栈
            lastvist=t;//更新
            t=0;//使下一循环直接取栈顶
        }
    }
}

void DLR(bitree root){        //递归先序二叉树
    if(!root)return;
    printf("%c", root->data);
    DLR(root->lchild);
    DLR(root->rchild);
}

void LDR(bitree root)        //递归中序二叉树
{
    if(!root)return;
    LDR(root->lchild);
    printf("%c",root->data);
    LDR(root->rchild);
}

void LRD (bitree root)      //递归后序二叉树
{
    if(!root)return;
    LRD(root->lchild);
    LRD(root->rchild);
    printf("%c",root->data);
}

Status mirror_tree(bitree root){      //镜像二叉树
    if(!root)return 0;
    node *p = root->rchild;
    root->rchild = root->lchild;
    root->lchild = p;
    mirror_tree(root->lchild);
    mirror_tree(root->rchild);
}

int tree_height(bitree root){     //求二叉树高度

    if(!root)return 0;
    if(root && !root->lchild && !root->rchild)return 1;
    if(tree_height(root->lchild) >= tree_height(root->rchild))return tree_height(root->lchild)+1;
    else return tree_height(root->rchild)+1;
}

/*
bitree BuTrPM(sqlist s1, sqlist s2)
{   int j,l1,l2,h1,h2; char c; node *p;
    l1=s1.low;l2=s2.low;h1=s1.high;h2=s2.high;
    if(l1 > h1 || l2 > h2)   return(0);           //递归出口
    c=s1.ch[s1.low];        //由先序遍历序列确定根
    p=new(node); p->data=c;                   //生成根结点
    for(j=s2.low;j<=s2.high;j++)
        if(c==s2.ch[j]) break;    //在中序序列找根的位置j
    s1.low=l1+1; s1.high=l1+j-l2; s2.low=l2;s2.high=j-1;
    p->lchild= BuTrPM(s1,s2);         //递归构建左子树
    s1.low=l1+j-l2+1; s1.high=h1; s2.low=j+1; s2.high=h2;
    p->rchild= BuTrPM(s1,s2);         //递归构建右子树
    return(p);
}
*/

int tree_width(bitree  T) {    //计算宽度
    bitree Qu[20];
    int w[10];
    int front = -1, rear = -1;
    int last = 0, level = 1;
    bitree p = T;
    Qu[++rear] = p;
    if (p == NULL) return 0;
    w[level] = 1;
    while (rear > front)
    {

        p = Qu[++front];
        if (p->lchild) {
            Qu[++rear] = p->lchild;
        }
        if (p->rchild)
            Qu[++rear] = p->rchild;

        if (front == last) {
            w[++level] = rear - last;
            last = rear;
        }
    }
    int max = 0;
    for (int i = 1; i <= level; i++) {
        if (w[i] > max) {
            max = w[i];
        }
    }
    return max;
}

int k_layer_dot(bitree  T, int k) {   //计算k层节点数
    bitree Qu[20];
    int w[10];
    int front = -1, rear = -1;
    int last = 0, level = 1;
    bitree p = T;
    Qu[++rear] = p;
    if (p == NULL) return 0;
    w[level] = 1;
    while (rear > front)
    {

        p = Qu[++front];
        if (p->lchild) {
            Qu[++rear] = p->lchild;
        }
        if (p->rchild)
            Qu[++rear] = p->rchild;

        if (front == last) {
            w[++level] = rear - last;
            last = rear;
        }
    }
    if(k > level)return 0;
    else return w[k];
}

int dot_count(bitree root){    //计算节点数
    if(!root)
        return 0;
    return (dot_count(root->rchild)+dot_count(root->lchild)+1);
}

int leaf_count(bitree root){  //计算叶子数
    if(!root)
        return 0;
    else if(!root->lchild && !root->rchild)
        return 1;
    else
        return(leaf_count(root->lchild)+ leaf_count(root->rchild));
}

bool structure_same(bitree t1, bitree t2){  //判断结构是否相同
    if(!t1 && !t2)
        return true;
    else if(!t1 || !t2)
        return false;
    return (structure_same(t1->lchild, t2->lchild) && structure_same(t1->rchild, t2->rchild));

}

bitree lowest_ancestor(bitree root, bitree t1, bitree t2){   //寻找最低祖先节点
    if (root == NULL || t1 == NULL || t2 == NULL)
        return NULL;

    if (t1 == root || t2 == root)
        return root;

    bitree* cur = NULL;

    node * left_ancestor = lowest_ancestor(root->lchild, t1, t2);
    node *right_ancestor = lowest_ancestor(root->rchild, t1, t2);
    if (left_ancestor && right_ancestor)
        return root;
    if (left_ancestor == NULL)
        return right_ancestor;
    else
        return left_ancestor;
}

int main(){
    bitree t;
    t = buildtree();
}