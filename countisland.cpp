#include<iostream>
#include <cstring>
using namespace std;
#define ROW 5
#define COL 5

int adj[5][5];

int isSafe(int m[][COL],int row,int col,bool visited[][COL])
{
	return ((row>=0) && (row<ROW) && (col>=0) && (col<COL) && m[row][col] && !visited[row][col]);
}

void dfs(int m[][COL],int row,int col,bool visited[][COL])
{
	static int rowNbr[]={-1,-1,-1,0,0,1,1,1};
	static int colNbr[]={-1,0,1,-1,1,-1,0,1};
	visited[row][col]=true;
	
	for(int k=0;k<8;++k)
	{
		if(isSafe(m,row+rowNbr[k],col+colNbr[k],visited))
			dfs(m,row+rowNbr[k],col+colNbr[k],visited);
	}
}

int countIslands(int m[][COL])
{
	bool visited[ROW][COL];
	memset(visited,0,sizeof(visited));
	int count=0;
	for(int i=0;i<ROW;++i)
	{
		for(int j=0;j<COL;++j)
		{
			if(m[i][j] && !visited[i][j])
			{
				dfs(m,i,j,visited);
				++count;
				
			}
		}
	}
	return count;
}

int main()
{
	int n;
	cout<<"enter the no. of nodes "<<endl;
	cin>>n;
	
	cout<<"enter the adjacency matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>adj[i][j];
			
	}
	
	
	cout<<"number of islands = "<<countIslands(adj);
return 0;

}
