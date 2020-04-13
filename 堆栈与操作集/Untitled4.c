#include"stdio.h"
#include"stdlib.h"
#define max 1000

typedef int element;
struct stack_
{
    element a[max];
    int top;
};
typedef struct stack_* st;

void init(st b)
{
    b->top=-1;
}

/*void panduan(st b)
{
    if(b->top==max-1)
    {
        printf("堆栈已满");
    }
    else if(b->top==-1)
    {
        printf("堆栈已空");
    }
}
*/

void push_a(element ele,st b)
{
    if(b->top==max-1)
    {
        printf("堆栈已满");
    }
    else
    {
        b->top+=1;
        b->a[b->top]=ele;

    }
}
element pop_a(st b)
{
    element i;
    if(b->top==-1)
    {
        printf("堆栈已空");
    }
    else
    {
       return b->a[b->top--];
    }
}
void print(st b)
{
    int i;
    for(i=0;i<=b->top;i++)
    {
        printf("%d ",b->a[i]);
    }
    printf("\n");
}
int main()
{
    int i;
    element k;
    element ele;
    st p;
    p=(st)malloc(sizeof(struct stack_));
    init(p);
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
    print(p);

    pop_a(p);
    print(p);

    return 0;
}
