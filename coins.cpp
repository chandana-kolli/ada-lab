#include<bits/stdc++.h>
using namespace std;
#define A 100
int minval(int a,int b)
{
	return a>b?b:a;
}
int min_coins(int d[4],int C[A+1],int S[A+1])
{
	int min,coin;
	C[0]=0;
	S[0]=0;
	for(int p=1;p<=A;p++)
	{
		min=INT_MAX;
			
		for(int i=1;i<=3;i++)
		{
			if(d[i]<=p)
				{if(1 + C[p - d[i]] < min) 
				
	   				{min = 1 + C[p - d[i]];
		  			coin = i;}
        			}

		}
		C[p] = min;
    		S[p] = coin;
	}
	return C[A];

}
void display(int S[],int d[])
{
	int a = A;
  	while(a > 0) {
    	printf("Use coin of denomination: %d\n", d[S[a]]);
    	a = a - d[S[a]];
  }
}
int main()
{
	int d[4]={0,1,2,5};
	int C[A+1]={0};
	int S[A+1]={0};
	int m=min_coins(d,C,S);
	cout<<"number of coins: "<<m<<endl;
	display(S,d);

}
