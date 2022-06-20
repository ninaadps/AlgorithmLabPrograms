#include<stdio.h>
#include<conio.h>
#include<math.h>
int min(int a, int b)
{
   if(a<b)
   {
    return a;
   }
   else
   {
    return b;
   }
}
void floyd(int r[10][10],int n)
{
for(int k=0;k<n;k++)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            r[i][j]=min(r[i][j],r[i][k]+r[k][j]);
        }
    }
}
}



void main()
{
int r[10][10],a[10][10],i,j,n;

printf("enter no of nodes\n");
scanf("%d",&n);
printf("enter the weight matrix\n");
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 {
  scanf("%d",&r[i][j]);
  }
}

floyd(r,n);
printf("the distance matrix\n");
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 {
  printf("%d\t",r[i][j]);
 }
 printf("\n");
}

}
