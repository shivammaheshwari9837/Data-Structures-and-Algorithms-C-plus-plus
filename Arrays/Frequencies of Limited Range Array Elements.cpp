/*

Ques:- Given an array A[] of N positive integers which can contain integers from 1 to N where elements can be repeated or can be absent from the array. Your task is to 
count frequency of all elements from 1 to N.

Concept:- 1)We used the concept of storing information at the particular index
          2)Reduce every arr[i] by 1,so our values will be in the range from 0 to n-1
          3)Whenever we encountered a value, we reach at that index and increase value by n ,ie. arr[arr[i]%n] += n 
          4)Then at end,our answer will be arr[i]/n
          
Time - O(n) , Space - O(1)

/*

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
        --arr1[i]; //reducing the values
    }
    
    for(int i=0;i<n;++i)
    {
        arr1[arr1[i]%n]+=n; //doing calculations
    }
    
    for(int i=0;i<n;++i)
    cout<<arr1[i]/n<<" ";
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
