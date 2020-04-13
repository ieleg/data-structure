#include"stdio.h"

void max(int b[])
{
    int *aa=b;
    b[1]=12;
}

int main()
{
    int a[]={1,2,3,4,5};
    max(a);
    for(int i=0;i<5;i++)
        printf("%d ",a[i]);
}
