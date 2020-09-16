/*

Ques:- Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

        Return all such possible sentences.
        
Concept:- 1) First try to see this question ie. Word Break 1(gfg or Leetcode)
          Code Link:-    https://github.com/shivammaheshwari9837/DS-and-Algorithms/blob/master/Dynamic%20Programming/Word%20Break.cpp
          
          2)than we only have to print all valid possibilty in acending sorted order
          
Time - O(2^n  * current segment length)
        
*/


#include<bits/stdc++.h>
using namespace std;

vector<string>  ans;

bool check(int st,int bk,string &str,vector<string> &dict)
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

void segment(int st,int bk,string &str,vector<string> &dict,vector<string> temp)
{
	//base...
	if(bk == str.size())
	{
		if(check(st,bk,str,dict))
		{
			string p;
			for(int i=st;i<bk;++i)
			{
				p.push_back(str[i]);
			}
			temp.push_back(p);
			
			string x;
			
			for(int i=0;i<temp.size();++i)
			{
			    for(int j=0;j<temp[i].size();++j)
			    x.push_back(temp[i][j]);
			    
			    if(i!=temp.size()-1)
			    x.push_back(' ');
			}
			
			ans.push_back(x);
		}
		return;
	}
	
	//not break it..
	segment(st,bk+1,str,dict,temp);
	
	if(check(st,bk,str,dict))
	{
		string p;
		for(int i=st;i<bk;++i)
		{
			p.push_back(str[i]);
		}
		
		temp.push_back(p);
		segment(bk,bk+1,str,dict,temp);
	}
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
	
	vector<string> temp;
	
	ans.clear();
	
	segment(0,1,str,dict,temp);
	
	sort(ans.begin(),ans.end());
	
	for(int i=0;i<ans.size();++i)
	{
	    cout<<"("<<ans[i]<<")";
	}
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
