/*

Ques:- Given a number K and string S of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of S atmost K times.

Concept:- 1)Consider every ith index and swap it with every possible next element in the string
          2)We have two choices:- 
                                a)Either swap the cuurent index of a string with all the preceding ones
                                b)Do nothing,and save swaps for some further operations
                                
Time - O(n^n) [Exponential]

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isLarge(string str,string &ans)
{
	for(int i=0;i<str.size();++i)
	{
		int num1 = str[i]-'0';
		int num2 = ans[i]-'0';
		
		if(num1 > num2)
		return true;
		else if(num1 < num2)
		return false;
	}
	
}

void maxKSwaps(string str,string &ans,int k,int index)
{
	//base...
	if(k == 0 || index == str.size()-1) //is swaps over or string ends
	return;
	
	
	maxKSwaps(str,ans,k,index+1); //do nothing , just increase the index
	
	for(int i=index+1;i<str.size();++i) //swap with all digits from index+1 to end of string
	{
		swap(str[index],str[i]);  //swap with ith index
		
		if(isLarge(str,ans)) //check if it is larger
		ans = str;
		
		maxKSwaps(str,ans,k-1,index+1); //call for further swaps
		
		swap(str[index],str[i]);  //backtrack the swap done 
	}
}

void work()
{
    int k;
    cin>>k;
    
    string str;
    cin>>str;
    
    string ans = str;
    
    maxKSwaps(str,ans,k,0); //(given string,the string which keeps the answer,k operations,cuurent index)
    
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
