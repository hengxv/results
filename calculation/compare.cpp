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
    };//�������ȹ�ϵ��񣬹������鴢���ַ�������ȹ�ϵ
    int i,j;
    switch (a)
    {
    case '+': i = 0;break;
    case '-': i = 1;break;
    case '*': i = 2;break;
    case '/': i = 3;break;
    case '(': i = 4;break;
    case ')': i = 5;break;
    }//�õ��ȽϹ�ϵ������
    switch (b)
    {
    case '+': j = 0;break;
    case '-': j = 1;break;
    case '*': j = 2;break;
    case '/': j = 3;break;
    case '(': j = 4;break;
    case ')': j = 5;break;
    }//�õ��ȽϹ�ϵ������
    return cmp[i][j];//���رȽϽ��
}