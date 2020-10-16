/*

Ques:- Given an integer, the task is to find factorial of the number.

Concept:- 1)it is very simple,we just store every digit of our answer to some array or string,so to store large values 
          2)For better understanding , multiply 1234*12 in the way that answer comes in one single iteration of number 1234...

Time - O(n * maxPossibleDigits)
Space - O(maxPossibleDigits)
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> mul(vector<int> &ans,int num) //{number to be multiplied, number through which have to multiply...}
{
    vector<int> temp;
    int carry = 0,t1;
    
    for(int i=ans.size()-1;i>0;--i) //ignoring the last 0th index digit since it will at end become a 2-digit number or so...
    {
        t1 = ans[i]*num + carry; 
        temp.push_back(t1%10);
        carry = t1/10;
    }
    
    t1 = ans[0]*num + carry; //finally taking the result of 0th index..
    
    while(t1 > 0) //breaking into single digit
    {
        temp.push_back(t1%10);
        t1 /= 10;
    }
    
    reverse(temp.begin(),temp.end()); //needed to be reversed 
    
    return temp;
}

void work()
{
    int n;
    cin>>n;
    
    vector<int> ans;
    ans.push_back(1);
    
    for(int i=2;i<=n;++i)
    {
        ans = mul(ans,i);
    }
    
    for(int i=0;i<ans.size();++i)
    cout<<ans[i];
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
