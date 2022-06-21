#include<stdio.h>
#include<stdlib.h>

int no_edges=1,min_cost=0;
void main()
{
    int cost[20][20],n,parent[20],min,a,u,b,v;
    printf("enter the no of nodes:\n");
    scanf("%d",&n);
    printf("enter the cost matrix:\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        parent[i]=0;
    }
    printf("edges of spanning tree are\n");
    while(no_edges<n)
    {
      min=999;
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                a=u=i;
                b=v=j;

            }
        }
      }
      while(parent[u])
      {
        u=parent[u];
      }
      while(parent[v])
      {
        v=parent[v];
      }
      if(u!=v)
      {
        printf("edge %d from (%d->%d) = %d",no_edges++,a,b,min);
        min_cost=min_cost+min;
        parent[v]=u;

      }
      cost[a][b]=cost[b][a]=999;
    }
    printf("the total cost is:%d",min_cost);
}