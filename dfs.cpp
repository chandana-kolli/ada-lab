#include<bits/stdc++.h>
using namespace std;
int visited[10],adjacent[10][10];
void DFS(int v,int n)
{
	visited[v]=1;
	cout<<v<<endl;
	for(int i=0;i<n;i++)
	{
		if(adjacent[v][i]==1 && visited[i]==0)
			DFS(i,n);
	}	
}
int main()
{
	int i,j,n;
	cout<<"how many nodes?";
	cin>>n;
	cout<<"enter into adjacency matrix"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>adjacent[i][j];
		}
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{visited[i]=0;}
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
			DFS(i,n);
	}
	return 0;
}
