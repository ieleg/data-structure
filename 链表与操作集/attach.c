#include"stdio.h"

#include"stdlib.h"
//attach插入后b是尾指针
//遍历时需要删除头指针 因为是带头结点的
typedef int elemType;//定义存入的数据的类型可以是int char

struct NODE{ //定义链表的结构类型
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
    b=b->next;              //删除头结点

    while(b!=NULL)  //第一个节点不纳入范围
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

