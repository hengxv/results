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
void search(relation *a,each_point *b);                                               //Ѱ��һ�η��ϱ�
int edge,num;                                                                         //edgeΪ����Ŀ��numΪ������Ŀ
int times = 1;                                                                        //�����
int main()
{
    printf("��ֱ�����ͼ�� ���� �� ���� ������\n");
    scanf("%d %d",&edge,&num);                                                        //edge��ʾ����Ŀ��num��ʾ������Ŀ
    printf("��ֱ���������ߵ� �������� ���� Ȩ�� ��\n");
    relation edge_rel[edge];                                                          //�߹�ϵ
    each_point one[num+1];                                                            //�����ϵ
    for (int i = 0; i < edge;edge_rel[i].flag = 0,i++)
        scanf("%d %d %d",&edge_rel[i].x,&edge_rel[i].y,&edge_rel[i].power);
    for (int i = 1; i <= num; i++)
        {
            one[i].group = 0;                                                         //��ʼ�� ������Ϣ
            one[i].point = i;
        }
    for(int i = 1;i <= edge;i++)
        search(edge_rel,one);
    printf("\n����ͼ����С�������ĸ�������Ϊ��\n");                                      //������
    for(int i = 0;i <= edge;i++)
        if(edge_rel[i].flag == 1) printf("(%d ,%d)\n",edge_rel[i].x,edge_rel[i].y);
    return 0;
}
void search(relation *a,each_point *b)
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
}