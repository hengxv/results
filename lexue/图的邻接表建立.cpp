#include<stdio.h>
#include<stdlib.h>
typedef struct point
{
    char name;
    struct arc *next;
}point;
typedef struct arc
{
    int power;
    int point;
    struct arc * next;
}arc;
int in(arc* &bza);
int out(int n,arc* bit);
int main()
{
    int count;
    char bin;
    scanf("%d%c",&count,&bin);
    point a[count];
    for (int i = 0; i < count; i++) 
    {
        scanf("%c%c",&a[i].name,&bin);
        a[i].next = NULL;
    }
    for (int i = 0; i < count; i++)
        in(a[i].next);
    for (int i = 0; i < count; i++)
    {
        printf("%c  ",a[i].name);
        out(i,a[i].next);
        printf("\n");
    }
    return 0;
}
int in(arc *&bza)
{
        int temp;
        scanf("%d",&temp);
        if(temp == -1) return 0;
        if(bza == NULL) 
            bza = (arc*)malloc(sizeof(arc));
        bza->point = temp;
        scanf("%d",&bza->power);
        bza->next = NULL;
        in(bza->next);
        return 0;
}
int out(int n,arc* bit)
{
    if(bit == NULL) return 0;
    else 
    {
        out(n,bit->next);
        printf("(%d,%d)%d  ",n,bit->point,bit->power);
        return 0;
    }
}