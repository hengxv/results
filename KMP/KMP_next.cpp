#include<stdio.h>
#include<stdlib.h>
#define SIZE 21 //定义能够储存长度 最大子串长+1
void get_next(char *ori,int *&next);//构造计算得到next数组的函数，以满足KMP算法的优化?
int main()
{
    char *p=(char*)malloc(SIZE*sizeof(char));//创建一个字符数组，以便容纳子串对象
    char _;       int i;
    for ( i=1 ;(_ = getchar()) != '\n' && i != SIZE ; i++)  p[i] = _;//存储字串，并得到最大储存?
    p[0] = i;
    int *next = (int*)malloc((p[0])*sizeof(int));//创建next数组
    get_next(p,next);//得到next数组
    for ( i = 1; i < p[0]; i++)  printf("%d ,",next[i]);//输出next数组有效内容
    return 0;
}
void get_next(char *ori,int *&next){
    int i,j;
    next[1] = 0;
    next[0] = 0;//初始定义
    for (i = 1,j = 0; i < ori[0];)//j，i在不断移动过程中，保持i只能前进，每次匹配的情况只有两种
    {
        if (ori[i] == ori[j] || j == 0)//满足条件：i，j同时前移一个位置，并存储对应next?
        {                              //ori[i] == ori[j]表明匹配成功，next[i+1]=next[i]+1=j+1
            next[i+1] = j+1 ;          // j == 0，回到头部后表明下一个只能从头开始匹配? next[i+1]=1=j+1
            j++;i++;
        }
        else  j = next[j];//当不满足上述条件时：继续往前索引，直至找到符合条件的位置，或者抵达头部?
    }
}
