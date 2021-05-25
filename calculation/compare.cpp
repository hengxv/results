#include<stdio.h>
char compare(char a,char b);
int main()
{
    char fir,sec;
    scanf("%c%c",&fir,&sec);
    printf("%c\n",compare(fir,sec));
    return 0;
}

char compare(char a,char b){
    char cmp[6][6] = 
    {   
        {'>','>','<','<','<','>'},
        {'>','>','<','<','<','>'},
        {'>','>','>','>','<','>'},
        {'>','>','>','>','<','>'},
        {'<','<','<','<','<','='},
        {'>','>','>','>','0','>'}
    };//根据优先关系表格，构建数组储存字符间的优先关系
    int i,j;
    switch (a)
    {
    case '+': i = 0;break;
    case '-': i = 1;break;
    case '*': i = 2;break;
    case '/': i = 3;break;
    case '(': i = 4;break;
    case ')': i = 5;break;
    }//得到比较关系的行数
    switch (b)
    {
    case '+': j = 0;break;
    case '-': j = 1;break;
    case '*': j = 2;break;
    case '/': j = 3;break;
    case '(': j = 4;break;
    case ')': j = 5;break;
    }//得到比较关系的列数
    return cmp[i][j];//返回比较结果
}