/*

Ques:- You are given number of nodes, N, and number of edges, M, of a undirected connected graph. After adding each edge, print the size of all the connected 
components (in increasing order).

Concept:- 1.)There is always a parent array which have information about parent of a particular component

*/


#include<bits/stdc++.h>
using namespace std;

int find(int n,int parent[]) //find that an element belongs to which set(returns the parent of the set)
{
	while(1)
	{
		if(n == parent[n])
		return n;
		else
		n = parent[n];
	}
}

void uni(int a,int b,int parent[]) //union of two sets 
{
	a = find(a,parent);
	b = find(b,parent);

	if(a == b)
	return;

	parent[a] = b;
	return;
}

void call(int parent[],int n)  //according to the problem statement
{
	unordered_map<int,int> m1;

	for(int i=1;i<=n;++i)
	{
		int par = find(i,parent);
		++m1[par];
	}

	vector<int> ans;

	for(auto i=m1.begin();i!=m1.end();++i)
	{
		ans.push_back(i->second);
	}

	sort(ans.begin(),ans.end());

	for(int i=0;i<ans.size();++i)
	cout<<ans[i]<<" ";

	cout<<"\n";

}

int main()
{
	int n,m;
	cin>>n>>m;

	int parent[n+1];
	for(int i=1;i<=n;++i)
	{
		parent[i] = i;
	}

	int x,y;
	for(int i=1;i<=m;++i)
	{
		cin>>x>>y;
		uni(x,y,parent);

		call(parent,n);
	}
}
