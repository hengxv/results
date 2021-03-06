#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    char data;                          //储存数据
    struct tree *left,*right;           //分别为，左孩子和右孩子
}tree;
tree *creat();                         //以先序遍历存储
int LDR(tree *a);                      //中序遍历
int LRD(tree *a);                      //后序遍历
int main()
{
    tree *bit;
    char _;
    bit = creat();
    printf("中序序列为：");
    LDR(bit);
    printf("\n");
    printf("后序序列为：");
    LRD(bit);
    printf("\n");
    return 0;
}

tree *creat(){
    tree *a = (tree*)malloc(sizeof(tree));
    char _,trashbin;                          // _ 储存值，trashbin 是消耗每次输入的空格，（由于采取了%c，scanf会读入空格）
    scanf("%c%c",&_,&trashbin);
    if (_ == '*')                              //判断是否为终止符号，即我们约定“*”为终止符号
        {free(a); a = NULL;}
    else
    {
        a->data = _;
        a->left = creat();
        a->right = creat();
    }
    return a;
}
int LDR(tree *a){
    if (a != NULL)
    {
        LDR(a->left);
        printf("%c ",a->data);
        LDR(a->right);
    }
    return 0;
}
int LRD(tree *a){
    if (a != NULL)
    {
        LRD(a->left);
        LRD(a->right);
        printf("%c ",a->data);
    }
    return 0;
}