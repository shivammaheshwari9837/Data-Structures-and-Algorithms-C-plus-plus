/*

Ques:- Implement Topological Sort on given Directed Acyclic Graph

Concept:- 1.)uses BFS traversal
          2.)We try to push the vertex of graph in a queue with indgree 0
          
Time - O(V+E)
Space - O(V)

*/

/*  Function which sorts the graph vertices in topological form
*   V: number of vertices
*   adj[]: input graph
*/
vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    int inDegree[V] = {0};
    
    for(int i=0;i<V;++i)
    {
        for(int j=0;j<adj[i].size();++j)
        {
            int child = adj[i][j];
            ++inDegree[child];  //finding the indgrees
        }
    }
    
    queue<int> q1;
    
    for(int i=0;i<V;++i)
    {
        if(inDegree[i] == 0) //initially pushing all vertices having indgree 0
        q1.push(i);
    }
    
    vector<int> ans;
    
    while(!q1.empty())
    {
        int vertex = q1.front();
        q1.pop();
        ans.push_back(vertex);
        
        for(int j=0;j<adj[vertex].size();++j)
        {
            int child = adj[vertex][j];
            --inDegree[child];  //removing the edges 
            
            if(inDegree[child] == 0) //if indegree 0
            q1.push(child);
        }
    }
    
    return ans;
}

