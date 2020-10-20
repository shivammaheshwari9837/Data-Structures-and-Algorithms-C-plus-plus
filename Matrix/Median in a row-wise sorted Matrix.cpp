/*

Ques:- Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Concept:- 1)in this,we can use binary search to find median efficiently
          2)First, we need to find the minimum and maximum elements from the matrix. The minimum and maximum can be easily found since the rows are sorted so we need to 
          comapare with the first element of each row for minimum and last element of each row for maximum.
          3)After finding our min and max, we can apply binary search on this range. The mid element can be calculated and number of elements smaller or equal to mid can be 
          calculated, we have used upper_bound() function for this.
          4)Based on the value of our counter, the min and max can be adjusted accordingly based on what we do for binary search.
          
Note:- Here , upper bound helps to know how many elements are smaller or equal(since elements can be repeated too)
      Median for odd elements  = (n+1)/2

*/


int median(vector<vector<int>> &mat, int r, int c){
        // code here   
        int maxi = INT_MIN,mini = INT_MAX;
        
        for(int i=0;i<r;++i) //finding minimum and maximum in the whole array
        {
            maxi = max(mat[i][c-1],maxi);
            mini = min(mat[i][0],mini);
        }
        
        int desired = (r*c + 1)/2; //the median where element should lie
        int ans;
        
        while(mini < maxi)
        {
            int mid = mini + (maxi - mini)/2;
            
            int coun = 0;
            for(int i=0;i<r;++i)
            coun += upper_bound(mat[i].begin(),mat[i].end(),mid) - mat[i].begin(); //finding the index of first elemenst greator than mid
            
            if(coun < desired) //if count is smaller than desired index of median,than this probabily a valid answer too
            mini = mid + 1;
            else 
            maxi = mid;
        }
        
        return mini;
    }
