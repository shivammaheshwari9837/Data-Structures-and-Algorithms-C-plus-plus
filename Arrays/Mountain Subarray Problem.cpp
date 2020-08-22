/*

Ques:- We are given an array of integers and a range, we need to find whether the subarray which falls in this range has values in the form of a mountain or not. 
All values of the subarray are said to be in the form of a mountain if either all values are increasing or decreasing or first increasing and then decreasing. 
More formally a subarray [a1, a2, a3 … aN] is said to be in form of a mountain if there exists an integer K, 1 <= K <= N such that,
a1 <= a2 <= a3 .. <= aK >= a(K+1) >= a(K+2) …. >= aN
You have to process Q queries. In each query you are given two integer L and R, denoting starting and last index of the subarrays respectively.
              
Concept:- 1)We maintain two arrays left and right where left[i] stores the last index on the left side which is increasing i.e. greater than its previous element and 
          right[i] will store the first index on the right side which is decreasing i.e. greater than its next element.
          2)Suppose range [l, r] is given then only if right[l] >= left[r]
          3)The reason we are doing it, we have to avoid the following pattern----  \         /   , rest 3 are allowed int the problem
                                                                                     \       /
                                                                                      \     /
                                                                                       \   /
                                                                                        \ /
          4)Since left subarray shows the pattern for some ith index:-     /     ie increasing
                                                                          /
                                                                         /
                                                                        /
          5)And right subarray shows the pattern for index i:-  \
                                                                 \
                                                                  \
                                                                   \
          6)by checking the the condition in point number 2,we try avoid the pattern that is not allowed(refer to point number 3 for pattern)
          
Time- O(n),Space - O(n)

*/

vector<bool> processQueries(int arr[], int n, vector<pair<int, int>> &queries,
                            int q) {
    int left[n],right[n];
    
    left[0] = 0;
    
    int leftIns = 0;
    for(int i=1;i<n;++i)
    {
        if(arr[i] > arr[i-1])
        leftIns = i;
        
        left[i] = leftIns;
    }
    
    right[n-1] = n-1;
    int rightDcr = n-1;
    for(int i=n-2;i>=0;--i)
    {
        if(arr[i] > arr[i+1])
        rightDcr = i;
        
        right[i] = rightDcr;
    }
    
    vector<bool> ans(q);
    for(int i=0;i<q;++i)
    {
        int l = queries[i].first,r = queries[i].second;
        
        if(right[l] >= left[r])
        ans[i] = true;
        else
        ans[i] = false;
    }
    
    return ans;
}
