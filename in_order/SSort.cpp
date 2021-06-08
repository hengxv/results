#include<stdio.h>
int main()
{
    int count;
    scanf("%d",&count);
    int num[count+1];
    for(int i = 1;i <= count ;i++)
        scanf("%d",&num[i]);
    
    int temp,Temp;
    for (int i = 1; i <= count; i++)
    {
        temp = i;
        Temp = num[i];
        for (int j = i+1; j <= count; j++)
            if(num[temp] > num[j]) 
                temp = j;
        num[i] = num[temp];
        num[temp] = Temp;
    }
    for(int i = 1;i <= count ;i++)
        printf("%d  ",num[i]);
        return 0;
}