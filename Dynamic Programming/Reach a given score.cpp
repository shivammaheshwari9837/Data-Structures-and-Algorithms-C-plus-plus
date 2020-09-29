/*

Ques:- Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find the number of distinct combinations to reach the given score.

Concept:- 1)Nothing but similar to basic coin change DP problem 

Time - O(n)
Space - O(n)

*/

#include<bits/stdc++.h>

using namespace std;
int coins[] = {3,5,10};
const int siz = 1005;
int dp[siz][3];

int ways(int sum,int index)
{
	//base....
	if(sum < 0 || index >= 3)
	return 0;
	if(sum == 0)
	return 1;
	
	if(dp[sum][index] != -1)
	return dp[sum][index];
	
	int a = 0,b = 0;
	
	if(coins[index] <= sum)
	{
		//take...
		a = ways(sum-coins[index],index);
		//not take it...
		b = ways(sum,index+1);
	}
	else
	{
		//not take it..
		a = ways(sum,index+1);
	}
	
	return dp[sum][index] = a+b;
}

void work()
{
    int n;
    cin>>n;
    
    for(int i=0;i<=n;++i) for(int j=0;j<=2;++j) dp[i][j] = -1;
    
    int ans = ways(n,0);
    cout<<ans;
}


int main()
{
     int test;
     cin >> test;
     for (int i = 0; i < test; ++i)
     {
         work();
         cout << "\n";
     }
    return 0;
}
