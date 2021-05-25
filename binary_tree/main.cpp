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
    char _,trashbin;
    scanf("%c%c",&_,&trashbin);
    if (_ == '*')
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