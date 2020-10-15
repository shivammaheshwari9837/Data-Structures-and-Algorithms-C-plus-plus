/*

Ques:- Given an array arr[] denoting heights of N towers and a positive integer K, modify the heights of each tower either by increasing or decreasing them by K only once. 
Find out the minimum difference of the heights of shortest and longest modified towers.

Concept:- 1)The idea is to sort all elements increasing order. And for all elements check if subtract(element-k) and add(element+k) makes any changes or not.

Time - O(n * log n)
Space - O(1)

*/

int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        
        int ans = arr[n-1] - arr[0];
        
        int big = arr[n-1] - k;
        int small = arr[0] + k;
        
        if(big < small)
        swap(big,small);
     
        for(int i=1;i<n-1;++i)
        {
            int add = arr[i] + k;
            int sub = arr[i] - k;
            
            // if addition and subtraction of element remains int the range of maximum and minimum,do not change
            if(add <= big || sub >= small)
            continue;
            
            // Either subtraction causes a smaller 
            // number or addition causes a greater 
            // number. Update small or big using 
            // greedy approach (If big - subtract 
            // causes smaller diff, update small 
            // Else update big) 
            if(big - sub <= add - small)
            small = sub;
            else
            big = add;
        }
        
        ans = min(ans,big - small);
        return ans;
    }
