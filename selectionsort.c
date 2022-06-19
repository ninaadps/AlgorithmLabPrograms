#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    clock_t start,end;
    int n;
    printf("Enter the number of elements to be stored");
    scanf("%d",&n);
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        int r=rand();
        arr[i]=r;
    }
    int min;
    start=clock();
    for(int i=0;i<n;i++)
    {    min=i;
        for(int j=i+1;j<n;j++)
        {
           if(arr[j]<arr[min])
           {
            min=j;
           }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    end=clock();
    double tt=(double)(end-start)/(CLOCKS_PER_SEC);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("time taken is: %e",tt);
}