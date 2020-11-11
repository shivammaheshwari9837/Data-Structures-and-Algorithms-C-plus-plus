/*

Ques:- Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

        Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
        Paste: You can paste the characters which are copied last time.


        Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.
        
Concept:- 1. Base case :
            If i is greater than n it means the series of steps that were performed were invalid, return infinity.
            If i is equals to n it means the series of steps that were performed were valid, return zero.
            
          2. Copy operation :
            We can't perform copy operation alone, as it doesn't change the number of 'A's currently present & hence can result in infinite recursion causing stack overflow.
            Hence we'll think of copy operation as copy + paste operation.
            Add 2 to steps. ( copy + paste )
            l will become i ( number of 'A's currently present ).
            Increment i ( number of 'A's currently present ) by l ( number of 'A's after last copy operation ).
            
          3. Paste operation :
            Add 1 to steps.
            l will be same.
            Increment i ( number of 'A's currently present ) by l ( number of 'A's after last copy operation ).
            
Time - O(n * n)
Space - O(n * n)
*/


#define inf 1000000
    
    int count(int curr,int clip,int n,vector<vector<int>> &dp)
    {
        //base...
        if(curr > n)
            return inf;
        
        if(curr == n)
            return 0;
        
        if(dp[curr][clip] != -1)
            return dp[curr][clip];
        
        int copy = count(curr+curr,curr,n,dp) + 2; //here we are doing copy and paste operation simultaneously
        int paste = count(curr+clip,clip,n,dp) + 1; //only doing paste operation
        
        return min(copy,paste);
    }
    
    int minSteps(int n) {
        if(n == 1)
            return 0;
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        int ans = count(1,1,n,dp) + 1; /adding one as copying given 'A' initially take one step 
        
        return ans;
    }
