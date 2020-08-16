/*

Ques:- Given a weighted, undirected and connected graph. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

Concept:- 1)Sort the graph edges with respect to their weights.
          2)Start adding edges to the MST from the edge with the smallest weight until the edge of the largest weight.
          3)Only add edges which doesn't form a cycle , edges which connect only disconnected components.
          4)Here we will use DSU(Disjoint Set Union) path compression technique to even reduce more time
          
 Time - O(V * logV)

*/


int find(int n,int parent[])  //DSU path compression technique  
{ 
    while(n != parent[n])
    {
        parent[n] = parent[parent[n]];
        n = parent[n];
    }
    return n;
}

void uni(int a,int b,int parent[]) //DSU union 
{
    int x = find(a,parent);
    int y = find(b,parent);
    
    parent[y] = x;
}

int kruskals(vector<pair<int,pair<int,int> >> &p1,int V)
{
    sort(p1.begin(),p1.end()); //sorting the edges according to the weight
    
    int cost = 0;
    
    int parent[V];
    
    for(int i=0;i<V;++i) //making singleton set in DSU
    parent[i] = i;
    
    for(int i=0;i<p1.size();++i)
    {
        int node1 = p1[i].second.first; //picking edge according to the minimum weight
        int node2 = p1[i].second.second;
        
        int wt = p1[i].first;
        
        if(find(node1,parent) != find(node2,parent)) //is cyclye not found we can add that edge in our MST
        {
            cost+=wt;
            uni(node1,node2,parent); //than union them to make spannin tree
        }
    }
    return cost;
}


// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // code here
    
    vector<pair<int,pair<int,int> >>p1;
    
    for(int i=0;i<V;++i)
    {
        for(int j=0;j<V;++j)
        {
            if(graph[i][j] != INT_MAX && (i<j)) //(i<j) to avoid duplicacy
            p1.push_back({graph[i][j],{i,j}});
        }
    }
    
    int ans = kruskals(p1,V);
    return ans;
}
