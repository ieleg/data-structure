#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define max 6
//����������ʵ��
//ѭ������ֻ��max-1���ռ�
//Ϊ��ֱ�۰ѿ�λ��0
//����ͷ�����һ��0��λ��
typedef int element;
struct queue_
{
    element a[max];
    int head;
    int end;
};
typedef struct queue_* que;

que creatque()
{
    que z=(que)malloc(sizeof(struct queue_));
    z->head=0;
    z->end=0;
    memset(z->a,0,sizeof(element)*6);
}

int if_full(que q)
{
    if((q->end+1)%max==q->head)
    {
        return 1;
    }
    else
        return 0;
}

int if_empty(que q)
{
    if(q->end==q->head)
    {
        return 1;
    }
    else
        return 0;
}

void add(element data,que b)
{
    if(if_full(b))
    {
        printf("��������\n");
        return NULL;
    }
    else
    {
        b->end=( b->end+1)%max;
        b->a[b->end]=data;
    }
}

element delete_(que b)
{
    if(if_empty(b))
    {
        printf("�����ѿ�\n");
        return NULL;
    }
    else
    {
        b->head=(b->head+1)%max;
         b->a[b->head]=0;
        return b->a[(b->head)];
    }
}

void prinque(que w)
{
    int i=0;
    for(i=0;i<max;i++)
    {
        printf("%d ",w->a[i]);

    }
    printf("\n");
}
int main()
{
    int i;
    element k;
    element ele;
    que s=creatque();
    printf("���һ��1\n");
    add(1,s);
    prinque(s);

    printf("���һ��3\n");
    add(3,s);
    prinque(s);

    printf("���һ��11\n");
    add(11,s);
    prinque(s);

    printf("���һ��11\n");
    add(11,s);
    prinque(s);

    printf("���һ��11\n");
    add(12,s);
    prinque(s);

      printf("����һ��\n");
   delete_(s);
    prinque(s);

    printf("���һ��111\n");
    add(111,s);
    prinque(s);

     printf("���һ��221\n");
    add(221,s);
    prinque(s);

    printf("����һ��\n");
   delete_(s);
    prinque(s);

     printf("���һ��221\n");
    add(221,s);
    prinque(s);

    printf("����һ��\n");
   delete_(s);
    prinque(s);


    return 0;
}


