/*

Ques:- Given an array arr[] of size N where every element is in range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]]. This should be done with 
O(1) extra space.

Concept:- 1) Here, We will use the formula Dividend = Divisor * Quotient + Remainder
              where Divisor = size of array
                         Quotient = New number at index i after rearrangement
                         Remainder = Old Number at index i before rearrangement
                         Dividend = The number stored at index i

          2) While Traversing the array, we will Look for the value at arr[arr[i]] (which is to be stored at index i), multiply it with Divisor (size of array), and add the 
          old value present at arr[i] to it.
          3)Divisor is a value which is higher then values in array (in this case n - size of array, as array elements are between 0 to n-1)

          4)Obviously, don't forget to remove the multiplier n from the values while accessing and outputting the new values.
          
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
	
	ll arr1[n];
	
	for(int i=0;i<n;++i)
	{
		cin>>arr1[i];
	}
	
	for(int i=0;i<n;++i)
	{
		ll old = arr1[arr1[i]]%n;  //getting the values initially at index
		arr1[i] = old*n + arr1[i]; //putting value using mathemactical formula as above
	}
	
	for(int i=0;i<n;++i)
	{
		cout<<arr1[i]/n<<" "; //printing the new values
	}
}

int main()
{
	int test;
	cin>>test;
	
	for(int i=0;i<test;++i)
	{
		work();
		cout<<"\n";
	}
	
	return 0;
}
