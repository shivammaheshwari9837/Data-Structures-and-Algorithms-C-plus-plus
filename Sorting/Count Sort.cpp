/*

Ques:- Implement Count Sort

Concept:- 1)the frequencies of distinct elements of the array to be sorted is counted and stored in an auxiliary array, by mapping its value as an index of the auxiliary array.

Time - O(n+k), where k is the value of max element 
Space - O(k)

*/


#include<bits/stdc++.h>
using namespace std;

void work()
{
	int n;
	cin>>n;

	int k = -1; //max_element

	int arr1[n];

	for(int i=0;i<n;++i)
	{
		cin>>arr1[i];
		k = max(k,arr1[i]); //finding the max element 
	}

	int aux[k+1] = {0};

	for(int i=0;i<n;++i)
	{
		++aux[arr1[i]];  // mapping with respect to index
	}

	for(int i=1;i<=k;++i)
	{
		if(aux[i] != 0)
		{
			cout<<i<<" "<<aux[i]<<"\n";
		}
	}
}

int main()
{
	int test = 1;
	// cin>>test;

	for(int i=0;i<test;++i)
	{
		work();
		cout<<"\n";
	}
	return 0;
}
