#include<stdio.h>
#include<stdlib.h>
int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else{
        return b;
    }
}
void knapsack(int cap,int obj,int prf[],int wts[])
{
    int v[100][100],ans[10];
    for(int i=0;i<=cap;i++)
    {
        v[0][i]=0;
    }
    for(int i=1;i<=cap;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            if(j>=wts[i])
            {
                v[i][j]=max(v[i-1][j],v[i-1][j-wts[i]] + prf[i]);
            }
            else
            {
                v[i][j]=v[i-1][j];
            }
        }
    }
    for(int i=1;i<=obj;i++)
    {
        ans[i]=0;
    }
    int a=obj,b=cap;
    while(a>0 && b>0)
    {
        if(v[a][b]!=v[a-1][b])
        {
            ans[a]=1;
            b=b-wts[a];
        }
        a--;
    }
    int sum=0;
    for(int i=1;i<=obj;i++)
    {
        if(ans[i]==1)
        {
            printf("%d\t",i);
            sum+=prf[i];
        }
    }
    printf("\ntotal profits:%d",sum);
}
void main()
{
    int wts[10], prf[10],obj,cap;
    printf("Enter the number of objects\n");
    scanf("%d",&obj);
    printf("enter weights of objects\n");
    for(int i=1;i<=obj;i++)
    {
         scanf("%d",&wts[i]);
    }
    printf("enter profits of objects\n");
    for(int i=1;i<=obj;i++)
    {
         scanf("%d",&prf[i]);
    }
    printf("enter capacity\n");
    scanf("%d",&cap);
    knapsack(cap,obj,prf,wts);
}