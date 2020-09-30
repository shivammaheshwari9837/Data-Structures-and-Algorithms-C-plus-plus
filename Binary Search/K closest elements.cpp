/*

Ques:- 

*/

vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        int rIndex = arr.size(),lIndex = -1;
        
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
        
//        cout<<lIndex<<" "<<rIndex<<"\n";
		
		int left = lIndex,right = rIndex;
		
		while(left>=0 && right<n && k > 0)
		{
			if(arr[left] == x)
			{
				--left;
				continue;
			}
			if(arr[right] == x)
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
		
		while(k>0 && left < 0)
		{
			ans.push_back(arr[right]);
			++right;
			--k;
		}
		
		while(k>0 && right >=n)
		{
			ans.push_back(arr[left]);
			--left;
			--k;
		}
		
//		sort(ans.begin(),ans.end());
        
        return ans;
    }
