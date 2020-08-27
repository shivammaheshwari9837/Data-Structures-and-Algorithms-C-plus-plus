/*

Ques:- Given a 2D board of letters and a word. Check if the word exists in the board. The word can be constructed from letters of adjacent cells only. 
ie - horizontal or vertical neighbors. The same letter cell can not be used more than once.

Concept:- 1)Here we will use DFS + Backtracking
          2)For every i,j in given matrix,we consider it as a source of a graph.
          3)When some invalid path is been traversed,we backtrack the boolean matrix to false
          
Time - O(n*m*(4^wordLength) ),where n,m are no. of rows and columns


*/

#define MAX 12

bool isValid(int x,int y,int &n,int &m,bool visit[][MAX]) //checks the validity of choice x,y
{
    if(x<0 || x>=n || y<0 || y>=m || visit[x][y])
    return false;
    
    return true;
}

bool dfs(vector<vector<char> >& board,int index,string &str,int &n,int &m,int x,int y,bool visit[][MAX])
{
    //base...
    
    if(!isValid(x,y,n,m,visit) || board[x][y]!=str[index] )
    return false;
    
    if(index == str.size()-1) //if we reaches to last word and is same,returs true
    return true;
    
    visit[x][y] = true; //make visited
    bool a = false,b = false,c = false,d = false;
        
    //top...
    a = dfs(board,index+1,str,n,m,x-1,y,visit);
        
    //bottom...
    b = dfs(board,index+1,str,n,m,x+1,y,visit);
        
    //left...
    c = dfs(board,index+1,str,n,m,x,y-1,visit);
        
    //right...
    d = dfs(board,index+1,str,n,m,x,y+1,visit);
        
    visit[x][y] = false; //backtracking...
        
    return (a||b||c||d);
}

bool WordSearch(vector<vector<char> >& board, string word) {
    // Your code goes here
    int n = board.size(),m = board[0].size();
    
    bool visit[MAX][MAX]; //boolean matrix
    
    for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
    visit[i][j] = false;
    
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(board[i][j] == word[0] && dfs(board,0,word,n,m,i,j,visit)) //if starting is same,we processes our dfs
            return true;
        }
    }
    
    return false;
}
