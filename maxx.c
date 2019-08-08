#include<stdio.h>
#include<stdlib.h>
int find_max(int A[],int n)
{
	int i;
	int max=A[0];
	for(i=0;i<n;i++)
	{
		if(A[i]>max)
			max=A[i];
	}
	return max;
}
void main()
{
	int A[300],n,i,max;
	printf("How many elements?");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{A[i]=rand() % 100 + 1;}
	for(i=0;i<n;i++)
	{printf("%d\t",A[i]);}
	max=find_max(A,n);
	printf("\n%d is maximum",max);
}
