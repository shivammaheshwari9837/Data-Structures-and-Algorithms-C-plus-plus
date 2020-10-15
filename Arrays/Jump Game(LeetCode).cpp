/*

Ques:- Given an array of non-negative integers, you are initially positioned at the first index of the array.

        Each element in the array represents your maximum jump length at that position.

        Determine if you are able to reach the last index.
        
Concept:- 1)We only have to focus on the value = 0 in the array,others values should give us atleast 1 jump
          2)We make an variable to see our largest jump possibel
          
Time - O(n)
Space - O(1)

*/

bool canJump(vector<int>& nums) {
        
        if(nums.size() == 1) //ex - [0] also
            return true;
        
        int lastIndex = -1;
        for(int i=0;i<nums.size() && lastIndex < (int)nums.size()-1;++i) //loops until the second last element as lastIndex
        {
            if(nums[i] == 0) //if 0 appears,check the farthest jump we can make
            {
                if(lastIndex <= i)
                    return false;
            }
            else
                lastIndex = max(lastIndex,i + nums[i]);
        }
        
        return true;
    }
