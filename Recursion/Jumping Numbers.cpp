/*

Ques 37:- Jumping Numbers(GFG)

PS:- Given a positive number X. Find all Jumping Numbers smaller than or equal to X. 
Jumping Number: A number is called Jumping Number if all adjacent digits in it differ by only 1. All single digit numbers are considered as Jumping Numbers. 
For example 7, 8987 and 4343456 are Jumping numbers but 796 and 89098 are not.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define prime 3
#define mod 1000000007

void calculate(int limit,int curr,vector<int> &ans)
{
	if(curr>limit)
	return;
	
	ans.push_back(curr);
	
	int val = curr%10;
	
	if(val == 0)
	{
		calculate(limit,curr*10 + (val + 1),ans);
	}
	else if(val == 9)
	{
		calculate(limit,curr*10 + (val - 1),ans);
	}
	else
	{
		calculate(limit,curr*10 + (val + 1),ans);
		calculate(limit,curr*10 + (val - 1),ans);
	}
	
	return;
}


void work()
{
	int n;
	cin>>n;
	
	vector<int> ans;
	ans.push_back(0);
	
	
	for(int i=1;i<=9;++i)
	{
		calculate(n,i,ans);
	}
	
	sort(ans.begin(),ans.end());
	
	for(int i=0;i<ans.size();++i)
	cout<<ans[i]<<" ";
}

int main()
 {
	ll test;
	cin>>test;
	cin.ignore();
	for(int i=0;i<test;++i)
	{
	    work();
	    cout<<"\n";
	}
	return 0;
}
