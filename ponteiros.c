#include <stdio.h>
#include <stdlib.h>

// exercicio 01
int main01(){
int i=30;
int v[]={1,2,3,4};
int * p= v; 
int * w=&v[2];
int * x=&i; 
}

//exercicio 02
int main02(){
int a=10;
int b=20;
int c=30;
int d=40;
int * v[]={&a,&b,&c,&d};
int **p=v;
for (int i = 0; i < 4; i++)
{ 
    printf("%d\n",**p);
    p++;
  
    
}
}

//exercicio 03
int main03(){
int v1[]={1,2,3};
int v2[]={4,5,6};
int *m[]={v1,v2};
int * p1=v1;
int * p2=v2;
int ** pm=m;
for (int i = 0; i < 2; i++)
{
    for (int e = 0; e < 3; e++)
    {
        printf("%d/n",m[i][e]);
    }
    
}}

