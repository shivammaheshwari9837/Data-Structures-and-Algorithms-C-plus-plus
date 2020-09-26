/*

Ques:- A message containing letters from A-Z is being encoded to numbers using the following mapping:

      'A' -> 1
      'B' -> 2
      ...
      'Z' -> 26
      Given a non-empty string containing only digits, determine the total number of ways to decode it.
      
Concept:- 1)Here we have two kind of choices:- 1)either just take single digit(but should not be zero)
                                               2)either take two digits(but lie in the range of 1.....26)
          2)thus recurion can be written too and apply DP
          
Time - O(n)
Space - O(n)

*/

class Solution {
public:
    
    int ways(string &str,int index,int dp[])
    {
        //base....
        if(index == str.size()) //if reaches to end of string
            return 1;
        
        int a = 0,b = 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        //single digit...
        int val = str[index]-'0'; //check the first digit is 0 or not(is helpful in both 1-digit(ex:- 0) and 2-digit(ex:- 05) )
        
        if(val != 0)
        {
            //single digit...
            a = ways(str,index+1,dp); //single digit
        
            //2-digit....
            if(index+2 <=str.size()) //avoid out of bound 
            {
                string temp = str.substr(index,2);
                int val = stoi(temp);
                if(val>=1 && val<=26)
                    b = ways(str,index+2,dp);
            }
        }
        

        
        return dp[index] = a+b;
        
    }
    
    int numDecodings(string s) {
        
        int n = s.size();
        int dp[n+1];
        
        memset(dp,-1,sizeof(dp));
        
        int ans = ways(s,0,dp);
        
        return ans;
    }
};
