#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Link
{
    int x,y;                                             //x表示行号，y表示列号
    int val;                                             //表示 值
    struct Link *right=NULL,*down=NULL;
}Link,*pLink;
typedef struct 
{
    pLink *mhead,*nhead;                                //mhead表示每行头链表，nhead表示每列头链表
    int m,n;                                    //m表示行，n表示列，total表示非零元个数
}crossList;
void creat(crossList &a){
    int i,j,num;
    pLink p = NULL,q = NULL;
    printf("请输入矩阵的行、列长度\n");
    scanf("%d%d",&a.m,&a.n);                                     //分别输入行、列长度
    printf("请输入矩阵\n");
    a.mhead = (pLink*) malloc((a.m+1)*sizeof(Link));
    a.nhead = (pLink*) malloc((a.n+1)*sizeof(Link));
    memset(a.mhead,NULL,(a.m+1)*sizeof(Link));
    memset(a.nhead,NULL,(a.n+1)*sizeof(Link));                   //将每个头链表初始化为NULL
    for ( i = 1,j = 1; i != a.m+1 ;i++) 
    {
        for(j = 1 ;j != a.n+1; j++)
        {
            scanf("%d",&num);
            if(num != 0)                                         //判断元素是否为零，若是则不储存
            {
                p = (pLink)malloc(sizeof(Link));
                p->x = i;   p->y = j;    p->val = num;           //完成三元的填充
                if (a.mhead[i] != NULL)                          //判断对应行的头链表是否为空，
                {                                                //否，则向右补位，
                    q = a.mhead[i];
                    while (q->right)  q = q->right;
                    q->right = p;
                    p->right =NULL;                             //初始下一项
                }
                else  
                {
                    a.mhead[i] = p;                             //是，则将此时地址定为头指针。
                    a.mhead[i]->right =NULL;
                }
                if (a.nhead[j] != NULL)                         //判断对应列的头链表是否为空，
                {                                               //否，则向下补位，
                    q = a.nhead[j];
                    while (q->down != NULL) q = q->down;
                    q->down = p;
                    p->down = NULL;                             //初始下一项
                }
                else  
                {
                    a.nhead[j] = p;                             //是，则将此时地址定为头指针。
                    a.nhead[j]->down = NULL;                    //初始下一项
                }
            }
        }
    }
}

int main()
{
    crossList A;
    creat(A);
    printf("over\n");
    return 0;
}