#include"stdio.h"
#include"stdlib.h"
#define MAX 1000
typedef struct node
{
    int a[MAX];
    int last;           //���һ��Ԫ���±�
}*List;
List opppp;
void Init(int n)            //��ʼ��
{
    opppp=(List)malloc(sizeof(struct node));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&opppp->a[i]);
    }
    opppp->last=n-1;
}
int find_a_element(int data,List b)             //����ĳ��Ԫ��
{
    int i=0;
    while(data!=b->a[i])
    {
        i++;
    }
    return i;
}
void insert_a_element(int data,int situation,List b) //�ڵ�situation��λ���ϲ���һ��ֵ
{
    int i;
    for(i=b->last;i>=situation-1;i--)
    {
        b->a[i+1]=b->a[i];
    }
    b->a[situation]=data;
    b->last+=1;

}

void delete_a_element(int situation,List b)
{
    int i;
    for(i=situation;i<=b->last;i++)
    {
        b->a[i-1]=b->a[i];
    }
    b->last--;

}

int main()
{
    int n;
    int t;
    printf("����Ԫ�صĸ���:");
    scanf("%d",&n);
    Init(n);
    insert_a_element(0,3,opppp);
    insert_a_element(122,4,opppp);
    delete_a_element(1,opppp);
    for(int i=0;i<=opppp->last;i++)
    {
        printf("%d ",opppp->a[i]);
    }
    printf("\n");
     t=find_a_element(3,opppp);
     printf("���ҵ�λ����%d\n ",t+1);


}

