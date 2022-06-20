#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 500

int t[MAX];
void shifttable(char p[])
{
    int m;
    m=strlen(p);
    for(int i=0;i<MAX;i++)
    {
        t[i]=m;
    }
    for(int j=0;j<m-1;j++)
    {
       t[p[j]]=m-1-j;
    }

}
int horspool(char src[],char p[])
{
    int i,j,k,m,n;
    m=strlen(p);
    n=strlen(src);
    printf("Length of text = %d\n",n);
    printf("Length of pattern = %d\n",m);
    i=m-1;
    while(i<n)
    {
        k=0;
        while((k<m) && (p[m-1-k]==src[i-k]))
        {
            k++;
        }
        if(k==m)
        {
            return (i-m+1);
        }
        else{
            i+=t[src[i]];
        }
        
    }
    return -1;

}

void main()
{
    char src[100],p[100];
    int pos;
    printf("enter the text:\n");
    gets(src);
    printf("enter the substring:\n");
    gets(p);
    shifttable(p);
    pos=horspool(src,p);
    if(pos>=0)
    {
        printf("\n the substring is found startnig from position %d",pos+1);

    }
    else
    {
        printf("pattern not found");
    }


}