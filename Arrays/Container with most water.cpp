/*

Ques:- Given N non-negative integers a_1, a_2, ..., a_n  where each represents a point at coordinate  (i, a_i) . 
N vertical lines are drawn such that the two endpoints of line i is at  (i, a_i)  and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Concept:- 1)Uses two pointers approach
          2)if array[left]<array[right],than try to maximize the left value,so as we know area = (right-left)*(minimum(array[left],array[right] ); same with right pointer

Time - O(n) 

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int> 

void work()
{
    int n;
    cin>>n;
    
    int arr1[n];
    for(int i=0;i<n;++i)
    cin>>arr1[i];
    
    int left = 0,right = n-1;
    int area = INT_MIN;
    
    while(left < right)
    {
    	area = max(area,(right - left) * min(arr1[left],arr1[right]));
    	
    	if(arr1[left] < arr1[right])
    	++left;
    	else
    	--right;
	}
	
	cout<<area;
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
