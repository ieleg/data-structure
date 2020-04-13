#include"stdio.h"
#include"stdlib.h"
typedef char element;
typedef struct tree *bt;
struct tree
{
    element data;
    bt left;
    bt right;
};
typedef bt position;

void creat(bt *b)  //修改头结点所以用指针指针
{
    char c;
    scanf("%c",&c);
    if(' '==c )
    {
        (*b)=NULL;
    }
    else
    {
        (*b)=(bt)malloc(sizeof(struct tree));
        (*b)->data=c;
        creat(&((*b)->left));
        creat(&((*b)->right));
    }
}

bt creatb(bt b)  //递归太慢了
{
    char c;
    scanf("%c",&c);
    if(' '==c )
    {
        (b)=NULL;

    }
    else
    {
        (b)=(bt)malloc(sizeof(struct tree));
        (b)->data=c;
        b->left=creatb(b->left);
        b->right=creatb(b->right);

    }
    return b;
}

void midprint(bt b)
{
    if(b)
    {

        printf("%c ",b->data);
        midprint(b->left);
        midprint(b->right);

    }
}

int main()
{
    bt q=NULL;

    q=creatb(q);
    midprint(q);
    return 0;
}
