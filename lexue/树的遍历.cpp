#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    char date;                          //��������
    struct tree *left,*right;           //�ֱ�Ϊ�����Ӻ��Һ���
}tree;
tree *creat();                         //����������洢
int DLR(tree *a);
int LDR(tree *a);                      //�������
int LRD(tree *a);                      //�������
int main()
{
    tree *bit;
    char _;
    bit = creat();
    printf("ǰ����������");
    DLR(bit);
    printf("\n");
    printf("������������");
    LDR(bit);
    printf("\n");
    printf("������������");
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