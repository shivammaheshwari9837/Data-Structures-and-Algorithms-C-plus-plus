/*

Ques:-Given a graph with N nodes and M directed edges. Your task is to complete the function kosaraju() which returns an integer denoting the number of strongly 
connected components in the graph.

Concept:- 1.)Sort all the vertices of a graph using DFS according to their ending time(using stack)
          2.)Find the closure of the given graph
          3.)Pop the element through stack, and do dfs traversal according to that and counts the components
          
 Time - O(V+E)

*/

void dfs(int vertex,bool visit[],stack<int> &st1,vector<int> adj[])
{
    visit[vertex] = true;
    
    for(int i=0;i<adj[vertex].size();++i)
    {
        int child = adj[vertex][i];
        
        if(visit[child] != true)
        {
            dfs(child,visit,st1,adj);
        }
    }
    st1.push(vertex); //pushing the elemnts according to the ending time
}

void revDfs(int vertex,bool visit[],vector<int> adj[])
{
    visit[vertex] = true;
    
    for(int i=0;i<adj[vertex].size();++i)
    {
        int child = adj[vertex][i];
        
        if(visit[child] != true)
        revDfs(child,visit,adj);
    }
}

int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    
    bool visit[V] = {false};
    stack<int> st1;
    
    for(int i=0;i<V;++i)
    {
        if(visit[i] != true)
        {
            dfs(i,visit,st1,adj);
        }
    }
    
    vector<int> trans[V];
    
    for(int i=0;i<V;++i)
    {
        for(int j=0;j<adj[i].size();++j)
        {
            int child = adj[i][j];
            trans[child].push_back(i); //transposing the graph(ie. just revresing the edges)
        }
    }
    
    int coun = 0;
    for(int i=0;i<V;++i)
    visit[i] = false;
    
    while(!st1.empty()) 
    {
        int node = st1.top(); //taking out the element from stack
        st1.pop();
        
        if(visit[node] != true)
        {
            ++coun;
            revDfs(node,visit,trans);
        }
    }
    
    return coun;
}

/*

Ques 2:- Check whether a graph is strongly Connected or not 
Concept:- 1)If the above algorithm returns 1, than true else false

*/
