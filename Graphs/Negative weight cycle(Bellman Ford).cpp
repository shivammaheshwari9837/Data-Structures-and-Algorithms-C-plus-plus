/*

Ques:- Given a graph, the task is to check if it contains a negative weight cycle or not.

Concept:- 1)For this we will use the Bellman Ford algo
          2)Bellman Ford say that:-
                                   a)we run a loop for n-1 times(where n = no. of nodes),as we have to find shortest path that does not contains cycle, that's why till n-1
                                   b)Check for each edge, ie. for node x,y........distance[x] + wt < distance[y],and if true, relax it
          3)For checking negative weight cycle,check if there still exits , distance[x] + wt < distance[y]

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void work()
{
    int V,E;
    cin>>V>>E;
    
    vector<int> gra[E];
    
    int from,to,wt;
    
    for(int i=0;i<E;++i)
    {
        cin>>from>>to>>wt;
        gra[i].push_back(from);
        gra[i].push_back(to);
        gra[i].push_back(wt);
    }
    
    int dis[V] = {INT_MAX};
    dis[0] = 0; //node 1 as a source node
    
    for(int i=0;i<V-1;++i)
    {
        for(int j=0;j<E;++j)
        {
            if(dis[gra[j][0]] + gra[j][2]< dis[gra[j][1]]) //relaxing the node
            dis[gra[j][1]]  = dis[gra[j][0]] + gra[j][2];
        }
    }
    
    for(int i=0;i<E;++i)
    {
        if(dis[gra[i][0]] + gra[i][2] < dis[gra[i][1]]) //checking the -ve weight cycle
        {
            cout<<1;
            return;
        }
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
