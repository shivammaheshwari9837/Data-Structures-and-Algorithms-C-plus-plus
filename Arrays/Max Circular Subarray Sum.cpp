/*

Ques:- Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contigious subarray sum.

Concept:- 1)Here we have two possible answers--> a)answer can be from linear array(can be found from Kadane Algo) , let it be X
                                                 b)answer can be from wrapping or circular array
          2)Let be array 1,4,2,8,-5,-9,-5,-12,3 ; than answer cab be = totalSum - (a subarray with minimum sum, for the case of wrapping array) left it be Y
          3)Final answer = max(X,Y)
          4)Special case, when all elements are -ve(ie. -1,-2,-3), than answer will be always X as Y can leads to wrong answer
          
Time - O(n)

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
	{
		cin>>arr1[i];
	}
	
	int total = 0,maxSum = INT_MIN,minSum = INT_MAX;
	int s1 = 0,s2 = 0;
	
	for(int i=0;i<n;++i)
	{
		total+=arr1[i]; //finding total sum of the array
		
    //finding the maximum subarray sum using Kadane algo
		s1+=arr1[i]; 
		if(s1 > maxSum)
		maxSum = s1;
		if(s1 < 0)
		s1 = 0;
		
		
    //finding the minimum subarray sum using the modification in Kadane Algo
		s2+=arr1[i];
		if(s2 < minSum)
		minSum = s2;
		if(s2 > 0)
		s2 = 0;
	}
	
	if(maxSum < 0) //if all elements are negative
	cout<<maxSum;
	else
	{
		if(maxSum > total - minSum)
		cout<<maxSum;
		else
		cout<<total - minSum;
	}
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
