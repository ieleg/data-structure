#include"stdio.h"

#include"stdlib.h"
//attach�����b��βָ��
//����ʱ��Ҫɾ��ͷָ�� ��Ϊ�Ǵ�ͷ����
typedef int elemType;//�����������ݵ����Ϳ�����int char

struct NODE{ //��������Ľṹ����
    elemType element;
    struct NODE *next;
};
typedef struct NODE*list_;

list_ ini()
{
    list_ p=(list_)malloc(sizeof(struct NODE));
    p->next=NULL;
    return p;
}

void attach(elemType c,list_ *b)
{
    list_ a=(list_)malloc(sizeof(struct NODE));
    a->element=c;
    a->next=NULL;
    (*b)->next=a;
    *b=a;
}

void print(list_ b)
{
    b=b->next;              //ɾ��ͷ���

    while(b!=NULL)  //��һ���ڵ㲻���뷶Χ
    {

        printf("%d ",b->element);
        b=b->next;

    }
    printf("\n");
}
int main()
{
    int i;
    list_ p,s,t;
    p=ini();
    s=p;

    attach(1,&p);
    print(s);

    attach(2,&p);
    attach(1,&p);
    attach(3123,&p);
    print(s);

    attach(3,&p);
    print(s);

}

