#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SETSIZE 10                            //初始栈长度
#define ADDSIZE 2                            //每次增加长度
#define ERROR -1
typedef struct 
{
    int *base;
    int *top;
    int size;
}stack;
void input_num (char _, stack &a, int flag);      //当输入为数字时，入数字栈，并传入flag值。
                                                 // flag用于判断是否连续输入数字，以便得到高位数字
void input_op(char _,stack &a);                 //输入为运算符时，入运算符栈
char compare(char a,char b);                   //比较运算符间的优先关系，并返回结果
void count(stack &num,stack &op);             //计算
void checkAdd(stack &a,char _);              // 检查括号运算是否结束，并以此采取入栈或者出栈操作
int main()
{
    stack num,op;                             //num栈储存数字，op栈储存运算符
    num.base = num.top = (int*)malloc(SETSIZE*sizeof(int)) ;
    op.base = op.top = (int*)malloc(SETSIZE*sizeof(int)) ;//分配初始空间
    num.size = op.size = SETSIZE;
    char _;  int flag = 1;
    printf("\n");
    while ((_ = getchar()) != '\n')          //以换行符为终止标志
    {
        if ('0' <= _ && _ <= '9') {input_num(_,num,flag); flag++;}//orz,再写连续不等式吃电脑
        else
        {
            if(op.base != op.top)             //判断是否为第一个符号入栈。若否，则判断优先级
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
    while(op.top != op.base) count(num,op);    //结束输入后，对栈中剩余的数与运算符进行计算
    printf("以上为计算过程\n结果为：%d\n",*num.base);               //输出最终结果
    free(op.base);   free(num.base);         //释放空间
    return 0;
}


void input_num (char _,stack &a,int flag){
     if(a.top-a.base >= a.size)               // 判断是否栈满。若是，则增加空间
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
    if(a.top-a.base >= a.size)               // 判断是否栈满。若是，则增加空间
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
    printf("%d %c %d = %d\n",b,*op.top,a,*(num.top-1)); //输出每一步的运算过程
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
    };                                      //根据优先关系表格，构建数组储存字符间的优先关系
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
    }                                       //得到比较关系的行数
    switch (b)
    {
    case '+': j = 0;break;
    case '-': j = 1;break;
    case '*': j = 2;break;
    case '/': j = 3;break;
    case '(': j = 4;break;
    case ')': j = 5;break;
    case '^': j = 6;break;
    }                                       //得到比较关系的列数
    return cmp[i][j];                      //返回比较结果
}