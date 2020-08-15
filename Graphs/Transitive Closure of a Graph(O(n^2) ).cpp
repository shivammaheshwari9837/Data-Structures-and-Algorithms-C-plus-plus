/*

Ques:- Given a directed graph, find out if a vertex j is reachable from another vertex i for all vertex pairs (i, j) in the given graph. Here reachable mean that there is a 
path from vertex i to j. The reach-ability matrix is called transitive closure of a graph.

Time - O(n^2)

*/

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define rep(i,n) for(int i = 0;i<n;i++)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define pii pair<int,int>
using namespace std;

///it just means is there any posiblity to reach the vertex j from i -->make 1 in the matrix
///TC --> O(n*n) - DfS in loop
void dfs(int s,int d,vector<int>adj[],int a[][101])
{
    a[s][d] = 1;
    for(auto x : adj[d]) ///go through the d
    {
        if(a[s][x] == false)
            dfs(s,x,adj,a);
    }
}
void singh()
{
    int n;
    cin>>n; ///vertices
    vector<int>adj[n];
   for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++)
       {
          int x;
          cin>>x;
          if(x == 1)
            adj[i].push_back(j);
       }

    int a[101][101] = {{0}};
    for(int i = 0;i<n;i++)
        dfs(i,i,adj,a);
        
    rep(i,n)
    {
        rep(j,n)
        cout<<a[i][j]<<" ";
    }

}

int32_t main()
{
    fast;
    int t = 1;
    cin>>t;
    while(t--)
    {
       singh();
       cout<<"\n";
    }
}


