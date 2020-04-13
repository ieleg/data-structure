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

void push_a(element data,st b)  //链表无放满的情况
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
        printf("堆栈已清空\n");
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
    b=b->next;  //头结点不打印

    while(b!=NULL)  //第一个节点不纳入范围
    {

        printf("%d ",b->data);
        b=b->next;

    }
    printf("\n");
}

int main()
{
    st p=creatstack();

    printf("入栈一个5\n");
    push_a(5,p);
    print(p);
    printf("入栈一个1\n");
    push_a(1,p);
    print(p);
    printf("入栈一个25\n");
    push_a(25,p);
    print(p);
    printf("入栈一个15\n");
    push_a(15,p);

    printf("出栈\n");
    pop_a(p);
     print(p);
    printf("出栈\n");
    pop_a(p);
     print(p);
    printf("出栈\n");
    pop_a(p);
     print(p);
    printf("出栈\n");
    pop_a(p);
     print(p);
     printf("出栈\n");
    pop_a(p);
     print(p);
}
