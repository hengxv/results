#include<stdio.h>
#include<stdlib.h>
struct List
    {
        int data;
        struct List *next;
    };
int main()
{
    int i,n,m;
    char _;
    struct List *head=NULL,*p=NULL,*q=NULL;
    head=(struct List*)malloc(sizeof(struct List));
    p=head;
    do
    {
	    scanf("%d",&n);
        p->next=(struct List*)malloc(sizeof(struct List));
        p=p->next;
        p->data=n;  
    } while ((_=getchar())!='\n');   
	p->next=NULL;
    scanf("%d",&m);
	if(head->next->data==m) printf("该结点没有前驱结点\n");
	else{
		for(q=head;q->next->next->data!=m;q=q->next);
    q->next=q->next->next;
    p=head->next;
    while (p->next!=NULL)
    {
        printf("%d ",p->data);
    	p=p->next;
    }
    printf("%d\n",p->data);}   
    return 0;
}
