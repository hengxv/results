#include<stdio.h>
int main()
{
    int m,n;
    while (scanf("%d %d",&m,&n) != EOF)
    {
        
        int num[m+1];
        for(int i = 1;i <= m;i++) scanf("%d",&num[i]);
        if(m < n) {printf("ERROR\n");continue;}
        for(int i = 2;i <= m ;i++)
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
        for (int i = m; i > m-n; i--)
            if(i != m) printf(" %d",num[i]);
            else printf("%d",num[i]);
        printf("\n");
    }
    
}