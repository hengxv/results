#include<stdio.h>
#include<stdlib.h>
typedef struct relation                                                              //记录每条边的特性
{
    int x,y;                                                                          //两点编号
    int power;                                                                        //该边的权重
    int flag ;                                                                        //标记值（0为初始，1为采用，2为弃置）
}relation;
typedef struct each_point                                                             //记录每个点的特性
{
    int point;                                                                        //点的编号
    int group;                                                                        //点的组别
}each_point;                                                                           
struct node
{
    int firnode;
    struct acrNode *next;
};
typedef struct acrNode                                                                //邻接表单元，用于储存最终结果
{
    int point;
    int power;
    struct acrNode *next;
}*acrP;                                                                                   
int search(relation *a,each_point *b);                                               //寻找一次符合边
void save(relation a);                                                                //对已经选择的边，利用邻接表储存
int edge,num;                                                                         //edge为边数目，num为顶点数目
int times = 1;                                                                        //组别编号
node *list;
int main()
{
    printf("请分别输入图的 边数 和 顶点 个数：\n");
    scanf("%d %d",&edge,&num);                                                        //edge表示边数目，num表示顶点数目
    printf("请分别输入各个边的 两个顶点 及其 权重 ：\n");
    relation edge_rel[edge];                                                          //边关系
    each_point one[num+1];                                                            //顶点关系
    list = (struct node*)malloc(sizeof(struct node)*num);
    for (int i = 0; i < edge;edge_rel[i++].flag = 0)                                //根据输入，构建边的特征
        scanf("%d %d %d",&edge_rel[i].x,&edge_rel[i].y,&edge_rel[i].power);
    for (int i = 1; i <= num; i++)                                                   //初始化 顶点信息 和 邻接表
        {
            one[i].group = 0;                                                        
            one[i].point = i;
            list[i-1].firnode = i;
            list[i-1].next = NULL;
        }
    for(int i = 1;i <= edge;i++)                                                        //对每条边完成一次search（）
        search(edge_rel,one);
    printf("\n生成图的最小生成树的各边依次为：\n");                                      //输出结果
    for(int i = 0;i <= edge;i++)
        if(edge_rel[i].flag == 1) printf("(%d ,%d)\n",edge_rel[i].x,edge_rel[i].y);
    printf("已储存最小生成树\n");
    return 0;
}
int search(relation *a,each_point *b)
{
    int temp = -1,pos = -1;
    int i;
    for (i = 0; i < edge; i++)  
        if(a[i].flag != 1 && a[i].flag != 2)
        {
            if(a[i].flag == 0 && (b[a[i].x].group == b[a[i].y].group) && (b[a[i].x].group + b[a[i].y].group) > 0)       //弃置判断
                a[i].flag = 2;
            if(a[i].flag == 0 )                                                                                         //选用判断
            {
                temp = a[i].power;
                pos = i;
                break;
            }
        }                                                                                                               //初始化temp
    for (i = 0; i < edge; i++)  
        {
            if((b[a[i].x].group == 0 &&b[a[i].y].group == 0)||(b[a[i].x].group != b[a[i].y].group))
            {
                if(a[i].power < temp && a[i].flag == 0)
                    {
                        temp = a[i].power;
                        pos = i;
                    }
            }
        }
    if(pos == -1) return 0; 
    a[pos].flag = 1;
    if(b[a[pos].x].group == 0 && b[a[pos].y].group == 0)                                      //即，没有组别时，初始化一个组别
    {
        b[a[pos].x].group = times;
        b[a[pos].y].group = times++;
    }
    else if(b[a[pos].x].group != b[a[pos].y].group)                                            //传递组别
    {
        if(b[a[pos].x].group != 0)     b[a[pos].y].group = b[a[pos].x].group;
        if(b[a[pos].y].group != 0)     b[a[pos].x].group = b[a[pos].y].group;
    }
    save(a[pos]);
    return 0;
}
void save(relation a)
{
    acrP px = list[a.x-1].next , py = list[a.y-1].next;
    if(px == NULL)
    {
        list[a.x-1].next = (acrP) malloc(sizeof(acrNode));
        px = list[a.x-1].next;
    }
    else
    {
        while(px->next != NULL) px = px->next;
        px->next = (acrP) malloc(sizeof(acrNode));
        px = px->next;
    }
    px->point = a.y;
    px->power = a.power;
    px->next = NULL;
    if(py == NULL)
    {
        list[a.y-1].next = (acrP) malloc(sizeof(acrNode));
        py = list[a.y-1].next;
    }
    else
    {
        while(py->next != NULL) py = py->next;
        py->next = (acrP) malloc(sizeof(acrNode));
        py = py->next;
    }
    py->point = a.x;
    py->power = a.power;
    py->next = NULL;
}