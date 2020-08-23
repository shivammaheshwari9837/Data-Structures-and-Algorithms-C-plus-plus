/*

Ques:- Given a binary matrix of size N x M. The task is to find the distance of nearest 1 in the matrix for each cell. The distance is calculated 
as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest 
cell having value 1.

Concept:- 1)We will use multisource bfs for the this problem
          2)Push every cell having value as 1 in a queue
          3)Than apply bfs over the whole matrix having the value 0,and increase the distance by 1 too

Time - O(n*m)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int> 

void work()
{
    int n,m;
    cin>>n>>m;
    
    int mat[n][m];
    
    for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
    cin>>mat[i][j];
    
    queue<pair<pii,int> > q1; // { { x_cordiante,y_coordinate},distnce of the current cell from 1}
    
    for(int i=0;i<n;++i)
    {
    	for(int j=0;j<m;++j)
    	{
    		if(mat[i][j] == 1) //if value as 1
    		{
    			mat[i][j] = -1; 
    			q1.push({{i,j},0}); //push them in the queue
			}
		}
	}
	
	while(!q1.empty())
	{
		int x = q1.front().first.first;
		int y = q1.front().first.second;
		int dis = q1.front().second;
		
		q1.pop();
		
		//above....
		if(x-1>=0 && mat[x-1][y] == 0)
		{
			mat[x-1][y] = dis+1;
			q1.push({{x-1,y},dis+1});
		}
		
		//below...
		if(x+1<n && mat[x+1][y] == 0)
		{
			mat[x+1][y] = dis+1;
			q1.push({{x+1,y},dis+1});
		}
		
		//left..
		if(y-1>=0 && mat[x][y-1] == 0)
		{
			mat[x][y-1] = dis+1;
			q1.push({{x,y-1},dis+1});
		}
		
		//right...
		if(y+1<m && mat[x][y+1] == 0)
		{
			mat[x][y+1] = dis+1;
			q1.push({{x,y+1},dis+1});
		}
	}
	
	for(int i=0;i<n;++i)
	for(int j=0;j<m;++j)
	{
		if(mat[i][j] == -1)
		mat[i][j] = 0;
	}
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
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
