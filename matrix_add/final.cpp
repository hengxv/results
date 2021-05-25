#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct  Link
{
    int x,y;                                                   //x表示行号，y表示列号
    int val;                                                   //val 表示 值
    struct Link *right,*down;
}Link,*pLink;
typedef struct 
{
    pLink *mhead,*nhead;                                       //mhead表示每行头链表，nhead表示每列头链表
    int m,n;                                                   //m表示行，n表示列，total表示非零元个数
}crossList;

void creat(crossList &a);                                      //创建并储存十字链表型稀疏矩阵
void list_Insert(pLink &left,crossList &A,pLink &a,pLink b);   //将b插入到a的相应位置
void destroy(pLink &left,crossList &A,pLink &a);               //删除a的此节点
void pass(pLink &left,pLink &a);                               //将a向前推进
void add(pLink &left,pLink &a,pLink b);                        //将a与b节点对应值相加

int main()
{
    crossList matrixA,matrixB;
    creat(matrixA);
    creat(matrixB);                                            //创建矩阵A与矩阵B
    if(matrixA.m != matrixB.m || matrixA.n != matrixB.n)       //判断是否满足矩阵加法条件
    {printf("矩阵类型不一致，无法完成加法运算\n"); return 0;}
    pLink pA,pB;                                               //pA指示A矩阵节点，pB指示B矩阵节点
    pLink left,next;                                           //left指示pA的上一个节点,next指示pB的下一个节点
    for ( int i = 1;i <= matrixA.m ;i++)                       //扫描每一行
    {
        left = pA = matrixA.mhead[i];
        pB = matrixB.mhead[i];
        while(pB != NULL)                                     //每次会有四种情况
        {
            next = pB->right;
            if (pA == NULL || pA->y > pB->y)  list_Insert(left,matrixA,pA,pB);  //此行A没有非零元或pA的非零元前于pA，采取插入
            else if (pA->y < pB->y)           {pass(left,pA);continue;}        //pB的非零元在pA前，采取推进
            else if (pA->y == pB->y && pA->val + pB->val == 0)  destroy(left,matrixA,pA);// 节点之和为零，摧毁节点
            else if (pA->y == pB->y && pA->val + pB->val != 0)  add(left,pA,pB);     //节点之和不为零，储存结果
            pB = next;
        }
    }
    printf("相加结果为：\n");
    for ( int i =1; i <= matrixA.m; i++)                     //每一行扫描出结果
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
    if(left == a)                                                  //此时a即是行链表的头
    {
        A.mhead[b->x] = b;                                         //将b插入为行链表的头
        left = b;                                                  //移动左指针
        b->right = a;                                              //链接行链表
    }
    else                                                           //此时a为中间点
    {
        left->right = b;                                           //插入b 
        b->right = a;
        left = left->right;                                        //移动左指针
    }
    if( A.nhead[b->y] && (A.nhead[b->y]->x) > b->x )               //判断b是否处于该列的头部。否，则插入b
    {
        pLink temp,Temp;                                           //中间量
        for ( temp = A.nhead[b->y] ;temp->down && ((temp->down->x) < b->x ); temp = temp->down); //找到恰高于b的非零位置
        Temp = temp->down;
        temp->down = b;
        b->down = Temp;
    }                                                              
    else                                                           //是，则修改列链表头部
    {
        pLink temp;
        temp = A.nhead[b->y];
        A.nhead[b->y] = b;
        b->down = temp;
    }
}
void destroy(pLink &left,crossList &A,pLink &a){
    pLink temp;
    if (A.mhead[a->x] == a)   A.mhead[a->x] = a->right;          //判断a是否处于行的头部
    else   left->right = a->right;
    if (A.nhead[a->y] != a)                                      //判断a是否处于列的头部
    {
        for ( temp = A.nhead[a->y] ;temp->down && ((temp->down->x) < a->x ); temp = temp->down);
        temp->down = a->down;
    }
    else A.nhead[a->y] =  A.nhead[a->y]->down;
}
void add(pLink &left,pLink &a,pLink b){                           //节点相加并推进pA
    a->val += b->val; 
    a = a->right;
    left = left->right;
}
void pass(pLink &left,pLink &a){                                  //推进pA
    left = a; 
    a = a->right;
}
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
