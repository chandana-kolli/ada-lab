#include<stdio.h>
#include<stdlib.h>
void quick_sort(int A[],int l,int u);
int partition(int A[], int l,int u);
void swap(int a,int b);

void quick_sort(int a[],int l,int u)
{
	int j;
	if(l<u)
	{
		j=partition(a,l,u);
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,u);
	}
}
 
int partition(int a[],int l,int u)
{
	int v,i,j,temp;
	v=a[l];
	i=l;
	j=u+1;

	do
	{
		do
		{i++;}

		while(a[i]<v&&i<=u);

		do
		{j--;}
		while(v<a[j]);

		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<j);

	a[l]=a[j];
	a[j]=v;

	return(j);
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
	quick_sort(A,0,n-1);
	printf("\nafter sorting using quicksort:\n");
	for(i=0;i<n;i++)
	{printf("%d\t",A[i]);}
}