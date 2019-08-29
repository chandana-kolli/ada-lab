#include<stdio.h>
#include<stdlib.h>
void merge_sort(int A[],int i,int j);
void merge(int A[],int i1,int j1,int i2,int j2);

void merge_sort(int A[],int i,int j)
{
	int mid;
	if(i<j)
	{
		mid=(i+j)/2;
		merge_sort(A,i,mid);
		merge_sort(A,mid+1,j);
		merge(A,i,mid,mid+1,j);
	}
}
void merge(int A[],int i1,int j1,int i2,int j2)
{
	int temp[50];
	int i,j,k;
	i=i1;
	j=i2;
	k=0;
	while(i<=j1 && j<=j2)
	{
		if(A[i]<A[j])
			temp[k++]=A[i++];
		else
			temp[k++]=A[j++];
	}
	while(i<=j1)
	{temp[k++]=A[i++];}
	while(j<=j2)
	{temp[k++]=A[j++];}
	for(i=i1,j=0;i<=j2;i++,j++)
	{A[i]=temp[j];}
}
void main()
{
	int n,A[200],i;
	printf("How many elements?");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{A[i]=rand()%100+1;}
	for(i=0;i<n;i++)
	{printf("%d\t",A[i]);}
	merge_sort(A,0,n-1);
	printf("\nafter sorting using mergesort:\n");
	for(i=0;i<n;i++)
	{printf("%d\t",A[i]);}
}
