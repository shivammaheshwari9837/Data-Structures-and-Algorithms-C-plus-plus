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
    return flr;
    
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

/*


Concept:- 1)Another approach can be using a binary search , instead of linear search in recusive function to reduce time

Time - O(n * k * logk), n->eggs,k->floors
Space - O(n * k)

*/


int egg(int eggLeft,int flr,vector<vector<int>> &dp)
    {
        //base...
        if(flr == 0 || flr == 1)
            return flr;
        if(eggLeft == 1)
            return flr;
        
        if(dp[eggLeft][flr] != -1)
            return dp[eggLeft][flr];
        
        
        int temp = INT_MAX;
        int low = 1,upp = flr;
        
        while(low <= upp)
        {
            int mid = (low+upp)/2;
            int left = egg(eggLeft-1,mid-1,dp);
            int right = egg(eggLeft,flr-mid,dp);
            
            int t1 = 1 + max(left,right);
            
            if(left < right)   //since right is more than left and we need more in worst case 
                low = mid + 1; // so l=mid+1 to gain more temp for worst case : upward
            else 
                upp = mid - 1;   //left > right so we will go downward 
            
            temp = min(temp,t1);
        }
        
        return dp[eggLeft][flr] = temp;
    }
    
    int superEggDrop(int k, int n) {
        
        vector<vector<int> >dp(k+2,vector<int>(n+2,-1));
        
        int ans = egg(k,n,dp);
        return ans;
        
    }
