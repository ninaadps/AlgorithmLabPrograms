#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int ar[100],n;
    clock_t start,end;
    printf("Enter the number of elements to be stored");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        int r=rand();
        ar[i]=r;
    }
    start=clock();
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(ar[j]>ar[j+1])
            {
                int temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
    end=clock();
    double tt=(double)(end-start)/(CLOCKS_PER_SEC);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",ar[i]);
    }
    printf("\n");
    printf("time taken is: %e",tt);
    
}