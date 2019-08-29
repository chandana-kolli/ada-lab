#include<stdio.h>
#include<stdlib.h>
void bubble(int A[],int n);
void selection(int A[],int n);
void merge_sort(int A[],int i,int j);
void merge(int A[],int i1,int j1,int i2,int j2);
int count2=0,count3=0;

void bubble(int A[],int n)
{
	int i,j,temp;
	int count1=0;
	for(i=0;i<=n-2;i++)
	{
		for(j=0;j<=n-2-i;j++)
		{
			if(A[j]>A[j+1])
			{
				count1++;
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}

	}
	printf("\nbubble sort : %d comparisions\n",count1);

}
void selection(int A[],int n)
{
	int i,j,temp,min;
	for(i=0;i<=n-2;i++)
	{	min=i;
		for(j=i+1;j<=n-1;j++)
		{
			count2=count2+1;
			if(A[min]>A[j])
			{	
				//count2=count2+1;
				min=j;
			}
		}

			//if(min!=i)
			{
				temp=A[min];
				A[min]=A[i];
				A[i]=temp;
			}
		

	}
	//for(i=0;i<n;i++)
	//{printf("%d\t",A[i]);}
	//printf("selection sort : %d comparisions\n",count2);
}
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
	int temp[100];
	int i,j,k;
	i=i1;
	j=i2;
	k=0;
	while(i<=j1 && j<=j2)
	{
		if(A[i]<A[j])
			{count3++;
			temp[k++]=A[i++];}
		else
			{count3++;
			temp[k++]=A[j++];}
	}
	while(i<=j1)
	{temp[k++]=A[i++];}
	while(j<=j2)
	{temp[k++]=A[j++];}
	for(i=i1,j=0;i<=j2;i++,j++)
	{A[i]=temp[j];}
	//printf("merge sort : %d comparisions\n",count3);

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
	bubble(A,n);
	selection(A,n);
	printf("selection sort : %d comparisions\n",count2);
	merge_sort(A,0,n-1);
	printf("merge sort : %d comparisions\n",count3);
	//for(i=0;i<n;i++)
	//{printf("%d\t",A[i]);}
}


