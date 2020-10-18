/*

Ques:- The first line of input contains integer T denoting the number of test cases. For each test case,  the first line of input contains an integer n denoting the size of 
       the array. Next line contains n space separated integers denoting the elements of the array. Next line contains an integer k denoting the number such that elements 
       less than and equal to k are group together. 
       
Concept:- 1)here first we know that all elements <= k,will be grouped together..
          2)So, we will maintian the window size of x(ie. elements <= k in array), and find the minimum elements > k,that surely be replaced, with valid elements too
          
Time - O(n)
Space - O(1)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void work()
{
    int n,k;
    cin>>n;
    
    int arr1[n];
    
    for(int i=0;i<n;++i) cin>>arr1[i];
    
    cin>>k;
    
    int inRange = 0,outRange = 0;
    
    for(int i=0;i<n;++i)
    {
        if(arr1[i] <= k)
        ++inRange;
    }
    
    for(int i=0;i<inRange;++i) //taking information of first window of size
    {
        if(arr1[i] > k)
        ++outRange;
    }
    
    int res = outRange;
    
    for(int i=0,j=inRange;j<n;++i,++j)
    {
        if(arr1[i] > k) //removing the elements in the window that are out
        --outRange;
        
        if(arr1[j] > k) //adding new elements in the window
        ++outRange;
        
        res = min(res,outRange);
    }
    
    cout<<res;
    
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
