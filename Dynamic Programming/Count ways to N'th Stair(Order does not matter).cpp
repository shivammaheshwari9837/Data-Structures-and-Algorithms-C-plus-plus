/*

Ques:- There are N stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, 
the person can reach the top (order does not matter).
Note: Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered same.

Concept:- 1)Here the resultant recurrance relation will be f(n) = 1 + f(n-2); for n=0 and n=1,dp[n] = 1
          2)It is similar the classical problem too,but with few restrictions
          3)draw the recursive tree of the similar problem where all 3 ways have individual counts, than try that how we can avoid the extra path

*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int> 

const int siz = 1000005;
ll dp[siz];

//ll stair(int n)
//{
//	if(n == 0 || n == 1)
//	return ( dp[n] = 1 );
//	if(n<0)
//	return 0;
//	
//	if(dp[n] != -1)
//	return dp[n];
//	
//	int a = stair(n-2);
//	
//	return ( dp[n] = 1+a );
//}

void work()
{
    int n;
    cin>>n;
    
    dp[0] = dp[1] = 1;
    
    for(int i=2;i<=n;++i)
    dp[i] = 1 + dp[i-2];
    
    cout<<dp[n];
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


