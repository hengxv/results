#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    char data;                          //��������
    struct tree *left,*right;           //�ֱ�Ϊ�����Ӻ��Һ���
}tree;
tree *creat();                         //����������洢
int LDR(tree *a);                      //�������
int LRD(tree *a);                      //�������
int main()
{
    tree *bit;
    char _;
    bit = creat();
    printf("��������Ϊ��");
    LDR(bit);
    printf("\n");
    printf("��������Ϊ��");
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