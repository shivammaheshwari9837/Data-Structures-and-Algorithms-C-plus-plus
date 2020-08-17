/*

Ques:- Given a graph of V nodes represented in the form of the adjacency matrix. The task is to find the shortest distance of all the vertex's from the source vertex.

Concept:- 1.)we pick the edge according to the minimum distance between the two nodes and further expolre according to it
          2)For this we use min priority queue to reduce the time
          
Time Complexity:- O(E + VlogV), E = no. of edges and V = no. of vertices

*/


#define pii pair<int,int> 

vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    // Your code here
    
    vector<pii>gra[V];
    
    for(int i=0;i<V;++i)
    {
        for(int j=0;j<V;++j)
        {
            if(g[i][j] != 0)
            {
                gra[i].push_back({j,g[i][j]}); //making the list
            }
        }
    }
    
    
    vector<int> dis(V,INT_MAX);
    dis[src] = 0; //distance of source be 0
    bool visit[V] = {false};
    
    priority_queue<pii,vector<pii>,greater<pii> >min_heap; //min priority queue 
    
    min_heap.push({0,src});
    
    while(!min_heap.empty())
    {
        pii temp = min_heap.top();
        min_heap.pop();
        
        int node = temp.second;
        
        if(visit[node]) //if already visted node, than continue
        continue;
        
        visit[node] = true;
        
        for(int i=0;i<gra[node].size();++i)
        {
            int node1 = gra[node][i].first,wt = gra[node][i].second;
            
            if(dis[node] + wt < dis[node1]) //relaxation of nodes if some minimum path possible
            {
                dis[node1] = wt + dis[node];
                min_heap.push({dis[node1],node1});
            }
        }
        
    }
    
    return dis;
}
