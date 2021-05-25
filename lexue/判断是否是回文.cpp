#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char *base;
    char *top;
}stack;
int main()
{
    char _;
    stack s;
    s.base = s.top = (char*)malloc(20*sizeof(stack));
    while ((_ = getchar()) != '\n')
    {
        *s.top=_;
        s.top++;
    }
    while (s.base <= s.top)
    {
        if (*s.base++ != *--s.top) {printf("不是回文\n");return 0;}
    }
    printf("是回文\n");
    return 0;
}