#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct  Link
{
    int x,y;                                                   //x��ʾ�кţ�y��ʾ�к�
    int val;                                                   //val ��ʾ ֵ
    struct Link *right,*down;
}Link,*pLink;
typedef struct 
{
    pLink *mhead,*nhead;                                       //mhead��ʾÿ��ͷ����nhead��ʾÿ��ͷ����
    int m,n;                                                   //m��ʾ�У�n��ʾ�У�total��ʾ����Ԫ����
}crossList;

void creat(crossList &a);                                      //����������ʮ��������ϡ�����
void list_Insert(pLink &left,crossList &A,pLink &a,pLink b);   //��b���뵽a����Ӧλ��
void destroy(pLink &left,crossList &A,pLink &a);               //ɾ��a�Ĵ˽ڵ�
void pass(pLink &left,pLink &a);                               //��a��ǰ�ƽ�
void add(pLink &left,pLink &a,pLink b);                        //��a��b�ڵ��Ӧֵ���

int main()
{
    crossList matrixA,matrixB;
    creat(matrixA);
    creat(matrixB);                                            //��������A�����B
    if(matrixA.m != matrixB.m || matrixA.n != matrixB.n)       //�ж��Ƿ��������ӷ�����
    {printf("�������Ͳ�һ�£��޷���ɼӷ�����\n"); return 0;}
    pLink pA,pB;                                               //pAָʾA����ڵ㣬pBָʾB����ڵ�
    pLink left,next;                                           //leftָʾpA����һ���ڵ�,nextָʾpB����һ���ڵ�
    for ( int i = 1;i <= matrixA.m ;i++)                       //ɨ��ÿһ��
    {
        left = pA = matrixA.mhead[i];
        pB = matrixB.mhead[i];
        while(pB != NULL)                                     //ÿ�λ����������
        {
            next = pB->right;
            if (pA == NULL || pA->y > pB->y)  list_Insert(left,matrixA,pA,pB);  //����Aû�з���Ԫ��pA�ķ���Ԫǰ��pA����ȡ����
            else if (pA->y < pB->y)           {pass(left,pA);continue;}        //pB�ķ���Ԫ��pAǰ����ȡ�ƽ�
            else if (pA->y == pB->y && pA->val + pB->val == 0)  destroy(left,matrixA,pA);// �ڵ�֮��Ϊ�㣬�ݻٽڵ�
            else if (pA->y == pB->y && pA->val + pB->val != 0)  add(left,pA,pB);     //�ڵ�֮�Ͳ�Ϊ�㣬������
            pB = next;
        }
    }
    printf("��ӽ��Ϊ��\n");
    for ( int i =1; i <= matrixA.m; i++)                     //ÿһ��ɨ������
    {
        pA = matrixA.mhead[i];
        for (int j = 1; j <= matrixA.n; j++)
        {
            if(pA != NULL && j == pA->y) 
            {
                printf("%d ",pA->val);
                pA = pA->right;
            }
            else printf("0 ");
        }
        printf("\n");
    }
}

void list_Insert(pLink &left,crossList &A,pLink &a,pLink b){
    if(left == a)                                                  //��ʱa�����������ͷ
    {
        A.mhead[b->x] = b;                                         //��b����Ϊ�������ͷ
        left = b;                                                  //�ƶ���ָ��
        b->right = a;                                              //����������
    }
    else                                                           //��ʱaΪ�м��
    {
        left->right = b;                                           //����b 
        b->right = a;
        left = left->right;                                        //�ƶ���ָ��
    }
    if( A.nhead[b->y] && (A.nhead[b->y]->x) > b->x )               //�ж�b�Ƿ��ڸ��е�ͷ�����������b
    {
        pLink temp,Temp;                                           //�м���
        for ( temp = A.nhead[b->y] ;temp->down && ((temp->down->x) < b->x ); temp = temp->down); //�ҵ�ǡ����b�ķ���λ��
        Temp = temp->down;
        temp->down = b;
        b->down = Temp;
    }                                                              
    else                                                           //�ǣ����޸�������ͷ��
    {
        pLink temp;
        temp = A.nhead[b->y];
        A.nhead[b->y] = b;
        b->down = temp;
    }
}
void destroy(pLink &left,crossList &A,pLink &a){
    pLink temp;
    if (A.mhead[a->x] == a)   A.mhead[a->x] = a->right;          //�ж�a�Ƿ����е�ͷ��
    else   left->right = a->right;
    if (A.nhead[a->y] != a)                                      //�ж�a�Ƿ����е�ͷ��
    {
        for ( temp = A.nhead[a->y] ;temp->down && ((temp->down->x) < a->x ); temp = temp->down);
        temp->down = a->down;
    }
    else A.nhead[a->y] =  A.nhead[a->y]->down;
}
void add(pLink &left,pLink &a,pLink b){                           //�ڵ���Ӳ��ƽ�pA
    a->val += b->val; 
    a = a->right;
    left = left->right;
}
void pass(pLink &left,pLink &a){                                  //�ƽ�pA
    left = a; 
    a = a->right;
}
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
