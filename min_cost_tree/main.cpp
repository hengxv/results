#include<stdio.h>
#include<stdlib.h>
typedef struct known
{
    int x,y;
    int power;
    int flag ;
}known;                                                                           //记录每条边的特性(两点、权重、标记值（0为初始，1为采用，2为弃置）)
typedef struct each_point
{
    int point;
    int group;
}each_point;                                                                           //记录每个点的特性（序号、组别）
void search(known *a,each_point *b);                                                  //寻找一次符合边
int edge,num;                                                                         //edge为边数目，num为顶点数目
int times = 1;                                                                        //组别编号
int main()
{
    printf("请分别输入图的 边数 和 顶点 个数：\n");
    scanf("%d %d",&edge,&num);
    printf("请分别输入各个边的 两个顶点 及其 权重 ：\n");
    known hh[edge];           //边关系
    each_point one[num+1];        //顶点关系
    for (int i = 0; i < edge;hh[i].flag = 0,i++)
        scanf("%d %d %d",&hh[i].x,&hh[i].y,&hh[i].power);
    for (int i = 1; i <= num; i++)
        {
            one[i].group = 0;                                                         //初始化 顶点信息
            one[i].point = i;
        }
    for(int i = 1;i <= edge;i++)
        search(hh,one);
    printf("\n生成图的最小生成树的各边依次为：\n");                                      //输出结果
    for(int i = 0;i <= edge;i++)
        if(hh[i].flag == 1) printf("(%d ,%d)\n",hh[i].x,hh[i].y);
    return 0;
}
void search(known *a,each_point *b)
{
    int temp = -1,pos = -1;
    int i;
    for (i = 0; i < edge; i++)  
        if(a[i].flag != 1 && a[i].flag != 2)
        {
            if(a[i].flag == 0 && (b[a[i].x].group == b[a[i].y].group) && (b[a[i].x].group + b[a[i].y].group) > 0)   //弃置判断
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
}