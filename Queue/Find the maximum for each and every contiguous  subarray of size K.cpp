/*

Ques:- Given an array A and an integer K. Find the maximum for each and every contiguous 
subarray of size K, Time-O(2*n)=O(n)

Theory - Uses Double ended queue.....

*/

void work()
{
    int n,k;
    cin>>n>>k;
    
    int arr1[n+1];
    
    deque<int> dq1;
    
    for(int i=1;i<=n;++i)
    cin>>arr1[i];
    
    for(int i=1;i<=k;++i)
    {
    	while( ( !dq1.empty() )&& arr1[i]>=(arr1[dq1.back() ]))
    	dq1.pop_back();
    	
    	dq1.push_back(i);
    }
    
    for(int i=k+1;i<=n;++i)
    {
    	cout<<arr1[dq1.front()]<<" ";
    	
    	while((!dq1.empty()) && (dq1.front()<=i-k)) 
    	dq1.pop_front();
    	
    	while( ( !dq1.empty() )&& arr1[i]>=(arr1[dq1.back() ]))
    	dq1.pop_back();
    	
    	dq1.push_back(i);
	}
    
    cout<<arr1[dq1.front()];
}
