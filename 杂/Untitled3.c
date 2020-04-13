#include<stdio.h>
#include <stdlib.h>
void change1(int* p)
{
    *p=2;
}

void change2(int p)
{
    p=2;
}


int main()
{
    int a=10;
    int b=10;
    change1(&a);
    change2(b);
    printf("%d\n",a);
    printf("%d\n",b);

    return 0;
}
