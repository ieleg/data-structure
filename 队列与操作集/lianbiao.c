#include"stdio.h"
#include"stdlib.h"

//不带头结点的单向链表实现
//头结点删除、尾节点删除
//2019年12月8日22:23:31
typedef int element;
struct node_
{
    element a;
    struct li_que* next;
};
struct li_que
{
    struct node_ *head;
    struct node_ *end;

};
typedef struct li_que* que;

que crea()
{
    que s=(que)malloc(sizeof(struct li_que));
    s->head=s->end=NULL;
    return s;
}

void add(element data,que b)
{
    struct node_* qnew=(struct node_*)malloc(sizeof(struct node_));
    qnew->a=data;
    qnew->next=NULL;
    if(b->end==NULL)   //如果刚初始化
    {
        b->end=qnew;
        b->head=qnew;
    }
    else
    {
        b->end->next=qnew;
        b->end=qnew;
    }

}
element delete_v(que d)
{
    struct node_*p;
    element k;
    if(d->head==NULL)
    {
        printf("已空\n");
        return NULL;
    }
    p=d->head;
    if(d->end==d->head) //only one elemnet
    {
        d->end=d->head=NULL;
    }
    else
    {
        d->head=p->next;
    }
    k=p->a;
    free(p);
    return k;
}

void print(que p)
{
    struct node_* q=p->head;
    while(q!=NULL)
    {

        printf("%d ",q->a);
        q=q->next;

    }
    printf("\n");
}

/*
void print(que p)
{

    while(p->head!=NULL)
    {

        printf("%d ",p->head->a);
        p->head=p->head->next;

    }
    printf("\n");
}
*/
int main()
{
    que s=crea();
    add(5,s);
    print(s);

    add(15,s);
    print(s);

    add(25,s);
    print(s);

    delete_v(s);
    print(s);

    add(432,s);
    print(s);

    delete_v(s);
    print(s);

    add(1125,s);
    print(s);

     delete_v(s);
    print(s);

     delete_v(s);
    print(s);

     delete_v(s);
    print(s);

     delete_v(s);
    print(s);
    return 0;
}
