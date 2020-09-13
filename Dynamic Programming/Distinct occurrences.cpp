/*

Ques:- Given two strings S and T of length n and m respectively. find count of distinct occurrences of T in S as a sub-sequence. 
Concept:- 1)This is overlapping subproblems
          2)We have two types of choices:- 1)if current char of S = current char of T
                                                  a)Either invlove it in the counting
                                                  b)Take some other character in string S to compare
                                           2)if not matches
                                                  a)Take some other character in string S to compare
                                                  
                                                  
Time - O(n * m) [n = length of string S, m = length of string T)
Space - O(n * m)

*/

int dp[8005][105];
#define mod 1000000007

int distinct(int S_index,string &S,int T_index,string &T)
{
	//base...
	if(T.size() == T_index) //if T string ends, than it is possible answer
	return 1;
	else if(S_index == S.size()) //if S ends,and T does not ends,than impossible
	return 0;
	
	if(dp[S_index][T_index] != -1)
	return dp[S_index][T_index];
	
	int a = 0,b = 0;
	
	if(S[S_index] == T[T_index])
	{
		//take it...
		a = distinct(S_index+1,S,T_index+1,T)%mod;
		
		//further take it...for S string
		b = distinct(S_index+1,S,T_index,T)%mod;
	}
	else
	{
    //further take it...for S string
		b = distinct(S_index+1,S,T_index,T)%mod;
	}
	
	return dp[S_index][T_index] = (a+b)%mod;
}


int subsequenceCount(string S, string T)
{
  //Your code here
  
  for(int i=0;i<=S.size();++i)
  for(int j=0;j<=T.size();++j)
  dp[i][j] = -1;
  
  return distinct(0,S,0,T);
}
