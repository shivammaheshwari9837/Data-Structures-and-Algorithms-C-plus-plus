/*

Ques:- Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.

Concept:- 1)Perform DFS traversal of the given graph. While doing traversal keep track of last finished vertex ‘v’.
          2)If there exist mother vertex, then v must be one. Check if v is a mother vertex by performing DFS/BFS from v.
          
Time - O(V+E)

*/

void dfs(int vertex,vector<int> gra[],bool visit[]) //basic dfs
 {
     visit[vertex] = true;
     
     for(int i=0;i<gra[vertex].size();++i)
     {
         int child = gra[vertex][i];
         if(visit[child] != true)
         dfs(child,gra,visit);
     }
 }

int findMother(int V, vector<int> g[]) 
{ 
    // Your code here
    bool visit[V] = {false};
    int mother;
    
    for(int i=0;i<V;++i)
    {
        if(visit[i] != true)
        {
            dfs(i,g,visit);
            mother = i; //last visited vertex may be a mother vertex
        }
    }
    
    for(int i=0;i<V;++i)
    visit[i] = false;
    
    dfs(mother,g,visit); //checking that is it really a mother vertex or not
    
    for(int i=0;i<V;++i)
    {
        if(visit[i] == false)
        return -1;
    }
    
    return mother;
} 
