/*

Ques:- There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to 
connect the ropes with minimum cost.

Concept:- 1)Take two smallest rope size, and add sum of their cost
          2)Do this until minHeap size > 1
      
Time - O(nlogn)
Space - O(n)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long


void work()
{
    ll n;
    cin>>n;
    
    ll arr1[n];
    
    priority_queue<ll,vector<ll>,greater<ll> >min_heap;
    
    for(int i=0;i<n;++i)
    {
    	cin>>arr1[i];
    	min_heap.push(arr1[i]);
	}
    
    ll total_cost=0;
    
    while(min_heap.size()>1)
    {
    	ll cost1 = min_heap.top();
    	
    	min_heap.pop();
    	
    	ll cost2 = min_heap.top();
    	
    	min_heap.pop();
    	
    	total_cost+=(cost1 + cost2);
    	
    	min_heap.push(cost1 + cost2);
	}
	
	cout<<total_cost<<" ";
    
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
