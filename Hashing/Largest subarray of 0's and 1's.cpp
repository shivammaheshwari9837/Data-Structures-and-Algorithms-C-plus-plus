/*

Ques:- Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.
Concept:- 1)Just replace every 0 with -1, than problem will reduce to largest subarray with sum 0

Time = O(n)
Space = O(n)

*/

int maxLen(int arr[], int n)
{
    // Your code here
    for(int i=0;i<n;++i)
    {
        if(arr[i] == 0)
        arr[i] = -1;
    }
    
    int prefix[n];
    prefix[0] = arr[0];
    
    for(int i=1;i<n;++i)
    prefix[i] = prefix[i-1] + arr[i];
    
    unordered_map<int,int> mp1;
    int ans = 0;
    
    //finding the largest subarray with sum 0
    for(int i=0;i<n;++i)
    {
        if(prefix[i] == 0)
        ans = max(ans,i+1);
        else
        {
            if(mp1.find(prefix[i]) == mp1.end())
            {
                mp1[prefix[i]] = i;
            }
            else
            {
                ans = max(ans,i - mp1[prefix[i]]);
            }
        }
    }
    
    return ans;
}
