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
    printf("���������ݴ�����\n");
    scanf("%d",&count);
    int a[count];
    printf("�������ݴ�\n");
    for (int i = 0; i < count; i++)
        scanf("%d",&a[i]);
    int obj,pos;
    printf("������Ҷ���\n");
    scanf("%d",&obj);
    int high = count-1 ,low = 0;
    pos = search(a,high,low,obj);
    if(pos != -1)
        printf("����λ�ڵ�%d��λ��\n",pos+1);
    else
        printf("�����ڲ��Ҷ���\n");
    return 0;
}