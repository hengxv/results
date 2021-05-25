#include<stdio.h>
#include<stdlib.h>
typedef struct List
{
    int data;
    struct List *next;
} *pl;
void input(pl head);
main()
{
    pl ha=NULL,hb=NULL,hc=NULL;
    pl p=NULL,q=NULL,k=NULL;
    ha = (struct List*)malloc(sizeof(struct List));
    hb = (struct List*)malloc(sizeof(struct List));
    hc = (struct List*)malloc(sizeof(struct List));
    input(ha);
    input(hb);
    for(p = ha->next,k = hc; p->next != NULL; p=p->next){
        for (q = hb->next ; q->next != NULL ; q=q->next){
            if (p->data == q->data){
                k->data = p->data;
                k->next = (struct List*)malloc(sizeof(struct List));
                k = k->next;
                break;
            }  
        }
    }
    k->next = NULL;
    if(hc->next == NULL) printf("娌℃湁浜ら泦\n");
    else{
		 for( p = hc; p->next != NULL; p = p->next){ printf("%d ",p->data); }
    	 printf("\n");
	}
    return 0;
}
void input(pl head){
    pl p;
    int n;
    p = head;
    do
    {
	    scanf("%d",&n);
        p->next = (struct List*)malloc(sizeof(struct List));
        p = p->next;
        p->data = n;  
    } while (getchar() != '\n');   
	p->next = (struct List*)malloc(sizeof(struct List));
	p->next->next=NULL;
}
