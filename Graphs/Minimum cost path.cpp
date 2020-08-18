/*

Ques:- Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from 
top left cell to bottom right cell by which total cost incurred is minimum. You can move in 4 directions : up, down, left an right.

Concept:- 1.)Here we will use Dijkstra Shortest Path Algorithm
          2)Consider each cell in a matrix as a node of a graph and apply Dijskatra(we use priority queue implementation)
          
Time - O(n*n +  e*loge) , where n = size of matrix
                          e = 4*(n*n), as in 4 directions we can move...

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,pair<int,int> > 

bool isValid(int x,int y,int n) // is coordinates are valid 
{
	if(x<0 || x>=n || y<0 || y>=n)
	return false;
	
	return true;
}

void work()
{
	int n;
    cin>>n;
    
    int mat[n][n];
    int dis[n][n]; //distance matrix
    bool visit[n][n]; //visited matrix
    
    for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
    {
    	cin>>mat[i][j];
    	dis[i][j] = INT_MAX;
    	visit[i][j] = false;
	}
    
    dis[0][0] = mat[0][0]; //initializing source with mat[0][0]
    
    priority_queue<pii,vector<pii>,greater<pii> >min_heap;
    
    min_heap.push({0,{0,0}}); //{ distance, {x_coordinate,y_coordinate} }
    
    while(!min_heap.empty()) // the rest is similar to Dijkstra
    {
    	pii temp = min_heap.top();
    	min_heap.pop();
    	
    	int x = temp.second.first;
    	int y = temp.second.second;
    	
    	if(visit[x][y]) continue;
    	visit[x][y] = true;
    	
    	//top....
    	if(isValid(x-1,y,n))
    	{
    		int wt = mat[x-1][y];
    		if(dis[x][y] + wt < dis[x-1][y])
    		{
    			dis[x-1][y] = dis[x][y] + wt;
    			min_heap.push({dis[x-1][y] , {x-1,y}});
			}
		}
		
		//bottom...
		if(isValid(x+1,y,n))
		{
			int wt = mat[x+1][y];
    		if(dis[x][y] + wt < dis[x+1][y])
    		{
    			dis[x+1][y] = dis[x][y] + wt;
    			min_heap.push({dis[x+1][y] , {x+1,y}});
			}
		}
		
		//left....
		if(isValid(x,y-1,n))
		{
			int wt = mat[x][y-1];
    		if(dis[x][y] + wt < dis[x][y-1])
    		{
    			dis[x][y-1] = dis[x][y] + wt;
    			min_heap.push({dis[x][y-1] , {x,y-1}});
			}
		}
		
		//right....
		if(isValid(x,y+1,n))
		{
			int wt = mat[x][y+1];
    		if(dis[x][y] + wt < dis[x][y+1])
    		{
    			dis[x][y+1] = dis[x][y] + wt;
    			min_heap.push({dis[x][y+1] , {x,y+1}});
			}
		}
	}
	
	cout<<dis[n-1][n-1]; //destination distance
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
