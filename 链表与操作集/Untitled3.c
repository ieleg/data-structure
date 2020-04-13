#include"stdio.h"
#include"stdlib.h"
//在index-1后插入 指针变量b作为参数传入的时候被修改无效，因此需要用指向b的指针

typedef struct Lnode
{
    int a;
    struct Lnode* next;

}List;


List* Init()
{
    int i,n;
    float k1,k2;
    List *head,*end,*Lnew;

    printf("输入节点个数: ");
    scanf("%d",&n);
    Lnew=(List*)malloc(sizeof(List));
    printf("输入节点元素: ");
    scanf("%d",&Lnew->a);
    head=end=Lnew;
    for(i=1;i<n;i++)
    {
       Lnew=(List*)malloc(sizeof(struct Lnode));
       scanf("%d",&Lnew->a);
       end->next=Lnew;
       end=Lnew;
    }	
    end->next=NULL;

  //  printf("%f",(k2-k1)/1e7);
    return head;

}

List* find_element(int index,List* b)
{
    int i=1;
    List* p=b;
    while(i<index&&p!=NULL)
    {
        p=p->next;
        i++;
    }
    return p;
}

void insert_a(int data,int index,List**b)  //在index-1后插入 指针变量b作为参数传入的时候被修改无效，因此需要用指向b的指针
{
    int i;
    List* p;
    List* pnew;
    if(index==1)
    {
        pnew=(List*)malloc(sizeof(struct Lnode));
        pnew->a=data;
        pnew->next=*b;
        *b=pnew;
        return NULL;

    }
     p= find_element(index-1,*b);
    if(p==NULL)
    {
        printf("序号超范围");

    }
    else
    {
          pnew=(List*)malloc(sizeof(struct Lnode));
            pnew->a=data;
            pnew->next=p->next;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!不能交换
            p->next=pnew;
           // b=pnew;
           //return b;  2019年12月8日21:34:27
    }
}

void delete_a(int index,List* b)//在index-1后插入
{
    List* p,*q;
    q=find_element(index-1,b);
    p=q->next;
    q->next=p->next;
    free(p);

}

int len(List* b)
{
    List*p=b;
    int i=0;
    while(p!=NULL)
    {
        p=p->next;
        i++;
    }
    return i;
}
void print(List* p)
{

    while(p!=NULL)
    {
        printf("%d ",p->a);
        p=p->next;
    }
}
int main()
{
    int n,i,j,k;
    List*p;
    float k1,k2;

    p=Init(n);
    while(1)
    {
        printf("选择功能0查找 1插入 2删除 3返回长度: ");
        scanf("%d",&i);
        if(i==0)
            {

                printf("查找序号: ");
                scanf("%d",&i);
                p=find_element(i,p);
                printf("查找元素值: %d\n",p->a);

               //  printf("%f",(k2-k1)/1e7);
            }
        else if(i==1)
        {

               printf("插入元素值: ");
                scanf("%d",&i);
                printf("插入序号位置: ");
                scanf("%d",&j);
                insert_a(i,j,&p);
                print(p);
                printf("\n");

               //  printf("%f",(k2-k1)/1e7);
        }
        else if(i==2)
        {

               printf("删除序号位置: ");
                scanf("%d",&j);
                delete_a(j,p);
                print(p);
                printf("\n");

               //  printf("%f",(k2-k1)/1e7);
        }
        else if(i==3)
        {

               printf("链表长度: ");
                i=len(p);
                printf("%d\n",i);

               //  printf("%f",(k2-k1)/1e7);
        }
    }
    return 0;
}


