/*

Ques:- There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection 
between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

Concept:- 1)It is similar to finding the bridges of a undirected graph....

Time - O(E + V) ie. O(n)
Space - O(V)

*/

    vector < vector <int> > adj, bridges;
    vector <bool> visited; 
    
    vector <int> disc, low;
    
    void dfs(int u, int parent) //program to finding the bridges in a graph...
    {
        static int tim = 1;
        disc[u] = low[u] = tim++;
        int child = 0;
        visited[u] = true;
        
        for(auto ele: adj[u])
        {
            if(!visited[ele])
            {
                child++;
                dfs(ele, u);
                low[u] = min(low[u], low[ele]);
                if(low[ele] > disc[u])
                {
                    vector <int> temp;
                    temp.push_back(u);
                    temp.push_back(ele);
                    bridges.push_back(temp);
                }
            }
            else if (ele != parent)
            {
                low[u] = min(low[u], disc[ele]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        adj.resize(n);
        
        for(int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
                
        visited.resize(n, false);
        disc.resize(n, INF);
        low.resize(n, INF);
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
                dfs(i, -1);
        }
                
        return bridges;
        
    }
