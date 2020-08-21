/*

Ques:- Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph 
are colored with the same color. Here coloring of a graph means assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

Vertex are 1-based (vertext number starts with 1, not 0).

Concept:- 1)Just few things to remember , that no two adjacent node should colored same,that's it
          2)If some recurive path fails,remember to uncolor all the nodes thtough the path,so can be utilised for further calls

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool mColor(int node,vector<int> gra[],int &m,int &n,int color[])
{
	if(node == n+1) //if all nodes are colored without fails,returns true
	return true;
	
	unordered_map<int,int> usedColor; //used so to check which colored are been fiiled to adjacent vertices
	bool ans = false;
	
	for(int i=0;i<gra[node].size();++i)
	{
		int child = gra[node][i];
		++usedColor[color[child]]; //update all adjacent vertices nodes
	}
	
	for(int i=1;i<=m;++i)
	{
		if(usedColor.find(i) == usedColor.end()) //if some color is available to fill
		{
			color[node] = i; //color it
		
			ans = ans || mColor(node+1,gra,m,n,color);
			
			color[node] = -1; //uncolor it,backtracking
	 	} 
	}
	
	return ans;
}

void work()
{
    int n,m,e;
    cin>>n>>m>>e;
    
    int x,y;
    
    vector<int> gra[n+1];
    int color[n+1] = {-1}; //initilly make all color to -1,thats color is not used
    
    for(int i=0;i<e;++i)
    {
    	cin>>x>>y;
    	gra[x].push_back(y);
    	gra[y].push_back(x);
	}
	
	bool ans = mColor(1,gra,m,n,color); //(node that is to be colored,graph,m,n,color array)
	
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
