/*

Ques:- Eulerian Path is a path in graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex. 
The task is to find that there exists the Euler Path or circuit or none in given undirected graph.

Concept:- Eulerian Cycle
          An undirected graph has Eulerian cycle if following two conditions are true.
          ….a) All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path 
          (we only consider all edges).
          ….b) All vertices have even degree.

          Eulerian Path
          An undirected graph has Eulerian Path if following two conditions are true.
          ….a) Same as condition (a) for Eulerian Cycle
          ….b) If zero or two vertices have odd degree and all other vertices have even degree. Note that only one vertex with odd degree is not possible in an 
          undirected graph (sum of all degrees is always even in an undirected graph)
          
 Time - O(1) 

*/

//V = no.of vertices
//adj  = adjacency List

int Graph::isEulerian()
{
//add code here.
    int odd = 0,even = 0;
    for(int i=0;i<V;++i)
    {
        if(adj[i].size() % 2 == 0)
        ++even;
        else
        ++odd;
    }
    
    if(even == V)
    return 2;
    else if(odd == 2)
    return 1;
    else
    return 0;
}
