/*

Ques:- The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. The Graph is represented as Adjancency Matrix, 
and the Matrix denotes the weight of the edegs (if it exists) else INF (1e7).

Concept:-1.)We initialize the solution matrix same as the input graph matrix as a first step. Then we update the solution matrix by considering all vertices as an intermediate 
         vertex.
         2)The idea is to one by one pick all vertices and updates all shortest paths which include the picked vertex as an intermediate vertex in the shortest path. 
         When we pick vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices.
         3) For every pair (i, j) of the source and destination vertices respectively, there are two possible cases.
                      a) k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is.
                      b) k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as 
                      dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]
                      
 Time = O(V^3)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void work()
{
    int V;
    cin>>V;
    
    int floyd[V+1][V+1];
    
    for(int i=1;i<=V;++i)
    {
        for(int j=1;j<=V;++j)
        cin>>floyd[i][j];
    }
    
    for(int k=1;k<=V;++k) //finding the minimum distance with first k nodes
    {
        for(int i=1;i<=V;++i)
        {
            for(int j=1;j<=V;++j)
            {
                floyd[i][j] = min(floyd[i][j],floyd[i][k] + floyd[k][j]); //if path can be reduced by introducing the kth node
            }
        }
    }
    
    for(int i=1;i<=V;++i)
    {
        for(int j=1;j<=V;++j)
        {
            if(floyd[i][j] != 1e7)
            cout<<floyd[i][j]<<" ";
            else
            cout<<"INF"<<" ";
        }
        cout<<"\n";
    }
}

int main()
 {
	ll test;
	cin>>test;
	for(int i=0;i<test;++i)
	{
	    work();
	}
	return 0;
}
