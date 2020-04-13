#include"stdio.h"
#include"stdlib.h"
#define maxdata 1000
typedef int element;

struct heapstruct
{
	element*ele;  //数组
	int size;      //元素个数
	int capacity;   //堆的最大容量
};

struct heapstruct* creat(int n)   //创建一个空集
{
    struct heapstruct *s;
    s=(struct heapstruct*)malloc(sizeof(struct heapstruct));
    s->ele=malloc(sizeof(element)*(n+1));
    s->ele[0]=maxdata;              //建一个哨兵
    s->capacity=n;
    s->size=0;
    return s;
};

/*
大堆
插入的结点与其父节点比较，若比他小则插在它下面
若比他大，则插入位置的结点等于其父节点的值，在与其父节点作比较

*/
struct heapstruct* inser(struct heapstruct*b,element data)
{
    int i;
    if(b->size==b->capacity)
    {
        printf("满了\n");
        return;
    }
    i=++(b->size);

    for(;b->ele[i/2]<data;i/=2)  //如果父节点小于插入的元素，i下标指向父节点
    {
        b->ele[i]=b->ele[i/2];
    }
    b->ele[i]=data;
    return b;
}
/*
取出最大元素并删除一个元素
取出数组最后一个值当做哨兵的子节点
比较左右儿子大小，如果父节点比大的儿子大，退出并保存位置的下标，如果父节点比大的儿子小，大的儿子就代替父节点，
在比较大的儿子结点的左右儿子，
直到最后把数组最后一个值赋给保存下标的结点
*/
element delet(struct heapstruct*b)
{
    int parent,child;
    element maxnode,t;
    if(b->size==0)
    {
        printf("空了\n");
        return;
    }
    maxnode=b->ele[1];//返回最大值
    t=b->ele[b->size--];       //数组最后一个元素
    for(parent=1;parent*2<=b->size;parent=child)        //在循环里parent指向的是childd的父节点
    {
        child=parent*2;  //左儿子位置
        if(child!=b->size&&b->ele[child]<b->ele[child+1])//父节点没有只有一个左儿子且右儿子大
        {
            child++;//右儿子位置
        }
        if(t>=b->ele[child])//如果数组最后一个元素比该结点大则退出循环
            break;
        else
            b->ele[parent]=b->ele[child];
    }
    b->ele[parent]=t;
    return maxnode;
};
struct heapstruct* new_(int n,struct heapstruct*b)//顺序输入建立堆
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
    for(parent=i;parent*2<=b->size;parent=child)        //在循环里parent指向的是childd的父节点
    {
        child=parent*2;  //左儿子位置
        if(child!=b->size&&b->ele[child]<b->ele[child+1])//父节点没有只有一个左儿子且右儿子大
        {
            child++;//右儿子位置
        }
        if(t>=b->ele[child])//如果数组最后一个元素比该结点大则退出循环
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
        for(parent=i;parent*2<=b->size;parent=child)        //在循环里parent指向的是childd的父节点
        {
            child=parent*2;  //左儿子位置
            if(child<b->size&&b->ele[child]<b->ele[child+1])//父节点没有只有一个左儿子且右儿子大
            {
                child++;//右儿子位置
            }
            if(t>=b->ele[child])//如果数组最后一个元素比该结点大则退出循环
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
