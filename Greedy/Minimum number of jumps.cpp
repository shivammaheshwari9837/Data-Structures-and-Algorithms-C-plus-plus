/*

Ques:- Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the minimum number of 
jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Concept:- 1)Here , we will simply iterate through some valid range of arr[i],to find the maximum range we can reach
          2)so we maintain two variables for that..
          
Time - O(n)
Space - O(1)

*/

int jump(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int n = nums.size();
        
        int currMax = nums[0]; //for the current maximum range upto which in future I can jump
        int maxReach = nums[0]; //for the maximum reach or the segement choosing
        
        int steps = 1;
        
        for(int i=1;i<=min(maxReach,n-1);++i)
        {
            currMax = max(currMax,i + nums[i]);
            if(i == n-1) //if I reach upto last index
                return steps;
            
            if(i == maxReach)
            {
                ++steps;
                maxReach = currMax;
            }
        }
        
        return -1; //if nothing happens
    }

