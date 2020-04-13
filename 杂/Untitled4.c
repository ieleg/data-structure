#include"stdio.h"
int main()
{
    char *str="abcdefg";
    int *a=(int *)str;
    int aa=65536;
    char p=1;
    int *jj;
    int i=1;
    int ad=i++;
    printf("%c\n%c",*(str+1),(char *)(a+1));
    printf("%d %d",sizeof(aa),sizeof(jj));
    printf("%d",ad);
}
