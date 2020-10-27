/*

Ques:- Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which 
       reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).
       
Concept:- 1)The idea is to generate all even length and odd length palindromes and keep track of the longest palindrome seen so far.
          2) Step to generate odd length palindrome:
                Fix a centre and expand in both directions for longer palindromes.
          3)Step to generate even length palindrome
                Fix two centre ( low and high ) and expand in both directions for longer palindromes.
                

Time - O(n^2)
Space - O(1)
       

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void odd(int index,string &str,int &siz,int &ans,int &edge1,int &edge2) //here we expand the all valid odd length centre palindrome having 1 centre
{
    int left = index,right = index;
    
    while(left>=0 && right<siz)
    {
        if(str[left] == str[right])
        {
            if((right-left+1) > ans)
            {
              ans = right-left+1;
              edge1 = left;
              edge2 = right;
            }
            --left;
            ++right;
        }
        else
        break;
    }
}

void even(int left,int right,string &str,int &siz,int &ans,int &edge1,int &edge2) //here we expand all even length palindrome having two centres initially
{
    while(left>=0 && right<siz)
    {
        if(str[left] == str[right])
        {
              if((right-left+1) > ans)
              {
                ans = right-left+1;
                edge1 = left;
                edge2 = right;
              }
            --left;
            ++right;
        }
        else
        break;
    }
}

void work()
{
    string str;
    cin>>str;
    
    int ans = 1;
    int siz = str.length();
    int edge1 = 0,edge2 = 0;
    
    //odd length...
    for(int i=0;i<siz;++i)
    {
        odd(i,str,siz,ans,edge1,edge2);
    }
    
    //even length....
    for(int i=0;i<siz-1;++i)
    {
        even(i,i+1,str,siz,ans,edge1,edge2);
    }
    
    for(int i=edge1;i<=edge2;++i)
    {
    	cout<<str[i];
	  }
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
