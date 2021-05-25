#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    char data;                          //��������
    struct tree *left,*right;           //�ֱ�Ϊ�����Ӻ��Һ���
}tree;
void DLR_leaf(tree *a);                 //���������ж�ȡҶ����
int DLR_depth(tree *a);                 //���������ж�ȡ��ȣ��ݹ�
tree *creat();                          //���������д���������
static int leaf = 0;
int main()
{
    tree *bit;
    int depth;
    bit = creat();
    DLR_leaf(bit);
    depth = DLR_depth(bit);
    printf("leafs=%d\nDepth=%d\n",leaf,depth);
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
        a->data = _;
        a->left = creat();
        a->right = creat();
    }
    return a;
}
void DLR_leaf(tree *a){
    if (a != NULL)
    {
        if(a->left == NULL && a->right == NULL)
            leaf++;
        DLR_leaf(a->left);  
        DLR_leaf(a->right);
    }
}
int DLR_depth(tree *a)
{
    if(a != NULL)
        return (DLR_depth(a->left) > DLR_depth(a->right) ? DLR_depth(a->left) : DLR_depth(a->right))+1;
    else 
        return 0;
}