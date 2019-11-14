#include<bits/stdc++.h>
using namespace std;
#define N 4
int minval(int a,int b)
{return a>b?b:a;}
void floyds(int A[][N])
{
	int i,j,k;
	for(k=0;k<N;k++)
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{A[i][j]=minval(A[i][j],(A[i][k]+A[k][j]));
			}
		}
	}
	cout<<"shortest distance matrix: "<<endl;
	for(int m=0;m<N;m++)
	{for(int n=0;n<N;n++)
		{
			cout<<A[m][n]<<" ";
		}cout<<endl;
	}
}
int main()
{
	int i,j,A[N][N];
	cout<<"enter matrix of size "<<N<<" :"<<endl;
	for(i=0;i<N;i++)
	{	for(j=0;j<N;j++)
			{cin>>A[i][j];}
	}
	//int A[N][N]={{0 ,999, 3, 999},{2 ,0 ,999, 999},{999, 7, 0, 1},{6, 999, 999, 0}};

	floyds(A);
	return 0;
}
