#include"stdio.h"
#include"stdlib.h"
//��index-1����� ָ�����b��Ϊ���������ʱ���޸���Ч�������Ҫ��ָ��b��ָ��

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

    printf("����ڵ����: ");
    scanf("%d",&n);
    Lnew=(List*)malloc(sizeof(List));
    printf("����ڵ�Ԫ��: ");
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

void insert_a(int data,int index,List**b)  //��index-1����� ָ�����b��Ϊ���������ʱ���޸���Ч�������Ҫ��ָ��b��ָ��
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
        printf("��ų���Χ");

    }
    else
    {
          pnew=(List*)malloc(sizeof(struct Lnode));
            pnew->a=data;
            pnew->next=p->next;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!���ܽ���
            p->next=pnew;
           // b=pnew;
           //return b;  2019��12��8��21:34:27
    }
}

void delete_a(int index,List* b)//��index-1�����
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
        printf("ѡ����0���� 1���� 2ɾ�� 3���س���: ");
        scanf("%d",&i);
        if(i==0)
            {

                printf("�������: ");
                scanf("%d",&i);
                p=find_element(i,p);
                printf("����Ԫ��ֵ: %d\n",p->a);

               //  printf("%f",(k2-k1)/1e7);
            }
        else if(i==1)
        {

               printf("����Ԫ��ֵ: ");
                scanf("%d",&i);
                printf("�������λ��: ");
                scanf("%d",&j);
                insert_a(i,j,&p);
                print(p);
                printf("\n");

               //  printf("%f",(k2-k1)/1e7);
        }
        else if(i==2)
        {

               printf("ɾ�����λ��: ");
                scanf("%d",&j);
                delete_a(j,p);
                print(p);
                printf("\n");

               //  printf("%f",(k2-k1)/1e7);
        }
        else if(i==3)
        {

               printf("������: ");
                i=len(p);
                printf("%d\n",i);

               //  printf("%f",(k2-k1)/1e7);
        }
    }
    return 0;
}


