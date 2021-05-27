#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    struct tree *left,*right;
    int data;
}*bitree;
int useless;
void save(bitree &a,int val)
{ 
    if(a != NULL)
    {
        if(a->data > val) save(a->left,val); 
        if(a->data < val) save(a->right,val);
    }
    else 
    {
        a = (bitree) malloc(sizeof(tree));
        a->data = val;
        a->right = NULL;
        a->left = NULL;
    }
}
int LDR(tree *a){
    if (a != NULL)
    {
        LDR(a->left);
        printf("%d  ",a->data);
        LDR(a->right);
    }
    return 0;
}
int del(bitree a)
{
    scanf("%d",&useless);
    bitree p = a,q = NULL,k = NULL,kp = NULL;
    while ( p != NULL)     //寻找删除节点
    {
        if(p->data == useless ) break;
        if(p->data > useless)
        { 
            q = p;
            p = p->left;
        }
        if(p->data < useless) 
        {
            q = p;
            p = p->right;
        }
    }
    if(p == NULL ) return 0;
    else
    {
        if(p->right == NULL && p->left == NULL) 
        {
            if(q->right == p) q->right = NULL;
            else q->left = NULL;
            free(p);
        }
        else if (p->left == NULL && p->right !=NULL)   
        {
            if(q->right == p) {
                q->right = p->right;
                free(p);
            }
            else{
                q->left = p->right;
                free(p);
            }
        }
        else if(p->left != NULL && p->right ==NULL)
        {
            if(q->right == p) {
                q->right = p->left;
                free(p);
            }
            else{
                q->left = p->left;
                free(p);
            }
        }
        else
        {
            k = p->right;
            while (k->left != NULL) 
            {
                kp = k;
                k = k->left;
            }
            if(q->right == p)   q->right = k;
            if(q->left == p)    q->left = k;
            k->right = p->right;
            k->left = p->left;
            if(kp->left == k) kp->left == NULL;
            if(kp->right == k) kp->right ==NULL;
            free(k);
        }
        return 1;
    }
}
int main()
{
    int num,val;
    bitree bit = NULL;
    scanf("%d",&num);
    for (int i = 1; i <= num; i++)
    {
        scanf("%d",&val);
        save(bit,val);
        if(i == 1) printf("原始数据：");;
        printf("%d ",val);
    }
    printf("\n");
    printf("中序遍历结果：");
    LDR(bit);
    printf("\n");
    printf("删除结点后结果：");
    if(del(bit))
    {
        LDR(bit);
        printf("\n");
    }
    else
        printf("没有%d结点。\n",useless);
    return 0;
}