/*

Ques:- Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Concept:- 1)Since we needed the subarray,we break aur chain if we found something smaller
          2)Thus uses similar to DP approach
          
Time - O(n)
Space - O(1)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void work()
{
    int n;
    cin>>n;
    
    int arr1[n];
    for(int i=0;i<n;++i)
    cin>>arr1[i];
    
    int maxSoFar = arr1[0]; //setting up initial values,the final result
    int currMax = arr1[0]; //helps to maintain the subarray property
    
    for(int i=1;i<n;++i)
    {
        currMax = max(arr1[i],arr1[i]+currMax); //maintains the subarray 
        maxSoFar = max(currMax,maxSoFar);
    }
    
    cout<<maxSoFar;
}

int main()
 {
	ll test;
	cin>>test;
	for(int i=0;i<test;++i)
	{
	    work();
	    cout<<"\n";
	}
	return 0;
}
