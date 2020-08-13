/*

Ques:- To check whether the given graph is bipartite or not

Concept:-1.)We will use the concept of 2-way coloring , where we try to color two adjacent vertices with different color too

Time - O(n), where n is the number of edges 

*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define loop(i,n) for(i=1;i<=n;++i)
#define lop(i,n) for(i=0;i<n;++i)
#define pb(i) push_back(i)
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define mod 1000000007

const int siz=2005;
vector<int> gra[siz];
bool visit[siz];

//Checking bipartite....
bool dfs(int vertex,int color,vector<int> &col)
{
    visit[vertex]=true;
    col[vertex]=color; //putting current vertex with current color

    for(int i=0;i<gra[vertex].size();++i)
    {
        if(visit[gra[vertex][i]]!=true) //if not visited 
        {
            if(dfs(gra[vertex][i], color ^ 1,col) == false)
                return false;
        }
        else if(col[vertex] == col[gra[vertex][i]]) //if visited,check the color with parent vertex
            return false;
    }
    return true;
}


void work(int test)
{
    int n,m;
    cin>>n>>m;
    int i,x,y;

    loop(i,n) visit[i]=false , gra[i].clear();

    vector<int> col(n+1);
    loop(i,m)
    {
        cin>>x>>y;
        gra[x].pb(y);
        gra[y].pb(x);
    }
    bool ans;
    loop(i,n) //Since graph can contain disconnected component too
    {
       if(visit[i]!=true)
       {
           ans=false;
           ans=dfs(i,0,col);
       }
       if(ans==false)
        {
            break;
        }
    }
    if(ans==0)
        cout<<"Not Bipartite";
    else
        cout<<"Bipartite";

}

int main()
 {
    int test;
    //work();
   cin>>test;
   for(int i=0;i<test;++i)
   {
       work(i+1);
      cout<<"\n";
   }
    return 0;
}
