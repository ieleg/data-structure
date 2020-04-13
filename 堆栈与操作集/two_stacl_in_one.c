#include"stdio.h"
#include"stdlib.h"
#define max 5
//两个堆栈用一个数组实现，两个堆栈分别从两端开始，当top1-top2=1时两个栈都用完了

typedef char element;
typedef struct stack_* st;   //不用指针
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
    if((s->top2)-s->top1==0)//=1还剩一个位置
    {
        printf("堆栈已满\n");
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
            printf("堆栈已空\n");
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
            printf("堆栈已空\n");
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

    printf("入2栈一个a\n");
    push_a('a',p,2);
    print(p);
    printf("入2栈一个b\n");
    push_a('b',p,2);
    print(p);
    printf("入2栈一个d\n");
    push_a('d',p,2);
    print(p);
    printf("入1栈一个e\n");
    push_a('e',p,1);
    print(p);
     printf("入1栈一个f\n");
    push_a('f',p,1);
    print(p);
     printf("入1栈一个q\n");
    push_a('q',p,1);
    print(p);
     printf("1出栈\n");
    pop_a(p,1);
    print(p);
    printf("2出栈\n");
    pop_a(p,2);
    print(p);
    printf("1出栈\n");
    pop_a(p,1);
    print(p);
}
