#include<stdio.h>
#include<conio.h>
#include<math.h>
int max(int,int);
void warshal(int r[10][10],int n)
{
int i,j,k;
for(k=1;k<=n;k++)
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   r[i][j]=max(r[i][j],r[i][k]&&r[k][j]);
}

int max(int a, int b)
{
 if(a>b)
  return(a);
 else
  return(b);
}

void main()
{
int r[10][10],a[10][10],i,j,n;

printf("enter no of vertices\n");
scanf("%d",&n);
printf("enter adjacency matrix\n");
for(i=1;i<=n;i++)
{
 for(j=1;j<=n;j++)
 {
  scanf("%d",&r[i][j]);
  }
}

warshal(r,n);
printf("transitive closure\n");
for(i=1;i<=n;i++)
{
 for(j=1;j<=n;j++)
 {
  printf("%d\t",r[i][j]);
 }
 printf("\n");
}

}
