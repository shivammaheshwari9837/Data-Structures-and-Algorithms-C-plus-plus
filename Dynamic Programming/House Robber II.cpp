/*

Ques:- You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two 
adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Concept:- 1)It is much similar to problem House Robber 1(Leetcode)
          2)We have two choices :- 1)either take particular ith values,than has to shift to i+2 th value
                                   2)not take ith value,than try to shift i+1 th value
          3)Since if I take 0th index value,than can't take n-1 th value,or vice-versa
          4)So, we make array 1 from 0.....n-2, and array2 from 1.....n-1,and apply recusive to both approaches
          5)And find the maximum from it
          
Time - O(n)
Space - O(n)

*/


    int robber(vector<int> &nums,int index,vector<int> &dp)
    {
        //base....
        if(index < 0 )
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        int a = robber(nums,index-1,dp); //skip it
        int b = robber(nums,index-2,dp) + nums[index]; //take it...
        
        return dp[index] = max(a,b);
    }
    
    int rob(vector<int>& nums) {
        int siz = nums.size();
        
        if(siz == 0)
            return 0;
        
        if(siz == 1)
            return nums[0];
        
        vector<int> dp(siz+1,-1);
        
        vector<int> temp;
        
        for(int i=1;i<siz;++i) //first array
            temp.push_back(nums[i]);
        
        int ans1 = robber(temp,temp.size()-1,dp);
        
        temp.clear();
        
        fill(dp.begin(),dp.end(),-1);
        
        for(int i=0;i<siz-1;++i) //second array
            temp.push_back(nums[i]);
        
        int ans2 = robber(temp,temp.size()-1,dp);
        
        return max(ans1,ans2);
    }
