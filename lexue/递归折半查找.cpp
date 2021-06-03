#include<stdio.h>
int search(int a[],int high,int low,int obj){
    int mid = (high+low)/2;
    if(mid == high ||mid == low) return -1;
    if(a[mid] == obj) return mid;
    if(a[mid] > obj) return search(a,mid,low,obj);
    if((a[mid] < obj)) return search(a,high,mid,obj);
}
int main()
{
    int count;
    printf("请输入数据串长度\n");
    scanf("%d",&count);
    int a[count];
    printf("输入数据串\n");
    for (int i = 0; i < count; i++)
        scanf("%d",&a[i]);
    int obj,pos;
    printf("输入查找对象\n");
    scanf("%d",&obj);
    int high = count-1 ,low = 0;
    pos = search(a,high,low,obj);
    if(pos != -1)
        printf("数据位于第%d个位置\n",pos+1);
    else
        printf("不存在查找对象！\n");
    return 0;
}