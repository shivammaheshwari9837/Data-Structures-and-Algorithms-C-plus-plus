/*

Ques:-Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (n-1, n-1). Find all possible paths that the rat can take to reach 
from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is 
blocked and cannot be crossed while value 1 at a cell in the matrix represents that it can be travelled through.

Concept:-1) we will recur in all four possible directions in a maze
         2) if some invalid path found, do remember all cells to make them valid, so they can be used to visit some other path
         
Time - O((N*N)^4)

*/

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5

bool isValid(int x,int y,int n,int mat[MAX][MAX],bool visit[][MAX])
{
    if(x<0 || x>=n || y<0 || y>=n || mat[x][y] == 0 || visit[x][y])
    return false;
    
    return true;
}

void ratMaze(int mat[MAX][MAX],int n,int x,int y,vector<string> &ans,string temp,bool visit[][MAX])
{
    
    if(x == n-1 && y == n-1) //base
    {
        ans.push_back(temp);
        return;
    }
    
    visit[x][y] = true; //make it invalid
    
    //up
    if(isValid(x-1,y,n,mat,visit))
    {
        ratMaze(mat,n,x-1,y,ans,temp+"U",visit);
    }
    
    //bottom
    if(isValid(x+1,y,n,mat,visit))
    {
        ratMaze(mat,n,x+1,y,ans,temp+"D",visit);
    }
    
    //left
    if(isValid(x,y-1,n,mat,visit))
    {
        ratMaze(mat,n,x,y-1,ans,temp+"L",visit);
    }
    
    //right
    if(isValid(x,y+1,n,mat,visit))
    {
        ratMaze(mat,n,x,y+1,ans,temp+"R",visit);
    }
    
    visit[x][y] = false; //make it valid for some other paths too, ie. backtracking
    
    return;
}

vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    vector<string> ans;
    string temp;
    
    bool visit[MAX][MAX]; //bool matrix to identify if current path has visited that particular cell or not
    
    for(int i=0;i<MAX;++i)
    for(int j=0;j<MAX;++j)
    visit[i][j] = false;
    
    if(m[0][0] != 0) //not possible to go on
    ratMaze(m,n,0,0,ans,temp,visit);
    
    sort(ans.begin(),ans.end());
    
    return ans;
}
