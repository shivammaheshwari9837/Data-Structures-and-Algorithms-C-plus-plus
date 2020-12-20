/*

Ques:- Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Concept:- 1)Read this :- https://leetcode.com/problems/majority-element-ii/discuss/543672/BoyerMoore-majority-vote-algorithm-EXPLAINED-(with-pictures)

Time - O(n)
Space - O(1)

*/

vector<int> majorityElement(vector<int>& nums) {
        
        int x = -1,y = -1,cx = 0,cy = 0;
        
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i] == x)
                ++cx;
            else if(nums[i] == y)
                ++cy;
            else if(cx == 0)
            {
                x = nums[i];
                cx = 1;
            }
            else if(cy == 0)
            {
                y = nums[i];
                cy = 1;
            }
            else
            {
                --cx;
                --cy;
            }
        }
        
        cx = cy = 0;
        
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i] == x)
                ++cx;
            else if(nums[i] == y)
                ++cy;
        }
        
        vector<int> ans;
        
        if(cx > (nums.size() / 3)) ans.push_back(x);
        if(cy > (nums.size() / 3)) ans.push_back(y);
        
        return ans;
    }
