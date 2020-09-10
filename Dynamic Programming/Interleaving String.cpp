/*

Ques :- https://leetcode.com/problems/interleaving-string/    

Concept:- 1)Here we have choices in recurion like - 1)if C[Cindex] == A[Aindex],and C[Cindex] != B[Bindex]
                                                    2)if C[Cindex] == B[Bindex],and C[Cindex] != A[Aindex]
                                                    3)if C[Cindex] == A[Aindex],and C[Cindex] == B[Bindex],recur in both the directions too
                                                    4)else false
                                                    
Time - O(A*B*C), where A = length of A
                       B = length of B
                       C = length of C

*/

int dp[105][105][205];

bool inter(string &A,int Aindex,string &B,int Bindex,string &C,int Cindex)
{
    //base....
    if(Cindex == C.size()) //if C if finishes
    {
        if(Aindex == A.size() && Bindex == B.size()) // if A and B are also empty, than true
        return dp[Aindex][Bindex][Cindex] = true;
        else 
        return dp[Aindex][Bindex][Cindex] = false;
    }
    else if(A.size() == Aindex) //if A finishes and C is left, than check only C with B
    {
        while(C.size()!=Cindex && B.size()!=Bindex)
        {
            if(C[Cindex] != B[Bindex])
            return dp[Aindex][Bindex][Cindex] = false;
            ++Cindex;
            ++Bindex;
        }
        if(C.size() == Cindex && B.size() == Bindex) //if C and B both finishes, than true
        return dp[Aindex][Bindex][Cindex] = true;
        else
        return dp[Aindex][Bindex][Cindex] = false;
    }
    else if(B.size() == Bindex) //same as above with B finishes
    {
        while(C.size()!=Cindex && A.size()!=Aindex)
        {
            if(C[Cindex] != A[Aindex])
            return dp[Aindex][Bindex][Cindex] = false;
            ++Cindex;
            ++Aindex;
        }
        if(C.size() == Cindex && A.size() == Aindex)
        return dp[Aindex][Bindex][Cindex] = true;
        else
        return dp[Aindex][Bindex][Cindex] = false;
    }
    
    if(dp[Aindex][Bindex][Cindex] != -1)
    return dp[Aindex][Bindex][Cindex];
    
    
    if(C[Cindex] == A[Aindex] && C[Cindex] != B[Bindex])
    return dp[Aindex][Bindex][Cindex] = inter(A,Aindex+1,B,Bindex,C,Cindex+1);
    else if(C[Cindex] == B[Bindex] && C[Cindex] != A[Aindex])
    return dp[Aindex][Bindex][Cindex] = inter(A,Aindex,B,Bindex+1,C,Cindex+1);
    else if(C[Cindex] == B[Bindex] && C[Cindex] == A[Aindex])
    {
        return (dp[Aindex][Bindex][Cindex] = (inter(A,Aindex+1,B,Bindex,C,Cindex+1) || inter(A,Aindex,B,Bindex+1,C,Cindex+1)));
    }
    else
    return dp[Aindex][Bindex][Cindex] = false;
}

bool isInterleave(string A, string B, string C) 
{
    //Your code here
    
    for(int i=0;i<=A.size();++i)
    for(int j=0;j<=B.size();++j)
    for(int k=0;k<=C.size();++k)
    dp[i][j][k] = -1;
    
    bool ans = inter(A,0,B,0,C,0);
    return ans;
}
