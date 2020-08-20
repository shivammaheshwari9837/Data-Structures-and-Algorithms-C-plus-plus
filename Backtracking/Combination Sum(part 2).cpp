/*

Ques:- Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B.

ach number in A may only be used once in the combination.

Note:
   All numbers will be positive integers.
   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
   The combinations themselves must be sorted in ascending order.
   If there is no combination possible the print "Empty" (without qoutes).
   
Concept:- 1)Just similar to Combination Sum- part 1 with a little catch,ie. now choices are:-
                                                                                            a)either take an element
                                                                                            b)not take it in the sum
          2)By above approach, there is a repeatition of values,for that use map or set of strings

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void combi(vector<int> temp,int pos,vector<int> &arr,int sum,int tar,map<string,int> &ans)
{
	//base...
	if(sum == tar) //if current sum is equal to the target sum
	{
		string var;
		for(int i=0;i<temp.size();++i)
		{
			var.push_back(temp[i]+48);
		}
		++ans[var];//save it in the map to avoid repeatition
		return;
	}
	
	//base...
	if(sum>tar || pos>=arr.size()) //if currentSum>targetSum, or array finishes, return from here
	return;
	
	temp.push_back(arr[pos]); //take this element at currnt position and forward to next index
	combi(temp,pos+1,arr,sum+arr[pos],tar,ans);
	
	temp.pop_back(); //backtrack here
	combi(temp,pos+1,arr,sum,tar,ans); //not take it in the current sum,and forward to next index
	
	return;
}

void work()
{
    int n,x;
    cin>>n;
    
    vector<int> arr1(n); //used to remove the duplicates and sort it
    
    for(int i=0;i<n;++i)
    {
        cin>>arr1[i];
    }
    
    int tar;
    cin>>tar;
    
    sort(arr1.begin(),arr1.end());
    
    vector<int> temp;
    
	  map<string,int> ans;
    
    combi(temp,0,arr1,0,tar,ans);
    
    for(auto i=ans.begin();i!=ans.end();++i)
    {
    	string var = i->first;
    	cout<<"(";
    	for(int j=0;j<var.size();++j)
    	{
    		if(j != var.size()-1)
    		cout<<var[j]<<" ";
    		else
    		cout<<var[j];
		} 
		cout<<")";
	}
	
	if(ans.empty())
	cout<<"Empty";
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
