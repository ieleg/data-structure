#include"stdio.h"
#include"stdlib.h"

typedef struct tree_ *TREE;
TREE inserrrr(int x,TREE b);
struct tree_
{
    int data;
    TREE left;
    TREE right;
    int flag;
};

TREE creanttree(int n)
{
    TREE t;
    int i,V;
    scanf("%d",&V);
        t=(TREE)malloc(sizeof(struct tree_));
        t->data=V;
        t->flag=0;
        t->left=t->right=NULL;
    for(i=1;i<n;i++)
    {
        scanf("%d",&V);
        t=inserrrr(V,t);
    }
    return t;

}

TREE inserrrr(int x,TREE b)//关键插入到应该的位置
{
    if(!b)  //第一次插入
    {
        b=(TREE)malloc(sizeof(struct tree_));
        b->data=x;
        b->flag=0;
        b->left=b->right=NULL;
    }
    else
    {
        if(x<b->data)
        {
            b->left=inserrrr(x,b->left);
        }
        else if(x>b->data)
        {
            b->right=inserrrr(x,b->right);
        }
    }
    return b;
}
int check(TREE b,int v)    //每次搜索的结点flag都为1 则一致；
{
    if(b->flag)   //已访问过
    {
        if(v<b->data)
            return check(b->left,v);
        else if(v>b->data)
            return check(b->right,v);
        else return 0;   //出现了2次肯定不一致
    }
    else
    {
        if(v==b->data)
            {
                b->flag=1;
                return 1;
            }
        else
            return 0;
    }
}

int judge(TREE b,int n)
{
    int flag=0;   //等于1则序列与树不一致
    int i,v;
    scanf("%d",&v);
    if(v!=b->data)
        flag=1;
    else
        b->flag=1;
    for(i=1;i<n;i++)
    {
        scanf("%d",&v);
        if(flag!=1&&check(b,v)==0)
            flag=1;
    }
    if(flag)
        return 0;
    else
        return 1;
}
void resetflag(TREE b)
{
    if(b->left)
        resetflag(b->left);
    else if(b->right)
        resetflag(b->right);
    b->flag=0;
}

void freetreep(TREE b)
{
    if(b->left)
        freetreep(b->left);
    else if(b->right)
        freetreep(b->right);
    free(b);
}

int main()
{
    int n,m;
    TREE p;
    int i;
    scanf("%d",&n);
    while(n)
    {
        scanf("%d",&m);
        p=creanttree(n);
        for(i=0;i<m;i++)
        {
            if(judge(p,n))
                printf("Yes\n");
            else
                printf("No\n");
            resetflag(p);
        }
        freetreep(p);
        scanf("%d",&n);
    }
}
