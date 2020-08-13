/*

Ques:- Given a Undirected Graph. Check whether it contains a cycle or not. 

Concept:- 1.)Here concept of back edge plays a role
          2.)While traversing the DFS of graph, check the condition that if a child is already visited, it is a parent of child or not
          
Time - O(E+V), where E = no of edges
               V = no. of vertices

*/

bool dfs(int vertex,int par,vector<int> gra[],bool visit[])
{
    visit[vertex] = true;
    
    for(int i=0;i<gra[vertex].size();++i)
    {
        int child = gra[vertex][i];
        
        if(visit[child] != true)
        {
            bool p = dfs(child,vertex,gra,visit);
            if(p == false)
            return false;
        }
        else if(child != par) // if child is already visited, checks whethet it is a parent or not
        return false;
    }
    
    return true;
}

bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   
   bool visit[V+1] = {false};
   
   for(int i=0;i<V;++i) //Since disconneted component too
   {
       if(visit[i] != true)
       {
           bool temp = dfs(i,-1,g,visit);
           if(temp == false)
           return true;
       }
   }
   
   return false;
   
}
