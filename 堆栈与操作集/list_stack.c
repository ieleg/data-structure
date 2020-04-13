#include"stdio.h"
#include"stdlib.h"
typedef int element;
struct li_stack
{
    element data;
    struct li_stack* next;
};
typedef struct li_stack* st;


st creatstack()
{
    st p;
    p=(st)malloc(sizeof(struct li_stack));

    p->next=NULL;
    return p;
}

void push_a(element data,st b)  //�����޷��������
{
    st a;
    a=(st)malloc(sizeof(struct li_stack));
    a->data=data;
    a->next=b->next;
    b->next=a;
}

element pop_a(st b)
{
    st t;
    element k;
    t=(st)malloc(sizeof(struct li_stack));
    if(b->next==NULL)
    {
        printf("��ջ�����\n");
        return NULL;
    }
    t=b->next;
    b->next=t->next;
    k=t->data;
    free(t);

    return k;
}
void print(st b)
{
    b=b->next;  //ͷ��㲻��ӡ

    while(b!=NULL)  //��һ���ڵ㲻���뷶Χ
    {

        printf("%d ",b->data);
        b=b->next;

    }
    printf("\n");
}

int main()
{
    st p=creatstack();

    printf("��ջһ��5\n");
    push_a(5,p);
    print(p);
    printf("��ջһ��1\n");
    push_a(1,p);
    print(p);
    printf("��ջһ��25\n");
    push_a(25,p);
    print(p);
    printf("��ջһ��15\n");
    push_a(15,p);

    printf("��ջ\n");
    pop_a(p);
     print(p);
    printf("��ջ\n");
    pop_a(p);
     print(p);
    printf("��ջ\n");
    pop_a(p);
     print(p);
    printf("��ջ\n");
    pop_a(p);
     print(p);
     printf("��ջ\n");
    pop_a(p);
     print(p);
}
