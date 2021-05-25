#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int *base;
    int *top;
}stack;

int main()
{
    int count,num;
    stack s1,s2;
    scanf("%d",&count);
    s1.base=s1.top=(int*)malloc(count*sizeof(stack));
    s2.base=s2.top=(int*)malloc(count*sizeof(stack));
    for (int i = 1; i <= count; i++)
    {
        scanf("%d",&num);
        if (num%2 != 0){ *s1.top++ = num; }
        else *s2.top++ = num;
    }
    while (s1.base != s1.top && s2.top != s2.base)
    {
        printf("%d %d\n",*s1.base++,*s2.base++);
    }
    return 0;
}