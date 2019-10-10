#include<bits/stdc++.h>
using namespace std;
int adj[10][10],visited[10],n;
void BFS(int k)
{
	int i;
	queue<int>q;
	visited[k]=1;
	q.push(k);
	while(!q.empty())
	{
		int ele=q.front();
		q.pop();
		cout<<ele<<" ";
		for(i=0;i<n;i++)
		{
			if(adj[k][i]==1 && visited[i]==0)
			{
				q.push(i);
				visited[i]=1;
			}
		}
	}
	cout<<endl;
}
int main()
{
	int i,j;
	cout<<"How many nodes: ";
	cin>>n;
	for(i=0;i<n;i++)
		visited[i]=0;
	cout<<"enter adjacency matrix:"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>adj[i][j];
		}
	}
	cout<<endl;
	
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
			BFS(i);
	}
	return 0;
}
