#include"stdio.h"
#include"stdlib.h"
#define max 5
//������ջ��һ������ʵ�֣�������ջ�ֱ�����˿�ʼ����top1-top2=1ʱ����ջ��������

typedef char element;
typedef struct stack_* st;   //����ָ��
struct stack_
{
    element a[max];
    int top1;
    int top2;
};

void init(st s)
{
    s->top1=-1;
    s->top2=max-1;
}

void push_a(element ele,st s,int flag)
{
    if((s->top2)-s->top1==0)//=1��ʣһ��λ��
    {
        printf("��ջ����\n");
    }
    else if(flag==1)
    {
        s->top1+=1;
        s->a[s->top1]=ele;

    }
    else if(flag==2)
    {
       s->top2-=1;
        s->a[s->top2]=ele;
    }
}

element pop_a(st b,int flag)
{
    element i;
    if(flag==1)
    {
        if(b->top1==-1)
        {
            printf("��ջ�ѿ�\n");
        }
        else
        {

            return b->a[(b->top1)--];

        }
    }
    else if(flag==2)
    {
       if(b->top2==max-1)
        {
            printf("��ջ�ѿ�\n");
        }
        else
        {

            return b->a[(b->top2)++];
        }
    }
}
void print(st b)
{
    int i;
    for(i=0;i<=b->top1;i++)
    {
        printf("%c ",b->a[i]);
    }
    printf("\n");
      for(i=max-2;i>=b->top2;i--)
    {
        printf("%c ",b->a[i]);
    }
    printf("\n");
}

int main()
{
    int i;
    element k;
    st p;
    p=(st)malloc(sizeof(struct stack_));
    init(p);

    printf("��2ջһ��a\n");
    push_a('a',p,2);
    print(p);
    printf("��2ջһ��b\n");
    push_a('b',p,2);
    print(p);
    printf("��2ջһ��d\n");
    push_a('d',p,2);
    print(p);
    printf("��1ջһ��e\n");
    push_a('e',p,1);
    print(p);
     printf("��1ջһ��f\n");
    push_a('f',p,1);
    print(p);
     printf("��1ջһ��q\n");
    push_a('q',p,1);
    print(p);
     printf("1��ջ\n");
    pop_a(p,1);
    print(p);
    printf("2��ջ\n");
    pop_a(p,2);
    print(p);
    printf("1��ջ\n");
    pop_a(p,1);
    print(p);
}
