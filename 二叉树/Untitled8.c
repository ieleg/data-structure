#include"stdio.h"
#include"stdlib.h"

/*
插入按照左比根小，右比根大
删除 1删除结点无子树 直接变NULL
    2 删除结点有单子树，单子树父节点指向其子儿子
    3 删除节点有左右儿子，取删除节点右子树里最小或取左子树最大作为父节点

*/
typedef int element;
typedef struct tree *bt;
int top=-1;
struct tree
{
    element data;
    bt left;
    bt right;
};

void pushstack(bt *b,bt a)
{
    b[++top]=a;
}
void popstack()
{
    if(top==-1)
        return;
    else
        top--;
}
bt getnode(bt *b)
{
    return b[top];
}
void mid_fei(bt b)         //前序
{

    struct tree * a[20];//定义一个顺序栈

                        //当p为NULL或者栈为空时，表明树遍历完成
    while (b || top!=-1) {
                        //如果p不为NULL，将其压栈并遍历其左子树
        if (b) {

            pushstack(a,b);
            printf("%d ",b->data);
            b=b->left;
        }
                        //如果p==NULL，表明左子树遍历完成，需要遍历上一层结点的右子树
        else{
            b=getnode(a);
            popstack(a);
            b=b->right;
        }
    }

}

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
    if(!b)  //第一次插入
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
bt delete_(element x,bt b)
{
    bt temp;
     if(x>b->data)
    {
        b->right=delete_(x,b->right);

    }
    else if(x<b->data)
    {
        b->left=delete_(x,b->left);
    }
    else //找到要删除的结点
    {
        if(b->left&&b->right)  //要删除的结点有两个儿子
        {
            temp=find_min(b->right);//找到右子树最小的元素；
            b->data=temp->data;
            b->right=delete_(b->data,b->right);
        }
        else   //要删除的结点有1个儿子或者无儿子
        {
            temp=b;
            if(b->left==NULL) //有右儿子或都无
            {
                b=b->right;
            }
             else if(b->left==NULL) //有右儿子或都无
            {
                b=b->left;
            }
            free(temp);
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
    return;
}
int main()
{
    bt p,q;
    p=(bt)malloc(sizeof(struct tree));
   q=(bt)malloc(sizeof(struct tree));
    p=NULL;
    p=insert_(4,p);
    p=insert_(2,p);
    p=insert_(6,p);
    p=insert_(1,p);
     p=insert_(3,p);
      p=insert_(5,p);
       p=insert_(7,p);
       /*
            4
         2     6
       1   3  5  7
       */

    printf("非递归前序遍历\n");
    mid_fei(p);
    printf("\n递归中序遍历\n");
    midprint(p);
    p=delete_(6,p);
    printf("\n非递归前序遍历\n");
    mid_fei(p);
    printf("\n递归中序遍历\n");
    midprint(p);
  /*
            4
         2     7
       1   3  5
*/

    p=delete_(2,p);

    printf("\n非递归前序遍历\n");
    mid_fei(p);
    printf("\n递归中序遍历\n");
    midprint(p);
      /*
            4
         3     7
       1     5
*/
    return 0;
}
