/*

Ques:- Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Concept:- 1)Here we will use Boyer-Moore Algorith
          2)Intutuion:-    https://medium.com/cantors-paradise/computing-the-majority-vote-on-pen-and-paper-the-boyer-moore-algorithm-3f739de3d8cb
          
 Time - O(n)
 Space - O(1)


*/


 int majorityElement(vector<int>& nums) {
        int majorIndex = 0; //first considering majority element at index 0
        int count = 1; //thus making count
        
        //we are removing element in pairs when are different
        
        for(int i=1;i<nums.size();++i)
        {
            nums[majorIndex] == nums[i] ? ++count : --count;
            
            if(count == 0) //when count is zero,means current element is crossed by different element,thus can't be majority
            {
                majorIndex = i;
                count = 1;
            }
        }
        
        return nums[majorIndex];
        
    }
