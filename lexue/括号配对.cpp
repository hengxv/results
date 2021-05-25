#include<stdlib.h>
#include<stdio.h>
typedef struct 
{
    char *base;
    char *top;
}stack;
int main()
{
    stack s;
    s.base=s.top=(char*)malloc(20*sizeof(stack));
    char _;
    while ((_=getchar()) != '\n')
    {
        if (_ == '{' || _ == '}' || _ == '(' || _==')' || _ == ']'|| _ == '[' )
        {
            if (s.base != s.top)
            {
                if((_ == ']'&& *(s.top-1) == '[')||(_ == ')'&& *(s.top-1) == '(')||(_ == '}'&& *(s.top-1) == '{')) s.top--;
                else *s.top++ =_;
            }
            else  *s.top++ =_;
        }
    }
    if (s.top == s.base) printf("¿®∫≈≈‰∂‘\n");
    else printf("¿®∫≈≤ª≈‰∂‘\n");
    return 0;
}