/*

Ques:- A Hamiltonian path, is a path in an undirected or directed graph that visits each vertex exactly once. Given an undirected graph  the task is to check if a 
Hamiltonian path is present in it or not.

Method 1:- a)Make a boolean matrix between all possible edges given
           b)Than check all permutations of from 1 to n, and find valid one

Time - O(!n)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool gra[15][15];

bool check(int n)
{
    vector<int> temp;
    
    for(int i=1;i<=n;++i)
    temp.push_back(i);
    
    do
    {
        bool valid = true;
        for(int i=0;i<temp.size()-1;++i)
        {
            if(gra[temp[i]][temp[i+1]] != true)
            {
                valid = false;
                break;
            }
        }
        if(valid)
        {
          return true;
		    }
    }while(next_permutation(temp.begin(),temp.end())); //finding the all permutations and check each of them
    
    return false;
}

void work()
{
    int n,m,x,y;
    cin>>n>>m;
    
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
    gra[i][j] = false;
    
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        gra[x][y] = true;
        gra[y][x] = true;
    }
    
    bool ans = check(n);
    
    if(ans)
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

/*

Method 2:- Using the DFS method
	    1)apply depth first search starting from every vertex v and do labeling of all the vertices.
	    2)All the vertices are labelled as either "IN STACK" or "NOT IN STACK". A vertex is labelled "IN STACK" if it is visited but some of its adjacent vertices 
	    are not yet visited and is labelled "NOT IN STACK" if it is not visited.
	    3)If at any instant the number of vertices with label "IN STACK" is equal to the total number of vertices in the graph then a Hamiltonian Path exists 
	    in the grap

Time - Worst case is O(!n)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool dfs(int vertex,bool inStack[],int n,vector<int> gra[],int coun)
{
    if(coun == n) //if total nodes in path equal to n,than path exists
    return true;
    
    for(int i=0;i<gra[vertex].size();++i) 
    {
        int child = gra[vertex][i];
        
        if(inStack[child] != true) //if not in path and is a connected node with current vertex
        {
            inStack[child] = true; //make it in the path
            
            if(dfs(child,inStack,n,gra,coun+1))
            return true;
            
            inStack[child] = false; //remove it from the path,so next path can utilize it ,while backtracking
        }
    }
    
    return false;
}

void work()
{
    int n,m,x,y;
    cin>>n>>m;
    
    vector<int> gra[n+1];
    
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        gra[x].push_back(y);
        gra[y].push_back(x);
    }
    
    bool inStack[n+1] = {false};
    bool ans = true;
    
    for(int i=1;i<=n;++i)
    {
        inStack[i] = true; // push the node to the path
        ans = dfs(i,inStack,n,gra,1);
        if(ans)
        {
            cout<<1;
            return;
        }
        inStack[i] = false;
    }
    
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
