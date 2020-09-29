/*

Ques:- Given an array arr[] of N non-negative integers representing height of blocks at index i as Ai where the width of each block is 1. Compute how much water can be
trapped in between blocks after raining.

Time - O(n)
Space - O(n)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void work()
{
    int n,temp1;
    cin>>n;
    
    int arr1[n],maxL[n],maxR[n];
    
    for(int i=0;i<n;++i)
    {
        cin>>arr1[i];
    }
    
    //Max left.....
    maxL[0]=arr1[0];
    temp1 = arr1[0];
    
    for(int i=1;i<n;++i)
    {
        maxL[i] = max(temp1,arr1[i]);
        
        temp1 = max(temp1,arr1[i]);
    }
    
    //Max right.....
    maxR[n-1] = arr1[n-1];
    temp1 = arr1[n-1];
    
    for(int i=n-2;i>=0;--i)
    {
        maxR[i] = max(temp1,arr1[i]);
        temp1 = max(temp1,arr1[i]);
    }
    
    //Calc....
    ll ans = 0;
    for(int i=0;i<n;++i)
    {
        ans+=(min(maxL[i],maxR[i]) - arr1[i]);
    }
    
    cout<<ans;
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

/*

Time - O(n)
Space - O(1)

*/
