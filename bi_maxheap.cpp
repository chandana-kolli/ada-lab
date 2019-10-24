#include <bits/stdc++.h> 
using namespace std;

bool checkHeap(int arr[],  int n) 
{ 
    for (int i=0; i<=(n-2)/2; i++) 
    { 
        if (arr[2*i +1] > arr[i]) 
                return false; 
  
        if (2*i+2 < n && arr[2*i+2] > arr[i]) 
                return false; 
    } 
    return true; 
}
  
int main() 
{ 
    int arr[40],n;
    cout<<"How many elements?: ";
    cin>>n;
    cout<<"enter array:"<<endl;
    for(int i=0;i<n;i++)
    {cin>>arr[i];}
  
    if(checkHeap(arr, n)==true)
	printf("Yes,it is a binary max heap\n");
    else
	printf("No,it is not a binary max heap\n"); 
  
    return 0; 
} 
