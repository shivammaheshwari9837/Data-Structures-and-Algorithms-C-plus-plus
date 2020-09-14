/*

Ques :- You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. 
You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amouint of money you can win if you go first.

Both of you must play optimally

Concept:- 1)Here a user plays smartly, while opponent always try to pick the maximum'
          2)So, when chance of user came in, he can pick either from left or right side
          3)When opponent plays, he picks the maximum too(since he plays optimally too)
       
Time - O(n^2)
space - O(n^2)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[105][105];

int optimal(int left,int right,bool chance,int arr1[])
{
    //base...
    
    if(left == right) //if single element left
    {
        if(chance) //if your chance just return the value
        return arr1[left];
        else
        return 0;
    }
    
    if(dp[left][right] != -1)
    return dp[left][right];
    
    int a = 0,b = 0;
    
    if(chance) //if your channce
    {
        //take left...
        a = optimal(left+1,right,false,arr1)+arr1[left]; 
        
        //take right...
        b = optimal(left,right-1,false,arr1)+arr1[right];
         return dp[left][right] = max(a,b);
    }
    else
    {
        // if(arr1[left] > arr1[right])
        a = optimal(left+1,right,true,arr1);
        // else
        b = optimal(left,right-1,true,arr1);
        
        return dp[left][right] = min(a,b); //Imp:----- if I try to pick maximum here, means try to provide maximum to opponet,than you will get minimum......,thus returning
                                              // minimu,so you get the maximum
    }
   
}

void work()
{
    int n;
    cin>>n;
    
    int arr1[n];
    
    for(int i=0;i<n;++i)
    cin>>arr1[i];
    
    for(int i=0;i<=n;++i)
    for(int j=0;j<=n;++j)
    dp[i][j] = -1;
    
    int ans = optimal(0,n-1,true,arr1); //{left end,right end,whom chance,array given}
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
