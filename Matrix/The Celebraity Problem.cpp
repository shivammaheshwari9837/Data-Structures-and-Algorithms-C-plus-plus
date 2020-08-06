/*

Ques :- The Celebraity Problem(GFG)

Method 1:- Using indgree and outdegree of a graph(T = O(n^2) ,S=O(n^2) )

*/

int getId(int M[MAX][MAX], int n)
{
    //Your code here
    vector<int> gra[n];
    
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(M[i][j] == 1)
            gra[i].push_back(j);
        }
    }
    
    vector<int> indegree(n),outdegree(n);
    
    for(int i=0;i<n;++i)
    {
        outdegree[i] = gra[i].size();
        for(int j=0;j<gra[i].size();++j)
        {
            ++indegree[gra[i][j]];
        }
    }
    
    for(int i=0;i<n;++i)
    {
        if(outdegree[i] == 0 && indegree[i] == n-1)
        return i;
    }
    
    return -1;
}

/*

Method 2:- Using Time-O(n^2), Space - O(N)

*/

Code Snippet:- int getId(int M[MAX][MAX], int n)
{
    //Your code here
    vector<int> candidates;
    bool check;
    
    for(int i=0;i<n;++i)
    {
        check=false;
        for(int j=0;j<n;++j)
        {
            if(M[i][j] == 1)
            {
                check=true;
                break;
            }
        }
        if(!check)
        candidates.push_back(i);
    }
    
    int coun=0;
    
    for(int i=0;i<candidates.size();++i)
    {
        coun=0;
        for(int j=0;j<n;++j)
        {
            if(M[j][candidates[i]] == 1)
            ++coun;
        }
        if(coun == n-1)
        return candidates[i];
    }
    
    return -1;
}

/*

Method 3:- Time - O(N) ,Space-O(1)

Concept:- 1.make two pointers , one at 0 and other at n-1
	2. if(Person X knows Y)
		X cant be a celebrity
	else if(Person X does not Y)
		Y cant be a celebrity

*/

int getId(int M[MAX][MAX], int n)
{
    //Your code here
    
    //Two pointer.........
    int start = 0,end = n-1;
    
    while(start<end)
    {
        if(M[start][end])
        ++start;
        else
        --end;
    }
    
    //Checking the candidate...
    int coun1=0,coun2=0;
    for(int i=0;i<n;++i)
    {
        if(M[i][start])
        ++coun1;
        
        if(M[start][i])
        ++coun2;
    }
    
    if(coun1 == n-1 && coun2 == 0)
    return start;
    else
    return -1;
}
