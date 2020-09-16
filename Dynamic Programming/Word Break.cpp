/*

Ques :- Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words.

Concept:- 1)Here in recursion we have only two valid choices---> 1)if possible to break as word found in the dictionery,just break the string here(for some L to R)
                                                                 2)just do not break the string
                                                                 
          2)Than you see sub-problems overalap in the recusion...,apply DP
  
 Time - (n * n * length of dictionary * current word_length) [n = length of the given string]
 Space - O(n * n)
*/

#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool check(int st,int bk,string &str,vector<string> &dict) //check the current substring in the range of string is present in the dictionery or not
{
	string temp;
	
	for(int i=st;i<bk;++i)
	temp.push_back(str[i]);
	
	for(int i=0;i<dict.size();++i)
	{
		if(temp.compare(dict[i]) == 0)
		return true;
	}
	return false;
}

bool segment(int st,int bk,string &str,vector<string> &dict)
{
	//base...
	if(bk == str.size()) //if upper range reaches to end of string
	{
		if(check(st,bk,str,dict)) //if still possible to break
		{
// 			cout<<st<<" "<<bk<<"\n";
			return true;
		}
		else
		return false;
	}
	
	if(dp[st][bk] != -1)
	return dp[st][bk];
	
	bool a = false,b = false;
	
	if(check(st,bk,str,dict)) //if possible to break
	a = segment(bk,bk+1,str,dict); //break here, thus now new segment will be from cuurent_break and upper range will be break+1
	
	//not break it..
	b = segment(st,bk+1,str,dict); //just add current alphabet into the segement
	
	return dp[st][bk] = (a | b);
}

void work()
{
	int n;
	cin>>n;
	
	vector<string> dict(n);
	
	for(int i=0;i<n;++i)
	cin>>dict[i];
	
	string str;
	cin>>str;
	
	for(int i=0;i<=str.size();++i)
	for(int j=0;j<=str.size();++j)
	dp[i][j] = -1;
	
	int ans = segment(0,1,str,dict);  // ( start of the word , end of the word + 1,given string , dictionery)
	cout<<ans;
}

int main()
{
	int test;
	cin>>test;
	
	while(test--)
	{
		work();
		cout<<"\n";
	}
	return 0;
}
