#include<stdio.h>
int key;
int QSort(int num[],int start,int end)
{
    int low = start;
    int high = end;
    key = num[low];
    while (low < high)
    {
        while(num[high] >= key && high > low) high--;
        num[low] = num[high];
        while(num[low] <= key && low < high) low++;
        num[high] = num[low];
    }
    num[high] = key;
    if(low != start)  QSort(num,1,low-1);
    if(high != end)   QSort(num,high+1,end);
    return 0;
}
int main()
{
    int count;
    scanf("%d",&count);
    int num[count+1];
    for(int i = 1;i <= count ;i++)
        scanf("%d",&num[i]);
    QSort(num,1,count);
    for(int i = 1;i <= count ;i++)
        printf("%d  ",num[i]);
        return 0;
}