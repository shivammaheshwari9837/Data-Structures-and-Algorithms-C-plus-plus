/*

Ques:- Given a sorted array, arr[] of N integers, and a value X. Find the K closest elements to X in arr[].
	Keep the following points in mind:

	If X is present in the array, then it need not be considered.
	If there are two elements with the same difference with X, the greater element is given priority.
	If sufficient elements are not present on the right side then take elements from left and vice versa.

Concept:- 1)we maintain two indices, which will maintain the nearest indices in which the X element found
	  2)Since array is sorted, than we will apply binary search in O(log n) time
	  3)After that we maintain two pointers (rIndex,lIndex), which will keep the track of closest element
	
Time - O(logn + K)
Space - O(1)
*/

vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        int rIndex = arr.size(),lIndex = -1; //we try to find the indices in which x can lie in O(log n )
        
        int low = 0,high = arr.size()-1;
        vector<int> ans;
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            if(arr[mid] == x)
            {
                lIndex = mid-1;
                rIndex = mid+1;
                break;
            }
            else if(arr[mid] < x)
            {
                lIndex = max(mid,lIndex);
                low = mid+1;
            }
            else
            {
                rIndex = min(mid,rIndex);
                high = mid-1;
            }
        }
		
		int left = lIndex,right = rIndex; //two pointers used as maintained above
		
		while(left>=0 && right<n && k > 0)
		{
			if(arr[left] == x) //if element is same as X,discard it
			{
				--left;
				continue;
			}
			if(arr[right] == x) //if element is same as X,discard it
			{
				++right;
				continue;
			}
			
			int diff1 = x - arr[left];
			int diff2 = arr[right] - x;
			
			if(diff1 < diff2)
			{
				ans.push_back(arr[left]);
				--left;
			}
			else
			{
				ans.push_back(arr[right]);
				++right;
			}
			
			--k;
		}
		
		while(k>0 && left < 0) //if some k is left,and left part is empty,than include only right part
		{
			ans.push_back(arr[right]);
			++right;
			--k;
		}
		
		while(k>0 && right >=n) //if some k is left,and right part becomes empty,than only includes left part elements
		{
			ans.push_back(arr[left]);
			--left;
			--k;
		}
        
        return ans;
    }
