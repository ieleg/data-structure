#include"stdio.h"
#include"stdlib.h"
#define maxdata 1000
typedef int element;

struct heapstruct
{
	element*ele;  //����
	int size;      //Ԫ�ظ���
	int capacity;   //�ѵ��������
};

struct heapstruct* creat(int n)   //����һ���ռ�
{
    struct heapstruct *s;
    s=(struct heapstruct*)malloc(sizeof(struct heapstruct));
    s->ele=malloc(sizeof(element)*(n+1));
    s->ele[0]=maxdata;              //��һ���ڱ�
    s->capacity=n;
    s->size=0;
    return s;
};

/*
���
����Ľ�����丸�ڵ�Ƚϣ�������С�����������
�������������λ�õĽ������丸�ڵ��ֵ�������丸�ڵ����Ƚ�

*/
struct heapstruct* inser(struct heapstruct*b,element data)
{
    int i;
    if(b->size==b->capacity)
    {
        printf("����\n");
        return;
    }
    i=++(b->size);

    for(;b->ele[i/2]<data;i/=2)  //������ڵ�С�ڲ����Ԫ�أ�i�±�ָ�򸸽ڵ�
    {
        b->ele[i]=b->ele[i/2];
    }
    b->ele[i]=data;
    return b;
}
/*
ȡ�����Ԫ�ز�ɾ��һ��Ԫ��
ȡ���������һ��ֵ�����ڱ����ӽڵ�
�Ƚ����Ҷ��Ӵ�С��������ڵ�ȴ�Ķ��Ӵ��˳�������λ�õ��±꣬������ڵ�ȴ�Ķ���С����Ķ��Ӿʹ��游�ڵ㣬
�ڱȽϴ�Ķ��ӽ������Ҷ��ӣ�
ֱ�������������һ��ֵ���������±�Ľ��
*/
element delet(struct heapstruct*b)
{
    int parent,child;
    element maxnode,t;
    if(b->size==0)
    {
        printf("����\n");
        return;
    }
    maxnode=b->ele[1];//�������ֵ
    t=b->ele[b->size--];       //�������һ��Ԫ��
    for(parent=1;parent*2<=b->size;parent=child)        //��ѭ����parentָ�����childd�ĸ��ڵ�
    {
        child=parent*2;  //�����λ��
        if(child!=b->size&&b->ele[child]<b->ele[child+1])//���ڵ�û��ֻ��һ����������Ҷ��Ӵ�
        {
            child++;//�Ҷ���λ��
        }
        if(t>=b->ele[child])//����������һ��Ԫ�رȸý������˳�ѭ��
            break;
        else
            b->ele[parent]=b->ele[child];
    }
    b->ele[parent]=t;
    return maxnode;
};
struct heapstruct* new_(int n,struct heapstruct*b)//˳�����뽨����
{
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b->ele[i]);
    }
    b->size=n;
    return b;
};
struct heapstruct* adjust_single(struct heapstruct*b,int i)
{
    element t;
    int parent,child;
    t=b->ele[i*2];
    for(parent=i;parent*2<=b->size;parent=child)        //��ѭ����parentָ�����childd�ĸ��ڵ�
    {
        child=parent*2;  //�����λ��
        if(child!=b->size&&b->ele[child]<b->ele[child+1])//���ڵ�û��ֻ��һ����������Ҷ��Ӵ�
        {
            child++;//�Ҷ���λ��
        }
        if(t>=b->ele[child])//����������һ��Ԫ�رȸý������˳�ѭ��
            break;
        else
            b->ele[parent]=b->ele[child];
    }
    b->ele[parent]=t;
    return b;
};

struct heapstruct* adjust(struct heapstruct*b)
{
   int i;
    element t;
    int parent,child;
    i=(b->size)/2;
    t=b->ele[i*2];

   for(;i>0;i--)
   {
       t=b->ele[i];
        for(parent=i;parent*2<=b->size;parent=child)        //��ѭ����parentָ�����childd�ĸ��ڵ�
        {
            child=parent*2;  //�����λ��
            if(child<b->size&&b->ele[child]<b->ele[child+1])//���ڵ�û��ֻ��һ����������Ҷ��Ӵ�
            {
                child++;//�Ҷ���λ��
            }
            if(t>=b->ele[child])//����������һ��Ԫ�رȸý������˳�ѭ��
                break;
            else
                b->ele[parent]=b->ele[child];
        }
        b->ele[parent]=t;

   }
   return b;
};



void print(struct heapstruct*b)
{
   int i;
   for(i=0;i<=b->size;i++)
   {
       printf("%d\n",b->ele[i]);
   }

}

int main()
{
    struct heapstruct*b;
        b=creat(10);
//    b=inser(b,3);
//    b=inser(b,1);
//    b=inser(b,31);
//    b=inser(b,12);
//    b=inser(b,113);
//    b=inser(b,7);
//    b=inser(b,35);
//    b=inser(b,17);
    b=new_(b->capacity,b);
    b=adjust(b);
    print(b);
//    printf("shan");
//    delet(b);
//       print(b);
//       printf("shan");
//       delet(b);
//       print(b);
       printf("shan");
       delet(b);
       print(b);
    return 0;
}
