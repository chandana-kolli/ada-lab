#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int search(int A[],int n,int k)
{
    int l=0,h=n-1,mid;
    while (l <= h)
    {
        mid = (l+h)/2;
        if (A[mid] == k)
            return 1;
        if (k>A[mid])
            l=mid+1;
        else
            h=mid-1;
    }
    return -1;
}
int main()
{
    int A[200],n,k,i,result;
    printf("How many elements");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        A[i]=rand();
    }
    sort(A,A+n);
    for(i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
    printf("\nWhich element to search");
    scanf("%d",&k);
    result=search(A,n,k);
    if(result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present");
    return 0;
}
