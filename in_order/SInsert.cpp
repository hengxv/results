#include<stdio.h>
int main()
{
    int count;
    scanf("%d",&count);
    int num[count+1];
    for(int i = 1;i <= count ;i++)
        scanf("%d",&num[i]);
    
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
    }
    for(int i = 1;i <= count ;i++)
        printf("%d  ",num[i]);
        return 0;
}