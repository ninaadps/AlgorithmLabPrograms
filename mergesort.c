#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void combine(int a[],int low,int mid,int high)
{  int temp[high+1];
   int i=low,k=low,j=mid+1;
   while(i<=mid && j<=high)
   {
     if(a[i]<a[j])
     {
        temp[k]=a[i];
        i++;
        k++;
     }
     else
     {
        temp[k]=a[j];
        j++;
        k++;
     }
   }
   while(i<=mid)
   {
    temp[k]=a[i];
    i++;
    k++;
   }
   while(j<=high)
   {
    temp[k]=a[j];
    j++;
    k++;
   }
   for(k=low;k<=high;k++)
   {
    a[k]=temp[k];
   }

}
void mergesort(int a[],int low,int high)
{
  int mid;
  if(low>=high)
  {
    return;
  }
  else
  {
    mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    combine(a,low,mid,high);

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
    mergesort(arr,0,n-1);
    end=clock();
    double tt=(double)(end-start)/(CLOCKS_PER_SEC);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("time taken is: %e",tt);
}