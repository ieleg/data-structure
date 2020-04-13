#include"stdio.h"
#include"stdlib.h"
typedef int element;
typedef struct tree *bt;
struct tree
{
    element data;
    bt left;
    bt right;
};
typedef bt position;


bt find_(element x,bt b)//和根结点作比较
{
    /*
    if(!b)
    {
        return NULL
    }
    if(x>b->data)
    {
        return(find_(x,b->right));

    }
   else if(x<b->data)
    {
        return(find_(x,b->left));

    }
    else
        return b;
    */
    while(b)
    {
        if(x>b->data)
        {
            return(find_(x,b->right));

        }
        else if(x<b->data)
        {
            return(find_(x,b->left));

        }
        else
            return b;
    }
    return NULL;

}

bt find_max(bt b)
{
    if(b)
    {
        while(b->right)
        {
            b=b->right;
        }
    }
    return b;
}

bt find_min(bt b)
{
    if(b)
    {
        while(b->left)
        {
            b=b->left;
        }
    }
    return b;
}

bt insert_(element x,bt b)//关键插入到应该的位置
{
    if(!b)
    {
        b=(bt)malloc(sizeof(struct tree));
        b->data=x;
        b->left=b->right=NULL;
    }
    else
    {
        if(x<=b->data)
        {
            b->left=insert_(x,b->left);
        }
        else if(x>b->data)
        {
            b->right=insert_(x,b->right);
        }
    }
    return b;
}
void midprint(bt b)
{
    if(b)
    {
        midprint(b->left);
        printf("%d ",b->data);
        midprint(b->right);

    }
}
int main()
{
    bt p,q;
    p=(bt)malloc(sizeof(struct tree));
    p=NULL;
    p=insert_(1,p);
    p=insert_(2,p);
    p=insert_(3,p);
    p=insert_(3,p);
     p=insert_(13,p);
      p=insert_(23,p);
       p=insert_(333,p);
        p=insert_(13,p);
         p=insert_(233,p);
          p=insert_(1233,p);
           p=insert_(13,p);
            p=insert_(33,p);
             p=insert_(43,p);
              p=insert_(13,p);
               p=insert_(113,p);
                p=insert_(43,p);
    midprint(p);
    return 0;
}
