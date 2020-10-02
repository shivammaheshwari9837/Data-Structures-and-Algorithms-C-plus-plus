/*

Ques:- Link:- https://www.spoj.com/problems/ELEVTRBL/cstart=50

Concept:- 1)Here we will simple create a graph,ie. connect the ith node to the elevator it can go, ie, the currNode + up  and currNode + down
          2)Than apply simple BFS to find the shortest path from source to destination
          
Time - O(n)
Space- O(n)

*/

#include<bits/stdc++.h>

using namespace std;


void work()
{
    int floor,src,des,up,down;
    cin>>floor>>src>>des>>up>>down;
    
    vector<int> gra[floor+1];
    
    for(int i=1;i<=floor;++i) //creation on graph
    {
    	if(i+up <= floor)
    	{
    		gra[i].push_back(i+up);
		}
		
		if(i-down >= 1)
		{
			gra[i].push_back(i-down);
		}
	}
	
	int ans = -1;
	
	bool visit[floor+1] = {false};
	
	queue<pair<int,int>> q1;
	q1.push({src,0});
	visit[src] = true;
	
	while(!q1.empty()) //simple BFS
	{
		int curr = q1.front().first;
		int lvl = q1.front().second;
		q1.pop();
		
		if(curr == des)
		{
			ans = lvl;
			break;
		}
		
		for(int i=0;i<gra[curr].size();++i)
		{
			int node = gra[curr][i];
			if(visit[node] != true)
			{
				q1.push({node,lvl+1});
				visit[node] = true;
			}
		}
	}
	
	if(ans != -1)
	cout<<ans;
	else
	cout<<"use the stairs";
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    work();
    return 0;
}
