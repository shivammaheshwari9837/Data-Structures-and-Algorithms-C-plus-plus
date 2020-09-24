/*

Ques:- Given an integer array A[] of size N. The task is to find the maximum of the minimum of every window size in the array.
       Note: Window size varies from 1 to n.
       
Concept:-     1)Try to find indexes of next smaller and previous smaller for every element.
              2)Next smaller is the nearest smallest element on right side of arr[i].
              3)Similarly, previous smaller element is the nearest smallest element on left side of arr[i].
              4)If there is no smaller element on right side, then next smaller is n.
              5)If there is no smaller on left side, then previous smaller is -1.
              6)f you have indexes of next and previous smaller, arr[i] is a minimum of a window of length “right[i] – left[i] – 1”.
              7)Few important observations to fill remaining entries:-
                     a) Result for length i, i.e. ans[i] would always be greater or same as result for length i+1, i.e., ans[i+1].
                     b) If ans[i] is not filled it means there is no direct element which is minimum of length i and therefore either the element of length ans[i+1], 
                     or ans[i+2], and so on is same as ans[i]
                     c)So we fill rest of the entries using loop.
                     
Time - O(n)
Space - O(1)
*/

#include<bits/stdc++.h>
using namespace std;

void help(int *arr, int n){
    stack<int>s;
    int left[n+1];
    int right[n+1];
    
    for(int i=0;i<n;i++){ //initializing the left and right smaller by deafult
        left[i]=-1;
        right[i]=n;
    }
    
    for(int i=0;i<n;i++){ //loop for NSL(Next Smaller Left)
        while(!s.empty()&& arr[s.top()]>=arr[i])
            s.pop();
            
        if(!s.empty())
            left[i]=s.top();
        
        s.push(i);
    }
    
    while(!s.empty())
        s.pop();
    
    
    for(int i=n-1;i>=0;i--){ //loop for NGR(ie. next smaller Right)
        while(!s.empty() && arr[s.top()]>=arr[i])
            s.pop();
            
        if(!s.empty())
            right[i]=s.top();
            
        s.push(i);
    }
       
    //NSL and NGR will help to find the minimum in some particular window,ie. always valid answer
    
    int ans[n+1]; //from 1...........n
       
    for(int i=0;i<=n;i++) //initializing
        ans[i]=0;
        
    for(int i=0;i<n;i++){
        int len= right[i]-left[i]-1; //finding the window size,ie. len
        ans[len]= max(ans[len], arr[i]); 
    }    
    
    for(int i=n-1;i>=1;i--){ //if some values remians unfilled,than filled by this
        ans[i]=max(ans[i], ans[i+1]);
    }
    
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    
}


int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        help(arr,n);
        cout<<endl;
    
    }
    
    return 0;
}
