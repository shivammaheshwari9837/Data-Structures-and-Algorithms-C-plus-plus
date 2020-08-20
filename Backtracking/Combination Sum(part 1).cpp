/*

Ques:- Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B. The same repeated number may be chosen from A unlimited 
number of times.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.
        
Concept:- 1)First remove all the duplicates ,and sort the array to get satisfy the condition 2,3 from question
          2)Than ,we have to choices --->
                                        a)Pick up current index value,add to current sum and repeat the process with this index(as repeatition is allowed)
                                        b)Pick up the next index value

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void combi(vector<int> temp,int pos,vector<int> &arr,int sum,int tar,vector<vector<int>> &ans)
{
	//base...
	if(sum == tar) //if current sum is equal to the target sum
	{
		ans.push_back(temp); //save it
		return;
	}
	
	//base...
	if(sum>tar || pos>=arr.size()) //if currentSum>targetSum, or array finishes, return from here
	return;
	
	temp.push_back(arr[pos]); //take this position element and push it to the current sum
	combi(temp,pos,arr,sum+arr[pos],tar,ans);
	
	temp.pop_back(); //backtrack here
	combi(temp,pos+1,arr,sum,tar,ans); //forward to next index
	
	return;
}

void work()
{
    int n,x;
    cin>>n;
    
    set<int> se1; //used to remove the duplicates and sort it
    
    for(int i=0;i<n;++i)
    {
        cin>>x;
        se1.insert(x);
    }
    
    vector<int> arr1;
    
    for(auto i=se1.begin();i!=se1.end();++i)
    {
        arr1.push_back(*i);
    }
    
    int tar;
    cin>>tar;
    
    vector<int> temp;
    vector<vector<int> > ans;
    
    combi(temp,0,arr1,0,tar,ans);
    
    for(int i=0;i<ans.size();++i)
    {
    	cout<<"(";
    	for(int j=0;j<ans[i].size();++j)
    	{
    		if(j != ans[i].size()-1)
    		cout<<ans[i][j]<<" ";
    		else
    		cout<<ans[i][j];
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
