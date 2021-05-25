#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SetSize 20
typedef struct 
{
    int size = SetSize;
    char *p;
}Hstring;
int input(char* p);
int compare(char* p ,char* q);
int main()
{
    Hstring a,b;
    a.p=(char*)malloc(SetSize*sizeof(char));
    b.p=(char*)malloc(SetSize*sizeof(char));
    input(a.p);  input(b.p);
    if(compare(a.p,b.p)) printf("equal\n");
    else printf("not equal\n");
    return 0;
}
int input(char* p){
    char _;
    int count = 0;
    memset(p,'\0',SetSize);
    while ((_ = getchar()) != '\n')
    {
        if(count >= SetSize-1) exit(-1);
        p[count] = _;
        count++;
    }
    return 0;
}
int compare(char *p,char *q){
    int i;
    for(i=0;p[i] != '\0' && q[i] != '\0'; i++)
    {
        if(p[i] != q[i]) return 0; 
    }
    if(p[i] == '\0' && q[i] == '\0') return 1;
    else return 0;
}