#include"stdio.h"
int a[100];
int find_max(int *a,int n)//计算所有子列和
{
    int ThisSum,MaxSum=0;
    int i,j,k;
        for(j=0;j<n;j++)
            {
                ThisSum=0;
                for(k=j;k<n;k++)
                    ThisSum+=a[k];
                if(ThisSum>MaxSum)
                    MaxSum=ThisSum;
            }

    return MaxSum;
}

int find_dongtai(int a[],int n)
{
    int thissum,maxsum,i;
    thissum=maxsum=0;
    for(i=0;i<n;i++)
    {
        thissum+=a[i];
        if(thissum>maxsum)
            maxsum=thissum;
        else if(thissum<0)
            thissum=0;
    }
    return maxsum;
}
int main()

{
    int n;
    int i;
    int t;
    while(scanf("%d",&n)==1&&n!=0)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        t=find_dongtai(a,n);
        printf("%d\n",t);
    }
}
