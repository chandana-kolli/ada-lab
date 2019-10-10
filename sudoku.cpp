#include<bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0
#define N 4
int grid[4][4];
bool FindUnassignedLocation(int grid[N][N],int &row,int &col);
bool isSafe(int grid[N][N],int row,int col,int num);
bool UsedInRow(int grid[N][N],int row,int num);
bool UsedInCol(int grid[N][N],int col,int num);
bool UsedInBox(int grid[N][N],int boxStartRow,int boxStartCol,int num);


bool FindUnassignedLocation(int grid[N][N],int &row,int &col)
{
	for(row=0;row<N;row++)
	{
		for(col=0;col<N;col++)
		{
			if(grid[row][col]==UNASSIGNED)
				return true;
		}
	}return false;
}
#define SQN 2
bool isSafe(int grid[N][N],int row,int col,int num)
{
	return !UsedInRow(grid,row,num) && !UsedInCol(grid,col,num) && !UsedInBox(grid,row-row%SQN,col-col%SQN,num);
}
bool UsedInRow(int grid[N][N],int row,int num)
{
	for(int col=0;col<N;col++)
	{
		if(grid[row][col]==num)
			return true;
	}return false;
}
bool UsedInCol(int grid[N][N],int col,int num)
{
	for(int row=0;row<N;row++)
	{
		if(grid[row][col]==num)
			return true;
	}return false;
}
bool UsedInBox(int grid[N][N],int boxStartRow,int boxStartCol,int num)
{
	for(int row=0;row<SQN;row++)
	{
		for(int col=0;col<SQN;col++)
		{
			if(grid[row+boxStartRow][col+boxStartCol]==num)
				return true;
		}
	}return false;
}
bool SolveSudoku(int grid[N][N])
{
	int row,col;
	if(!FindUnassignedLocation(grid,row,col))
		return true;
	for(int i=0;i<=N;i++)
	{
		if(isSafe(grid,row,col,i))
		{
	 		grid[row][col]=i;
			if(SolveSudoku(grid))
				return true;		
			grid[row][col]=UNASSIGNED;
		}
	}return false;
	
}
int main()
{
	int i,j;
	cout<<"enter sudoku puzzle:"<<endl;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			cin>>grid[i][j];
	}
	cout<<endl;
	if(SolveSudoku(grid))
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
				{cout<<grid[i][j]<<" ";}
			cout<<endl;
		}
	}
	else
		cout<<"No solution exists"<<endl;
	return 0;
}
