/*

Ques:- Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k.

Concept:- 1)Maintain two auxiliary array,first provides the smallest element on left,and second provides the largest element on right for every index valid index i

*/

vector<int> find3Numbers(vector<int> arr, int N) {
    // Your code here
    
    vector<int> smLeft(N,INT_MAX),larRig(N,INT_MIN); 
    
    for(int i=1;i<N;++i)
    {
        smLeft[i] = min(arr[i-1],smLeft[i-1]); //stroring the smallest elemnt on left 
    }
    
    for(int i=N-2;i>=0;--i)
    {
        larRig[i] = max(arr[i+1],larRig[i+1]); //storing the largest element on right 
    }
    
    vector<int> ans;
    
    for(int i=0;i<N;++i)
    {
        if(smLeft[i]<arr[i] && arr[i]<larRig[i]) //if conditions are valid(because above approach also conatins similar elements too)
        {
            ans.push_back(smLeft[i]);
            ans.push_back(arr[i]);
            ans.push_back(larRig[i]);
            return ans;
        }
    }
    
    return ans;
}
