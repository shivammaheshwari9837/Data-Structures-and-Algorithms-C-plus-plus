/*

Ques:- Implement Radix Sort

Concept:-1) For each digit i where i varies from the least significant digit to the most significant digit of a number
         2)Sort input array using countsort algorithm according to ith digit.

Time - O((n+b) * log(base b)maxx) , where n = number of elements in the array
                                    b = base of the numbers in the array
                                    maxx = maximum element in the arry

*/

#include<bits/stdc++.h>
using namespace std;
#define range 10 // since base 10 numbers are present in the array(0-9)

void buildRadix(int arr[],int n,int mul)
{
	int fre[range] = {0}; //frequency array
	int output[n];

	for(int i=0;i<n;++i)
	{
		++fre[(arr[i]/mul)%range]; //mapping the value according to the digit
	}

	for(int i=1;i<range;++i)
	{
		fre[i]+=fre[i-1]; //to know where actually value lies in the original array
	}

	for(int i=n-1;i>=0;--i)
	{
		output[fre[(arr[i]/mul)%range] - 1] = arr[i]; //putting the value in the original place in the current pass
		--fre[(arr[i]/mul)%range]; //reducing the frequency 
	}

	for(int i=0;i<n;++i)
	{
		arr[i] = output[i];
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

void radixSort(int arr[],int n,int lar)
{
	int mul = 1; //used to find the nth digit from last
	while(lar)
	{
		buildRadix(arr,n,mul);
		mul*=10; // finding the ith digit from last
		lar/=10;
	}
}

void work()
{
	int n;
	cin>>n;

	int arr1[n];
	int lar = -1;

	for(int i=0;i<n;++i)
	{
		cin>>arr1[i];
		lar = max(lar,arr1[i]); //finding the max element in the array
	}

	radixSort(arr1,n,lar);


}

int main()
{
	int test = 1;

	for(int i=0;i<test;++i)
	{
		work();
		// cout<<"\n";
	}

	return 0;
}
