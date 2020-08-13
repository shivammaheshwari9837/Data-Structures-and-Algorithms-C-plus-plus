/*

Ques:- Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

So, we have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j],
[i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to rot every orange then simply return -1.

Concept:-1)Since we have to find the minimum value, than here BFS works fine instead of DFS
         2)We push all the 2's value i,j from the given matrix, as oranges have to be rott simultaneously in a queue
         3)Than pick out that time at which the last orange is to be rotten

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int siz = 105;
int mat[siz][siz];
bool visit[siz][siz];
int row,col;

bool isValid(int x,int y)  //checking the valid index ie. x and y coordinates
{
    if(x<0 || x>=row || y<0 | y>=col)
    return false;
    
    return true;
}

void bfs()
{
    queue<pair<int,pair<int,int> > >q1; //{time for rotting the current orange, {coordinate x,coordinate y} }
    
    for(int i=0;i<row;++i) 
    {
        for(int j=0;j<col;++j)
        {
            if(mat[i][j] == 2) //putting all 2's in a queue
            {
                q1.push({0,{i,j}});
                visit[i][j] = true;
            }
        }
    }
    
    int tAns = 0;
    
    while(!q1.empty())
    {
        pair<int,pair<int,int> > tar = q1.front();
        q1.pop();
        
        int timer = tar.first;
        int x = tar.second.first;
        int y = tar.second.second;
        
        tAns = max(timer,tAns);
        
        if(isValid(x-1,y) && visit[x-1][y]!=true && mat[x-1][y] == 1)
        {
            q1.push({timer+1,{x-1,y}});
            visit[x-1][y] = true;
            mat[x-1][y] = 2;
        }
        
        if(isValid(x+1,y) && visit[x+1][y]!=true && mat[x+1][y] == 1)
        {
            q1.push({timer+1,{x+1,y}});
            visit[x+1][y] = true;
            mat[x+1][y] = 2;
        }
        
        if(isValid(x,y+1) && visit[x][y+1]!=true && mat[x][y+1] == 1)
        {
            q1.push({timer+1,{x,y+1}});
            visit[x][y+1] = true;
            mat[x][y+1] = 2;
        }
        
        if(isValid(x,y-1) && visit[x][y-1]!=true && mat[x][y-1] == 1)
        {
            q1.push({timer+1,{x,y-1}});
            visit[x][y-1] = true;
            mat[x][y-1] = 2;
        }
    }
    
    bool isLeft = false;
    
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
        {
            if(mat[i][j] == 1) //if any orange is not rotten
            isLeft = true;
        }
    }
    
    if(isLeft)
    cout<<-1;
    else
    cout<<tAns;
}

void work()
{
    cin>>row>>col;
    
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
        {
            cin>>mat[i][j];
            visit[i][j] = false;
        }
    }
    
    bfs();
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
