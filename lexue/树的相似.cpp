#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    char date;                          //储存数据
    struct tree *left,*right;           //分别为，左孩子和右孩子
}tree;
static int com[20];
static int i = 0;
static int ok = 1;
tree *creatA();                         
tree *creatB();                         
int main()
{
    tree *bit;
    char _;
    creatA();
    i = 0;
    _ = getchar();
    creatB();
    if (ok == 0)
        printf("A与B不相似\n");
    else
        printf("A与B相似\n");
    return 0;
}

tree *creatA(){
    tree *a = (tree*)malloc(sizeof(tree));
    char _;
    scanf("%c",&_);
    if (_ == '#')
        {free(a); a = NULL;com[i++] = 0;}
    else
    {
        com[i++] = 1;
        a->date = _;
        a->left = creatA();
        a->right = creatA();
    }
    return a;
}
tree *creatB(){
    tree *a = (tree*)malloc(sizeof(tree));
    char _;
    scanf("%c",&_);
    if (_ == '#')
        {free(a); a = NULL;if(com[i++] != 0)ok = 0; }
    else
    {
        if(com[i++] != 1)ok = 0;
        a->date = _;
        a->left = creatB();
        a->right = creatB();
    }
    return a;
}