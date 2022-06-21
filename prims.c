#include<stdio.h>
#include<stdlib.h>

int no_edges=1,min_cost=0;
void main()
{
    int cost[20][20],n,visited[20],source,a,u,b,v;
    printf("enter number of nodes\n");
    scanf("%d",&n);
    printf("enter cost matrix\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
    }
    printf("enter the source node\n");
    scanf("%d",&source);
    visited[source]=1;
    printf("minimum cost spannign tree is\n");
    while(no_edges<n)
    {
        int min=999;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]==0)
                    {
                        continue;
                    }
                    else
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        if(visited[u]==0 || visited[v]==0)
        {
            printf("\nedge(%d) (%d->%d) = %d",no_edges++,a,b,min);
            min_cost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;

    }
    printf("\ntotal cost is : %d",min_cost);
}