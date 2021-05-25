#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SetSize 25
typedef struct 
{
    int size;
    char* p;
}String;
void input(String &S);
int main()
{
    String obj,met;
    int i = 1,j = 1;
    obj.p = (char*)malloc(SetSize*sizeof(char));
    met.p = (char*)malloc(SetSize*sizeof(char));
    input(obj);  input(met);
    while (obj.p[i] != '\0' && met.p[j] != '\0')
    {
        if(obj.p[i] == met.p[j]) {i++;j++;}
        else {i=i-j+2;j=1;}
    }
    if (j >met.size)  {printf("%d\n",i-met.size); return 0;} 
    else return -1;
}
void input(String &S){
    char _;
    int count = 1;
    memset(S.p,'\0',SetSize);
    while((_ = getchar()) != '\n')
    {
        S.p[count++] = _;
    }
    S.p[0] = '\0'; S.size = count-1;
}

