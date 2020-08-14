/*

Ques:- Given a Directed Graph. Check whether it contains any cycle or not.

Concept:- 1. when the graph is disconnected. You have to check with a loop, what are unvisited nodes
          2. When there are more than one orphan nodes (with zero parents) pointing to a single node in a particular subgraph. For that we need to maintain a stack which 
          keeps track of the nodes visited in each subgraph starting from each orphan nodes.
          Assume the example, 2->11 9->11
          3. When starting from each orphan node, when there is no cycle detected, this means that pointing back to this node again starting from some other orphan node  
          will not be a cycle.
          Assume the example, 35->19, 35->59, 59->19
          4.Thus DFS will work here

*/


bool dfs(int vertex,vector<int> gra[],bool visit[],bool inCall[])
{
    visit[vertex] = true;
    inCall[vertex] = true;
    
    for(int i=0;i<gra[vertex].size();++i)
    {
        int child = gra[vertex][i];
        
        if(visit[child] != true)
        {
            bool temp = dfs(child,gra,visit,inCall);
            
            if(temp)
            return true;
        }
        else if(inCall[child]) //if a child is already visited and child is of same call stack, than cycle present
        return true;
    }
    
    inCall[vertex] = false; //if no cycle, remember to do all vertex false
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    
    bool visit[V+1] = {false},inCall[V+1] = {false}; //inCall array keep the track whether the calls are of current call stack or not
    
    for(int i=0;i<V;++i)
    {
        if(visit[i] != true)
        {
            bool temp = dfs(i,adj,visit,inCall);
            
            if(temp)
            return true;
        }
    }
    
    return false;
    
}

/*

Method 2:- Using the topological sort

Concept:- 1.)Just check that while building the topological array(ie. answer array), is its size equal to no. of vertices or not

*/


bool topSort(vector<int> adj[],int V,int inDegree[])
{
    queue<int> q1;
    
    for(int i=0;i<V;++i)
    {
        if(inDegree[i] == 0)
        q1.push(i);
    }
    
    vector<int> ans;
    
    while(!q1.empty())
    {
        int vertex = q1.front();
        q1.pop();
        ans.push_back(vertex);
        
        for(int i=0;i<adj[vertex].size();++i)
        {
            int child = adj[vertex][i];
            --inDegree[child];
            
            if(inDegree[child] == 0)
            q1.push(child);
        }
    }
    
    return (ans.size() != V);
}

bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    int inDegree[V] = {0};
    
    for(int i=0;i<V;++i)
    {
        for(int j=0;j<adj[i].size();++j)
        {
            ++inDegree[adj[i][j]];
        }
    }
    
    return topSort(adj,V,inDegree);
}

*/
