#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int *base;
    int *top;
}stack;
void creat(stack &s,int num);
void enter(int i,stack &s);
void output(stack s);
int main()
{
    int num,time,i;
    scanf("%d",&num);
    stack s1,s2,s3;
    creat(s1,num);  creat(s2,num);  creat(s3,num);
    for ( time = 1; time <= num; time++)
    {
        scanf("%d",&i);
        if(i < 60) enter(i,s1);
        else if(i<100) enter(i,s2);
        else enter(i,s3);
    }
    printf("60>x:"); output(s1);
    printf("60<=x<100:"); output(s2);
    printf("x>=100:"); output(s3);
    return 0;
}

void creat(stack &s,int num){
    s.base=s.top=(int*)malloc(num*sizeof(stack));
}
void enter(int i,stack &s){
    *s.top=i;
    s.top++;
}
void output(stack s){
    while (1)
    {
        if(s.base != s.top) printf("%d ",*s.base++);
        else {printf("\n"); break;};
    }
}