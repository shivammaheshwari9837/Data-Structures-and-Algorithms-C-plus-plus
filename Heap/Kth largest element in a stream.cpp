/*

Ques :- Kth largest element in a stream ...

Theory:- Using min_heap.

*/


void work()
{
    int k,n;
    cin>>k>>n;
    
    priority_queue<int,vector<int>,greater<int> > min_heap;
    
    int arr1[n];
    
    for(int i=0;i<n;++i) cin>>arr1[i];
    
    int ans[n];
    
    for(int i=0;i<n;++i)
    {
    	min_heap.push(arr1[i]);
    	
    	if(min_heap.size()>k)
    	{
    		min_heap.pop();
		}
		
		if(min_heap.size() == k)
		ans[i] = min_heap.top();
		else
		ans[i]=-1;
	}
	
	for(int i=0;i<n;++i)
	cout<<ans[i]<<" ";
}
