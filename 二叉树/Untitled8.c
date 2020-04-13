#include"stdio.h"
#include"stdlib.h"

/*
���밴����ȸ�С���ұȸ���
ɾ�� 1ɾ����������� ֱ�ӱ�NULL
    2 ɾ������е����������������ڵ�ָ�����Ӷ���
    3 ɾ���ڵ������Ҷ��ӣ�ȡɾ���ڵ�����������С��ȡ�����������Ϊ���ڵ�

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
void mid_fei(bt b)         //ǰ��
{

    struct tree * a[20];//����һ��˳��ջ

                        //��pΪNULL����ջΪ��ʱ���������������
    while (b || top!=-1) {
                        //���p��ΪNULL������ѹջ��������������
        if (b) {

            pushstack(a,b);
            printf("%d ",b->data);
            b=b->left;
        }
                        //���p==NULL������������������ɣ���Ҫ������һ�����������
        else{
            b=getnode(a);
            popstack(a);
            b=b->right;
        }
    }

}

bt find_(element x,bt b)//�͸�������Ƚ�
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

bt insert_(element x,bt b)//�ؼ����뵽Ӧ�õ�λ��
{
    if(!b)  //��һ�β���
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
    else //�ҵ�Ҫɾ���Ľ��
    {
        if(b->left&&b->right)  //Ҫɾ���Ľ������������
        {
            temp=find_min(b->right);//�ҵ���������С��Ԫ�أ�
            b->data=temp->data;
            b->right=delete_(b->data,b->right);
        }
        else   //Ҫɾ���Ľ����1�����ӻ����޶���
        {
            temp=b;
            if(b->left==NULL) //���Ҷ��ӻ���
            {
                b=b->right;
            }
             else if(b->left==NULL) //���Ҷ��ӻ���
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

    printf("�ǵݹ�ǰ�����\n");
    mid_fei(p);
    printf("\n�ݹ��������\n");
    midprint(p);
    p=delete_(6,p);
    printf("\n�ǵݹ�ǰ�����\n");
    mid_fei(p);
    printf("\n�ݹ��������\n");
    midprint(p);
  /*
            4
         2     7
       1   3  5
*/

    p=delete_(2,p);

    printf("\n�ǵݹ�ǰ�����\n");
    mid_fei(p);
    printf("\n�ݹ��������\n");
    midprint(p);
      /*
            4
         3     7
       1     5
*/
    return 0;
}
