/*

Ques:- Link:   https://practice.geeksforgeeks.org/problems/minimum-platforms/0

Concept:- 1)We have to deal with arrival time and departure time here
          2)So, we sort both arrival and departure time array
          3)We take two pointer , one for that some train in arrived(here we increament our count), the other will provide the information that some train in departed(here 
          we decreament the count)
          
 Time - O(nlogn)
 Space - O(1)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long


void work()
{
    int n;
    cin>>n;
    
    int arr[n],dep[n];
    string temp;
    
    for(int i=0;i<n;++i)
    {
    	cin>>temp;
    	arr[i] = stoi(temp);
	}
	
	for(int i=0;i<n;++i)
	{
		cin>>temp;
		dep[i] = stoi(temp);
	}
	
	sort(arr,arr+n);
	sort(dep,dep+n);
	
	int curr = 1;
	int maxPlat = 1;
	
	int depart = 0,arrive = 1;
	
	while(depart<n && arrive<n)
	{
		if(dep[depart] < arr[arrive]) //if some departed, before the arrival of a train,we decreament the count
		{
			--curr;
			++depart;
		}
		else //if some train arrived, before the departure of a train,we increase the count
		{
			++curr;
			++arrive;
		}
		maxPlat = max(maxPlat,curr);
	}
	
	cout<<maxPlat;
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
