#include<stdio.h>
#include<stdlib.h>
#define setSize 10
typedef struct 
{
    int x,y;
    int val;
} tri;
typedef struct 
{
    tri data[setSize+1];
    int total; 
}link;
void start(link &a);
int main()
{
    link a,b;
    start(a);  start(b);
    int i,j;
    for ( i = 1; i <= a.total; i++)
    {
        for ( j = 1; j <= b.total; j++)
        {
            if (a.data[i].x == b.data[j].x && a.data[i].y == b.data[j].y)   
            {
            a.data[i].val += b.data[j].val;
            b.data[j].val = 0;
            } 
        }
    }
    for ( j = 1; j <= b.total; j++)
    {
        if (b.data[j].val != 0)
        {
            a.data[i++] =  b.data[j];
            a.total++;
        }
    }
    for ( i = 1; i <= a.total; i++)
    {
        if (a.data[i].val != 0)
        {
            if(i != 1) printf(";");
            printf("%d,%d,%d",a.data[i].x,a.data[i].y,a.data[i].val);
        }
    }
    printf("\n");
    return 0;
}
void start(link &a){
    char trash;
    int i=1;
    do
    {
        scanf("%d,%d,%d",&a.data[i].x,&a.data[i].y,&a.data[i].val);
        i++;
    } while ((trash = getchar()) != '\n');
    a.total = i-1;
}
