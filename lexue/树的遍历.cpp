#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    char date;                          //储存数据
    struct tree *left,*right;           //分别为，左孩子和右孩子
}tree;
tree *creat();                         //以先序遍历存储
int DLR(tree *a);
int LDR(tree *a);                      //中序遍历
int LRD(tree *a);                      //后序遍历
int main()
{
    tree *bit;
    char _;
    bit = creat();
    printf("前序遍历结果：");
    DLR(bit);
    printf("\n");
    printf("中序遍历结果：");
    LDR(bit);
    printf("\n");
    printf("后序遍历结果：");
    LRD(bit);
    printf("\n");
    return 0;
}

tree *creat(){
    tree *a = (tree*)malloc(sizeof(tree));
    char _;
    scanf("%c",&_);
    if (_ == '#')
        {free(a); a = NULL;}
    else
    {
        a->date = _;
        a->left = creat();
        a->right = creat();
    }
    return a;
}
int DLR(tree *a){
    if (a != NULL)
    {
        printf("%c ",a->date);
        DLR(a->left);
        DLR(a->right);
    }
    return 0;
}
int LDR(tree *a){
    if (a != NULL)
    {
        LDR(a->left);
        printf("%c ",a->date);
        LDR(a->right);
    }
    return 0;
}
int LRD(tree *a){
    if (a != NULL)
    {
        LRD(a->left);
        LRD(a->right);
        printf("%c ",a->date);
    }
    return 0;
}