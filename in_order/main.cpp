#include<stdio.h>
int count;                                                          //定义全局变量，是为了在输出结果时更方便
void SInsert(int num[],int count)                                                   //直接插入排序法
{
    for(int i = 2;i <= count ;i++)
    {
        num[0] = num[i];
        for (int j = i-1; j >= 0; j--)
        {
            if(num[0] < num[j]) 
                num[j+1] = num[j];
            if(num[0] >= num[j])
                {
                    num[j+1] = num[0];
                    break;
                }
        }
        for(int k = 1;k <= count ;k++)
            printf("%d  ",num[k]);
        printf("\n");
    }
}
int Qsort(int num[],int start,int end)                                                //快速排序法
{
    int low = start;                                                               
    int high = end;
    int key = num[low];
    while (low < high)
    {
        while(num[high] >= key && high > low) high--;
        num[low] = num[high];
        while(num[low] <= key && low < high) low++;
        num[high] = num[low];
    }
    num[high] = key;
    for(int i = 1;i <= count ;i++)
        printf("%d  ",num[i]);
    printf("\n");
    if(low != start)  Qsort(num,1,low-1);
    if(high != end && high+1 != end)   Qsort(num,high+1,end);
    return 0;
}
void SSort(int num[],int count)                                                         //简单选择排序
{
    int temp,Temp;                                                                      //temp记录最小者标号，Temp记录最小者值
    for (int i = 1; i <= count; i++)
    {
        temp = i;
        Temp = num[i];
        for (int j = i+1; j <= count; j++)
            if(num[temp] > num[j]) 
                temp = j;
        num[i] = num[temp];
        num[temp] = Temp;
        for(int k = 1;k <= count ;k++)
        printf("%d  ",num[k]);
        printf("\n");
    }
}
int main()
{
    printf("请输入排序个数：\n");
    scanf("%d",&count);
    int num[count+1];
    printf("请输入需要排序的数：\n");
    for(int i = 1;i <= count ;i++)
        scanf("%d",&num[i]);
    printf("请选择排序方法：\n1.直接插入 \n2.快速排序\n3.简单排序\n");
    int x;
    scanf("%d",&x);
    printf("以下为排序过程：\n");
    switch (x)                                                                              //选择不同的排序方法
    {
    case 1:SInsert(num,count); break;
    case 2:Qsort(num,1,count);break;
    case 3:SSort(num,count);break;
    default: printf("非法输入！！");
    }
    printf("结果为：\n");
    for(int i = 1;i <= count ;i++)
        printf("%d  ",num[i]);
        return 0;
}