#include<bits/stdc++.h>
using namespace std;
#define N 5
void dijkstra(int c[][N],int src)
{
	int dist[N],i,j,vis[N],count,u,min;
	for(j=0;j<N;j++)
	{dist[j]=c[src][j];}
	for(j=0;j<N;j++)
	{vis[j]=0;}
	dist[src]=0;
	vis[src]=1;
	count=1;
	while(count!=N)
	{
		min=9999;
		for(j=0;j<N;j++)
		{
			if(dist[j]<min && vis[j]!=1)
			{min=dist[j];u=j;}	
		}
		vis[u]=1;
		
		for(j=0;j<N;j++)
		{
			if(min+c[u][j]<dist[j] && vis[j]!=1)
			{dist[j]=min+c[u][j];}
		}
		count+=1;
	}
	cout<<"shortest distance is"<<endl;
	for(i=0;i<N;i++)
	{
		cout<<src<<"-"<<i<<"  "<<dist[i]<<endl;
	}
}
int main()
{
	int c[N][N],i,j,src;
	cout<<"enter matrix of size "<<N<<" :"<<endl;
	for(i=0;i<N;i++)
	{	for(j=0;j<N;j++)
			{cin>>c[i][j];}
	}
	cout<<"enter source:";
	cin>>src;
	dijkstra(c,src);
	return 0;

}
