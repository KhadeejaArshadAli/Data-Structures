#include<stdio.h>
#include<stdlib.h>

int main(void)
{

int c[4][4];
//int** ja = new int*[4];
int **a,**b;
a = new int*[4];
b = new int*[4];
printf("&a = %u a = %u , &b = %u , b = %u \n",&a,a,&b,b); 
//int C[4]={3,6,2,5};
int C[4]={4,4,4,4};
for(int i=0;i<4;i++)
 { a[i] = new int(C[i]);
 b[i] = new int(C[i]);
 }
//int a[4][4],b[4][4];

for(int x=0;x<4;x++)
 for(int y=0;y<C[x];y++)
{a[x][y]=b[x][y]=x*C[x]+y;}

for(int x=0;x<4;x++)
 printf("&a[%d]= %u , %u , &b[%d] = %u , %u \n",x,&a[x],a[x],x,&b[x],b[x]);


for(int x=0;x<4;x++)
 for(int y=0;y<C[x];y++)
printf("a[%d][%d] = %d @ %u\n",x,y,a[x][y],&a[x][y]);

for(int x=0;x<4;x++)
 for(int y=0;y<4;y++)
printf("c[%d][%d] = %d @ %u\n",x,y,c[x][y],&c[x][y]);

for(int x=0;x<4;x++)
for(int y=0;y<C[x];y++)
printf("b[%d][%d] = %d @ %u\n",x,y,b[x][y],&b[x][y]);

return 0;
}