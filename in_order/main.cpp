#include<stdio.h>
int count;                                                          //����ȫ�ֱ�������Ϊ����������ʱ������
void SInsert(int num[],int count)                                                   //ֱ�Ӳ�������
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
int Qsort(int num[],int start,int end)                                                //��������
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
void SSort(int num[],int count)                                                         //��ѡ������
{
    int temp,Temp;                                                                      //temp��¼��С�߱�ţ�Temp��¼��С��ֵ
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
    printf("���������������\n");
    scanf("%d",&count);
    int num[count+1];
    printf("��������Ҫ���������\n");
    for(int i = 1;i <= count ;i++)
        scanf("%d",&num[i]);
    printf("��ѡ�����򷽷���\n1.ֱ�Ӳ��� \n2.��������\n3.������\n");
    int x;
    scanf("%d",&x);
    printf("����Ϊ������̣�\n");
    switch (x)                                                                              //ѡ��ͬ�����򷽷�
    {
    case 1:SInsert(num,count); break;
    case 2:Qsort(num,1,count);break;
    case 3:SSort(num,count);break;
    default: printf("�Ƿ����룡��");
    }
    printf("���Ϊ��\n");
    for(int i = 1;i <= count ;i++)
        printf("%d  ",num[i]);
        return 0;
}