/*

Ques :-Next Permutations of a array of number(Time-O(n) , space-O(1))

Theory:- 1. search for index of the just decreasing sequence from last(let be x)
2. swap x-1 th value with the next greator value in above sequence
3. reverse the above sequence than to get answer.

*/

int last=nums.size()-1;
        
        for(int i=nums.size()-2;i>=0;--i)
        {
            if(nums[i]>=nums[i+1])
                last=i;
            else
                break;
        }
        
        if(last==0)
        {
	    //redundant due to LeetCode
            int i=0,j=nums.size()-1;
            for(;i<j;++i,--j)
                swap(nums[i],nums[j]);
        }
        else
        {
            int maxi=nums[last-1];
            for(int i=nums.size()-1;i>=last;--i)
            {
                if(nums[i]>maxi)
                {
                    swap(nums[last-1],nums[i]);
                    break;
                }
            }
            
            int i=last,j=nums.size()-1;
            for(;i<j;++i,--j)
            {
                swap(nums[i],nums[j]);
            }
        }
    }
