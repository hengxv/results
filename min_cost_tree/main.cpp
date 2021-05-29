#include<stdio.h>
#include<stdlib.h>
typedef struct relation                                                              //��¼ÿ���ߵ�����
{
    int x,y;                                                                          //������
    int power;                                                                        //�ñߵ�Ȩ��
    int flag ;                                                                        //���ֵ��0Ϊ��ʼ��1Ϊ���ã�2Ϊ���ã�
}relation;
typedef struct each_point                                                             //��¼ÿ���������
{
    int point;                                                                        //��ı��
    int group;                                                                        //������
}each_point;                                                                           
struct node
{
    int firnode;
    struct acrNode *next;
};
typedef struct acrNode                                                                //�ڽӱ�Ԫ�����ڴ������ս��
{
    int point;
    int power;
    struct acrNode *next;
}*acrP;                                                                                   
int search(relation *a,each_point *b);                                               //Ѱ��һ�η��ϱ�
void save(relation a);                                                                //���Ѿ�ѡ��ıߣ������ڽӱ���
int edge,num;                                                                         //edgeΪ����Ŀ��numΪ������Ŀ
int times = 1;                                                                        //�����
node *list;
int main()
{
    printf("��ֱ�����ͼ�� ���� �� ���� ������\n");
    scanf("%d %d",&edge,&num);                                                        //edge��ʾ����Ŀ��num��ʾ������Ŀ
    printf("��ֱ���������ߵ� �������� ���� Ȩ�� ��\n");
    relation edge_rel[edge];                                                          //�߹�ϵ
    each_point one[num+1];                                                            //�����ϵ
    list = (struct node*)malloc(sizeof(struct node)*num);
    for (int i = 0; i < edge;edge_rel[i++].flag = 0)                                //�������룬�����ߵ�����
        scanf("%d %d %d",&edge_rel[i].x,&edge_rel[i].y,&edge_rel[i].power);
    for (int i = 1; i <= num; i++)                                                   //��ʼ�� ������Ϣ �� �ڽӱ�
        {
            one[i].group = 0;                                                        
            one[i].point = i;
            list[i-1].firnode = i;
            list[i-1].next = NULL;
        }
    for(int i = 1;i <= edge;i++)                                                        //��ÿ�������һ��search����
        search(edge_rel,one);
    printf("\n����ͼ����С�������ĸ�������Ϊ��\n");                                      //������
    for(int i = 0;i <= edge;i++)
        if(edge_rel[i].flag == 1) printf("(%d ,%d)\n",edge_rel[i].x,edge_rel[i].y);
    printf("�Ѵ�����С������\n");
    return 0;
}
int search(relation *a,each_point *b)
{
    int temp = -1,pos = -1;
    int i;
    for (i = 0; i < edge; i++)  
        if(a[i].flag != 1 && a[i].flag != 2)
        {
            if(a[i].flag == 0 && (b[a[i].x].group == b[a[i].y].group) && (b[a[i].x].group + b[a[i].y].group) > 0)       //�����ж�
                a[i].flag = 2;
            if(a[i].flag == 0 )                                                                                         //ѡ���ж�
            {
                temp = a[i].power;
                pos = i;
                break;
            }
        }                                                                                                               //��ʼ��temp
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
    if(b[a[pos].x].group == 0 && b[a[pos].y].group == 0)                                      //����û�����ʱ����ʼ��һ�����
    {
        b[a[pos].x].group = times;
        b[a[pos].y].group = times++;
    }
    else if(b[a[pos].x].group != b[a[pos].y].group)                                            //�������
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