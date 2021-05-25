#include<stdio.h>
#include<stdlib.h>
typedef struct List{
    int data;
    struct List *next;
} *pl;
int main()
{
    pl ha,p,q,min = NULL,max = NULL;
    int num; char trush;
    p = ha = (pl) malloc(sizeof(pl));
    while (1)
    {
        scanf("%d",&num);
        p->next = (pl) malloc(sizeof(pl));
        p = p->next;
        p->data = num;
        trush = getchar();
        if(trush == '\n') break;
    }
    p->next = NULL;
    int x,y;
    scanf("%d %d",&x,&y);
    for(p = ha; p->next != NULL;p = p->next)if (p->next->data > x) {min = p;break;}
    for(p = ha; p->next != NULL;p = p->next)if (p->next->data > y) {max = p->next;break;} 
    
    if(min != NULL && max != NULL)
    {   
        for(p = min->next;p < max;p = q) {q=p->next;(p);}
        min->next = max;
    } 
    if(min != NULL && max == NULL)
    {   
        for(p = ha->next;p != NULL;p = q) {q=p->next;(p);}
    } 
    for (p = ha->next ; p->next !=NULL ;p = p->next)
    {
        printf("%d",p->data);
    }
    return 0;
}
