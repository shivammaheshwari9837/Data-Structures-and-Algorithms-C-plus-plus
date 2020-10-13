/*

Ques:- Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the 
        minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

        An egg that survives a fall can be used again.
        A broken egg must be discarded.
        The effect of a fall is the same for all eggs.
        If the egg doesn't break at a certain floor, it will not break at any floor below.
        If the eggs breaks at a certain floor, it will break at any floor above.
        
Conecpt:- 1)It is variation of MCM(matrix chain multiplication)
          2)Here we divide the array into all possible parts
          3)We have choices:- a)if some egg is break at some ith floor,than we should search our critical floor in downards direction,ie.reduce the floor
                              b) if egg is not broken at some ith floor,than should search our critical floor in upwards direction, ie. floor left = totalFloor- currFloor
                              
                              
Time - O(n * k * k)
Space - O(n * k)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[15][60];

int egg(int eggLeft,int flr)
{
    //base....
    if(flr == 0 || flr == 1)//if no floor left,or one left,than only 1 steps take place
    return 1;
    
    if(eggLeft == 1) //if one egg left,than we try to find the critical floor from bottom itself
    return flr;
    
    if(dp[eggLeft][flr] != -1)
    return dp[eggLeft][flr];
    
    
    int temp = INT_MAX;
    
    for(int k=1;k<=flr;++k) //setting up every floor as critical floor
    {
        int t1 = 1 + max(egg(eggLeft-1,k-1),egg(eggLeft,flr-k)); //both choices as written above,finding the worst case...
        temp = min(t1,temp); //finding the minimum
    }
    
    return dp[eggLeft][flr] = temp;
}

void work()
{
    int n,k;
    cin>>n>>k;
    
    for(int i=0;i<=n;++i) 
    for(int j=0;j<=k;++j)
    dp[i][j] = -1;
    
    int ans = egg(n,k);
    cout<<ans;
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
