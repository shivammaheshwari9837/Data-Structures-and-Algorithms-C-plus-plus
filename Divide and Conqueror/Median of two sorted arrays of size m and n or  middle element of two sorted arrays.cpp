/*


Ques :- Median of two sorted arrays of size m and n or  middle element of two sorted arrays, T=(O(log(min(n,m) ) )

Concept:- 1.we will do binary search over the smaller size array
	2. partition of X + partition of Y = (x+y+1)/2;
	than:- partition of X = (low + high)/2,where low = 0 ,high = x;
	thus partition of Y = (x+y+1)/2 - partition of X
  
  */
  
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double ans;
        
        if(nums1.size()>nums2.size())
            swap(nums1,nums2);
        
        int x = nums1.size();
        int y = nums2.size();
        
        int low = 0;
        int high = x;
        
        while(low<=high)
        {
            int partitionX = (low+high)/2;
            int partitionY = (x+y+1)/2 - partitionX;
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX-1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY-1];
            int minRightY = (partitionY == y) ? INT_MAX: nums2[partitionY];
            
            if(maxLeftX<=minRightY && maxLeftY<=minRightX)
            {
                if((x+y)%2 == 0)
                {
                    double temp1 = max(maxLeftX,maxLeftY);
                    double temp2 = min(minRightY,minRightX);
                    
                    ans = (temp1+temp2)/2;
                    break;
                }
                else
                {
                    ans = max(maxLeftX,maxLeftY);
                    break;
                }
            }
            else if(maxLeftX > minRightY)
                high = partitionX-1;
            else
                low = partitionX + 1;
        }
        return ans;     
        
    }
