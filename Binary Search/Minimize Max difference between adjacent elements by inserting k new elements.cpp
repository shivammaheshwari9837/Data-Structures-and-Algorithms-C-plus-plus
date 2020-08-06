/*

Ques:- You are given an array arr[ ], of n integers. Minimize the max difference the between pairs of adjacent array elements by inserting at most k elements in the array.

Concept:- 1.)We are making the search space related to difference (ie. answer) 
          2.)Setting up low=1,high = 1
          3.)Than for every two consecutive elements , we are checking that it is possioble to set up the current difference
*/


int insertions(int arr[], int n, int gap) //checking up if possible gap or difference possible while iterating the array
{
    int ret=0;
    for(int i=1; i<n; i++)
        if( arr[i] != arr[i-1] )
            ret += ( abs(arr[i]-arr[i-1]) -1 ) / gap;
    return ret;
}

int minimizedMaxDiff(int arr[], int n, int k)
{
    int low=1, high=1;
    for(int i=1; i<n; i++)
        high = max( high , abs(arr[i] - arr[i-1]) ); //setting up the max diffence in the input to high variable
    
    while(low<high) 
    {
        int mid = (high+low)/2;  // here consider mid ans the possible answer or possible diffenence
        
        if( insertions(arr,n,mid) <= k ) // if k possible , we reduce our search space to left(decreasing the value)
            high = mid;
        else  // not possible,we increase the space
            low = mid+1;
    }
    
    return high;
}
