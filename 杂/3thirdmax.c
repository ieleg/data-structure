#include <stdio.h>



int find(int max, int n, int num[])

{

    int i = 0,max_t = 0;

    while(i < n){

        if(max_t < num[i] && num[i] < max)

            max_t = num[i];

        i++;

    }

    return max_t;

}



int main(int argc, char *argv[])

{

    int i,x,n;

    int max = 0;

    int num[] = {1,4,2,5,6,3,9,8};

    n = sizeof(num)/sizeof(int);

    printf("一共有%d个数\n",n);

    printf("请输入第几大的数：");

    scanf("%d",&x);

    for(i = 0; i < sizeof(num)/sizeof(int); i++)

        if(max < num[i])

            max = num[i];

    if(1 == x)

        printf("第%d大的数是：%d\n",x,max);

    else if(x > 1){

        for(i = 1; i < x; i++)

        max = find(max,n,num);

        printf("第%d大的数是：%d\n",x,max);

    }

    return 0;

}
