/*

Ques:- Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Concept:- 1)We will maintain a speacial pointer which will move from column m.....0,and maintain the first occurance of '1' in every row

Time - O(n+m)
Space - O(1)

*/

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    
	    int index = m,prev = m;
	    int rowNum = -1;
	    
	    for(int i=0;i<n;++i)
	    {
	        while((index-1)>=0 && arr[i][index-1] == 1)
	        {
	            --index;
	        }
	        
	        if(index < prev)
	        {
	            prev = index;
	            rowNum = i;
	        }
	    }
	    
	    return rowNum;
	    
	}
