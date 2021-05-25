#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Link
{
    int x,y;                                             //x��ʾ�кţ�y��ʾ�к�
    int val;                                             //��ʾ ֵ
    struct Link *right=NULL,*down=NULL;
}Link,*pLink;
typedef struct 
{
    pLink *mhead,*nhead;                                //mhead��ʾÿ��ͷ����nhead��ʾÿ��ͷ����
    int m,n;                                    //m��ʾ�У�n��ʾ�У�total��ʾ����Ԫ����
}crossList;
void creat(crossList &a){
    int i,j,num;
    pLink p = NULL,q = NULL;
    printf("�����������С��г���\n");
    scanf("%d%d",&a.m,&a.n);                                     //�ֱ������С��г���
    printf("���������\n");
    a.mhead = (pLink*) malloc((a.m+1)*sizeof(Link));
    a.nhead = (pLink*) malloc((a.n+1)*sizeof(Link));
    memset(a.mhead,NULL,(a.m+1)*sizeof(Link));
    memset(a.nhead,NULL,(a.n+1)*sizeof(Link));                   //��ÿ��ͷ�����ʼ��ΪNULL
    for ( i = 1,j = 1; i != a.m+1 ;i++) 
    {
        for(j = 1 ;j != a.n+1; j++)
        {
            scanf("%d",&num);
            if(num != 0)                                         //�ж�Ԫ���Ƿ�Ϊ�㣬�����򲻴���
            {
                p = (pLink)malloc(sizeof(Link));
                p->x = i;   p->y = j;    p->val = num;           //�����Ԫ�����
                if (a.mhead[i] != NULL)                          //�ж϶�Ӧ�е�ͷ�����Ƿ�Ϊ�գ�
                {                                                //�������Ҳ�λ��
                    q = a.mhead[i];
                    while (q->right)  q = q->right;
                    q->right = p;
                    p->right =NULL;                             //��ʼ��һ��
                }
                else  
                {
                    a.mhead[i] = p;                             //�ǣ��򽫴�ʱ��ַ��Ϊͷָ�롣
                    a.mhead[i]->right =NULL;
                }
                if (a.nhead[j] != NULL)                         //�ж϶�Ӧ�е�ͷ�����Ƿ�Ϊ�գ�
                {                                               //�������²�λ��
                    q = a.nhead[j];
                    while (q->down != NULL) q = q->down;
                    q->down = p;
                    p->down = NULL;                             //��ʼ��һ��
                }
                else  
                {
                    a.nhead[j] = p;                             //�ǣ��򽫴�ʱ��ַ��Ϊͷָ�롣
                    a.nhead[j]->down = NULL;                    //��ʼ��һ��
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