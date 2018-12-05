#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int a,b,c,d;
    int* convert(int n);
    void print(int* a);
    printf("Enter IP:");
    scanf("%d.%d.%d.%d",&a,&b,&c,&d);
    printf("The converted IP address is:");
    print(convert(a));
    printf("-");
    print(convert(b));
    printf("-");
    print(convert(c));
    printf("-");
    print(convert(d));
    system("pause");
    return 0;
}
int i,j;
int* convert(int n)
{
    int *p;
    extern int i,j;
    if(n==0)
    {
        p=(int*)malloc(sizeof(int));
        *p=0;
        j=0;
    }
    else if(n==1)
    {
        p=(int*)malloc(sizeof(int));
        *p=1;
        j=1;
    }
    else if(n>1)
    {
        for(i=0;i<100;i++)
        {
            if(n>=pow(2,i))
            {
                j=i+1;
            }
            else
                continue;
        }
        p=(int *)malloc(j*sizeof(int));
        for(i=0;i<j;i++)
        {
            if(n>1)
            {
                *(p+i)=n%2;
                n=n/2;
            }
            else if(n==1)
                *(p+i)=n;
        }
    }
    return(p);
}
 void print(int* a)
 {
     extern int i,j;
     if(j==8)
     {
        for(i=0;i<j;i++)
        {
            printf("%d",*(a+j-i-1));
        }
     }
     else if(j<8)
     {
         for(i=0;i<8-j;i++)
         {
             printf("0");
         }
         for(i=0;i<j;i++)
         {
             printf("%d",*(a+j-i-1));
         }
     }
     else if(j>8)
        printf("Input error!");
 }
