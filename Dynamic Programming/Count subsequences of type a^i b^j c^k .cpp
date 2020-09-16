/*

Ques:- Given a string s, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

Note: Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.

Method:- 1)Keep in mind the condition that, minimum one 'a',one 'b',one 'c' has to come in order of aa...bbb...cc...
         2)Keeping that we try to do recurion,thus can apply DP too(since sub-problems overlaps)

Time - O(n)
Space - O(n)

*/


#include<bits/stdc++.h>
using namespace std;

const int siz = 105;
int dp[siz][10];

int sub(int index,int rec,string &str) //{recent index for which we made up our choice,recent character we add in our subsequence,string given}
{
	char last; //{0 -> '*',1->'a' , 2->'b' , 3->'c' , 4->'@' ie. ending character}
	if(rec == 0)
	last = '*';
	else if(rec == 1)
	last = 'a';
	else if(rec == 2)
	last = 'b';
	else if(rec == 3)
	last = 'c';
	else
	last = '@';
	
	//base....
	
	if(index == str.size()-1) //if reaches to '@' ie. last character
	{
		if(last == 'c') // if last charater is 'c' ,than we have completed the subsequence
		return 1;
		else
		return 0;
	}
	
	if(index != -1 && dp[index][rec] != -1)
	return dp[index][rec];
	
	int temp = 0;
	
	for(int i=index+1;i<str.size();++i)
	{
		if(last == '*' && str[i] == 'a') //is starting of subsequence,we need 'a'
		temp += sub(i,1,str);
		else if(last == 'a') //if recent is 'a'
		{
			if(str[i] == 'a') //'a' is allowed
			temp += sub(i,1,str);
			else if(str[i] == 'b') //'b' is allowed
			temp += sub(i,2,str);
			else if(str[i] == '@')
			temp += sub(i,rec,str);
		}
		else if(last == 'b')
		{
			if(str[i] == 'b')
			temp += sub(i,2,str);
			else if(str[i] == 'c')
			temp += sub(i,3,str);
			else if(str[i] == '@')
			temp += sub(i,rec,str);
		}
		else if(last == 'c')
		{
			if(str[i] == 'c')
			temp += sub(i,3,str);
			else if(str[i] == '@')
			temp += sub(i,rec,str);
		}
	}
	
	if(index != -1)
	return ( dp[index][rec] = temp );
	else
	return temp;
}

void work()
{
	string str;
	cin>>str;
	
	str.push_back('@');
	
	for(int i=0;i<=str.size();++i)
	for(int j=0;j<=5;++j)
	dp[i][j] = -1;
	
	int ans = sub(-1,0,str);
	cout<<ans;
}

int main()
{
	int test;
	cin>>test;
	
	for(int i=0;i<test;++i)
	{
	    work();
	    cout<<"\n";
	}
	
	return 0;
}
