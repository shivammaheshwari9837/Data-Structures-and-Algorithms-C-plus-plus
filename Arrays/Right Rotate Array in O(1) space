/*

Ques :- Given an array of n size, right roatate it some d times

Concept:- 1)Here we will observe that there forms a cycle of some sets that is been juggled ie. cycle is made.
          2)In each cycle,we just start to interchange the required values.
          3)the number of sets/cycles will be gcd(n,d)
          
Time Complexity = O(n * gcd(n,d) ie. O(n^2)

*/

#include<bits/stdc++.h>
using namespace std;

void work()
{
	int n,d;
	cin>>n>>d;
	
	int arr1[n];
	
	for(int i=0;i<n;++i)
	cin>>arr1[i];
	
	int sets = __gcd(d,n);  //number of cycles/sets
	int temp1,temp2,k;
	
	for(int i=0;i<sets;++i) //number of possible cycles
	{
		int j = i;
		temp1 = arr1[i];
		while(1) //looping through the current cycle
		{
			k = (j+d)%n; //controlling the index
			
			temp2 = arr1[k];  //swapping the values
			arr1[k] = temp1;  //swapping the values
			temp1 = temp2;  //swapping the values
			j = k;          making j ready for next index
			
			if(k == i) //to avoid the infinite loop or retracing some index again
			break;
		}
	}
	
	for(int i=0;i<n;++i)
	cout<<arr1[i]<<" ";
	
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
