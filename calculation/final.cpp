#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SETSIZE 10                            //��ʼջ����
#define ADDSIZE 2                            //ÿ�����ӳ���
#define ERROR -1
typedef struct 
{
    int *base;
    int *top;
    int size;
}stack;
void input_num (char _, stack &a, int flag);      //������Ϊ����ʱ��������ջ��������flagֵ��
                                                 // flag�����ж��Ƿ������������֣��Ա�õ���λ����
void input_op(char _,stack &a);                 //����Ϊ�����ʱ���������ջ
char compare(char a,char b);                   //�Ƚ������������ȹ�ϵ�������ؽ��
void count(stack &num,stack &op);             //����
void checkAdd(stack &a,char _);              // ������������Ƿ���������Դ˲�ȡ��ջ���߳�ջ����
int main()
{
    stack num,op;                             //numջ�������֣�opջ���������
    num.base = num.top = (int*)malloc(SETSIZE*sizeof(int)) ;
    op.base = op.top = (int*)malloc(SETSIZE*sizeof(int)) ;//�����ʼ�ռ�
    num.size = op.size = SETSIZE;
    char _;  int flag = 1;
    printf("\n");
    while ((_ = getchar()) != '\n')          //�Ի��з�Ϊ��ֹ��־
    {
        if ('0' <= _ && _ <= '9') {input_num(_,num,flag); flag++;}//orz,��д��������ʽ�Ե���
        else
        {
            if(op.base != op.top)             //�ж��Ƿ�Ϊ��һ��������ջ���������ж����ȼ�
            {
                switch (compare(*(op.top-1),_))
                {
                    case '<': input_op(_,op);   break;
                    case '>': count(num,op);   checkAdd(op,_);   break;         
                    case '=': op.top--;
                }
            }
            else input_op(_,op);
            flag = 1;
        }    
    }
    while(op.top != op.base) count(num,op);    //��������󣬶�ջ��ʣ���������������м���
    printf("����Ϊ�������\n���Ϊ��%d\n",*num.base);               //������ս��
    free(op.base);   free(num.base);         //�ͷſռ�
    return 0;
}


void input_num (char _,stack &a,int flag){
     if(a.top-a.base >= a.size)               // �ж��Ƿ�ջ�������ǣ������ӿռ�
    {
        a.base = (int*)realloc(a.base,(a.size+ADDSIZE)*sizeof(int));
        if(!a.base) exit ERROR;
        a.top = a.base + ADDSIZE;
        a.size += ADDSIZE;
    }
    if( flag == 1)  *a.top++ = _ - '0';
    else *(a.top-1) = *(a.top - 1)*10 +(_ - '0'); 
}
void input_op(char _,stack &a){
    if(a.top-a.base >= a.size)               // �ж��Ƿ�ջ�������ǣ������ӿռ�
    {
        a.base = (int*)realloc(a.base,(a.size+ADDSIZE)*sizeof(int));
        if(!a.base) exit(ERROR);
        a.top = a.base + ADDSIZE;
        a.size += ADDSIZE;
    }
    *a.top++ = _ ;
}

void checkAdd(stack &a,char _){
    if(_ != ')')input_op(_,a);
    else a.top--;
}

void count(stack &num,stack &op){
    int a,b;
    a = *(--num.top);
    b = *(--num.top);
    switch (*(--op.top))
    {
        case '+': *num.top++ = b+a;break;
        case '-': *num.top++ = b-a;break;
        case '*': *num.top++ = b*a;break;
        case '/': *num.top++ = b/a;break;
        case '^': *num.top++ = pow(b,a);break; 
    }
    printf("%d %c %d = %d\n",b,*op.top,a,*(num.top-1)); //���ÿһ�����������
}
char compare(char a,char b){
    char cmp[7][7] = 
    {   
        {'>','>','<','<','<','>','<'},
        {'>','>','<','<','<','>','<'},
        {'>','>','>','>','<','>','<'},
        {'>','>','>','>','<','>','<'},
        {'<','<','<','<','<','=','<'},
        {'>','>','>','>','0','>','>'},
        {'>','>','>','>','<','>','>'}
    };                                      //�������ȹ�ϵ��񣬹������鴢���ַ�������ȹ�ϵ
    int i,j;
    switch (a)
    {
    case '+': i = 0;break;
    case '-': i = 1;break;
    case '*': i = 2;break;
    case '/': i = 3;break;
    case '(': i = 4;break;
    case ')': i = 5;break;
    case '^': i = 6;break;
    }                                       //�õ��ȽϹ�ϵ������
    switch (b)
    {
    case '+': j = 0;break;
    case '-': j = 1;break;
    case '*': j = 2;break;
    case '/': j = 3;break;
    case '(': j = 4;break;
    case ')': j = 5;break;
    case '^': j = 6;break;
    }                                       //�õ��ȽϹ�ϵ������
    return cmp[i][j];                      //���رȽϽ��
}