#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quicksort(int a[],int low,int high)
{  
   int i=low,j=high,pivot=low;
   if(i<j)
   {
    while(i<j)
    {
        while(a[i]<=a[pivot] && i<high)
        {
            i++;
        }
        while(a[j]>a[pivot])
        {
            j--;
        }
        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int x=a[j];
    a[j]=a[pivot];
    a[pivot]=x;
    quicksort(a,low,j-1);
    quicksort(a,j+1,high);

   }
}

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
   
    start=clock();
    quicksort(arr,0,n-1);
    end=clock();
    double tt=(double)(end-start)/(CLOCKS_PER_SEC);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("time taken is: %e",tt);
}