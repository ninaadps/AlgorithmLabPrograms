#include<stdio.h>
#include<stdlib.h>

void djikstra(int source,int cost[20][20],int visited[20],int d[20],int n)
{
    int i,j,min,u,w;
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
        d[i]=cost[source][i];
    }
    visited[source]=1;
    d[source]=0;
    for(j=2;j<=n;j++)
    {
        min=999;
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                if(d[i]<min)
                {
                    min=d[i];
                    u=i;
                }
            }
        }
        visited[u]=1;
        for(w=1;w<=n;w++)
        {
            if(d[u]+cost[u][w] < d[w])
            {
                d[w]=d[u]+cost[u][w];
            }
        }

    }
    
}
void main()
{
    int cost[20][20],d[20],n,visited[20],source;
    printf("enter no of vertices\n");
    scanf("%d",&n);
    printf("enter the cost matrix\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    printf("enter the source node\n");
    scanf("%d",&source);
    djikstra(source,cost,visited,d,n);
    for(int i=1;i<=n;i++)
    {
        if(i!=source)
        {
            printf("\n shortest path from %d to %d is %d",source,i,d[i]);
        }
    }

}