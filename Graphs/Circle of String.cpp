/*

Ques:- Given an array of strings A[], determine if the strings can be chained together to form a circle. A
string X can be chained together with another string Y if the last character of X is same as first
character of Y. If every string of the array can be chained, it will form a circle.

For eg for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"

Concept:- 1.)The idea is to create a directed graph of all characters and then find if their is an eulerian circuit in the graph or not.  
          If there is an eulerian circuit, then chain can be formed, otherwise not.
          2)directed graph has eulerian circuit only if in degree and out degree of every vertex is same, and all non-zero degree vertices form a single strongly 
          connected component(using Kosraju's Algo)
          3)Create a directed graph g with number of vertices equal to the size of alphabet (i.e. 26 characters)

          4) Perform for every string in the given array of strings.
                    a) Add an edge from first character to last character of the given graph
          5) If the created graph has eulerian circuit, then return true, else false.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int vertex,bool visit[],vector<int> gra[],stack<int> &st1) //standard Kosaraju's Algo part2
{
	visit[vertex] = true;
	
	for(int i=0;i<gra[vertex].size();++i)
	{
		int child = gra[vertex][i];
		if(visit[child] != true)
		dfs(child,visit,gra,st1);
	}
	
	st1.push(vertex);
	
}

void revDfs(int vertex,bool visit[],vector<int> gra[])  //standard Kosaraju's Algo part3
{
	visit[vertex] = true;
	
	for(int i=0;i<gra[vertex].size();++i)
	{
		int child = gra[vertex][i];
		if(visit[child] != true)
		revDfs(child,visit,gra);
	}
}

bool kosaraju(vector<int> gra[])  //standard Kosaraju's Algo part1
{
	bool visit[26] = {false};
	stack<int> st1;
	
	for(int i=0;i<26;++i)
	{
		if(visit[i] != true && gra[i].size()>0)
		dfs(i,visit,gra,st1);
	}
	
	vector<int> trans[26];
	
	for(int i=0;i<26;++i)
	{
		for(int j=0;j<gra[i].size();++j)
		{
			int child = gra[i][j];
			trans[child].push_back(i);
		}
	}
	
	int SCC = 0;
	for(int i=0;i<26;++i)
	visit[i] = false;
	
	while(!st1.empty())
	{
		int node = st1.top();
		st1.pop();
		
		if(visit[node] != true)
		{
			++SCC;
			revDfs(node,visit,trans);
		}
	}
	
	if(SCC == 1)
	return true;
	else
	return false;
}

void work()
{
	int n;
	cin>>n;
	
	vector<string> str(n);
	
	for(int i=0;i<n;++i)
	cin>>str[i];
	
	vector<int> gra[26];
	int inDegree[26] = {0},outDegree[26] = {0};
	
	for(int i=0;i<n;++i)
	{
		string temp = str[i];
		char st = temp[0],end = temp[temp.size()-1]; //creating the graph.....
		gra[st-'a'].push_back(end-'a'); //creating the graph.....
		++outDegree[st-'a']; 
		++inDegree[end-'a'];
	}
	
	bool res1 = kosaraju(gra); //standard Kosaraju's Algo called
	bool res2 = true;
	
	for(int i=0;i<26;++i)
	{
		if(inDegree[i] != outDegree[i]) //checking the equality of indegree and outdegree algo
		res2 = false;
	}
	
	if(res1 && res2)
	cout<<1;
	else
	cout<<0;
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
