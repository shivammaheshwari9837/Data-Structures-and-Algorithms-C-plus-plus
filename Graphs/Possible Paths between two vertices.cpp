/*

Ques:- Count the total number of ways or paths that exist between two vertices in a directed graph. These paths doesn’t contain a cycle.

Concept:- 1)Since we have to find the number of paths,we can use Backtracking within the dfs
          2)Whenever destination found or a node is visited completely(means all child are traversed),we make that node to be false again in visit array
          
Time - O(n^2)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long


void dfs(int vertex,int des,vector<int> gra[],int &coun,bool visit[])
{
	if(vertex == des) //if destination found
	{
		++coun;
		visit[des] = false;
		return;
	}
	
	visit[vertex] = true;
	
	for(int i=0;i<gra[vertex].size();++i)
	{
		int child = gra[vertex][i];
		
		if(visit[child] != true)
		dfs(child,des,gra,coun,visit);
	}
	
	visit[vertex] = false; //backtracing occurs here
}

void work()
{
    int n,m;
    cin>>n>>m;
    
    vector<int> gra[n+1];
    int poss = 0;
    bool visit[n+1] = {false};
    
    int u,v;
    for(int i=0;i<m;++i)
    {
        cin>>u>>v;
        gra[u].push_back(v);
    }
    
    int sou,des;
    cin>>sou>>des;
    
    dfs(sou,des,gra,poss,visit);
    cout<<poss;
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
