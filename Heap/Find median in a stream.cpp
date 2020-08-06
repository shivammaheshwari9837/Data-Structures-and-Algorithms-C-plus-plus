/*

Ques :- Find median in a stream..

Theory:-1. Maintain both min_heap and max_heap 
2. maintain a current median too
3. Current stream<medain ,push it into max_heal
		else
	push it into min_heap

*/

void work()
{
    int n;
    cin>>n;
    
    int arr1[n];
    
    for(int i=0;i<n;++i) cin>>arr1[i];
    
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int> > min_heap;
    
    int ans[n],median,middle;
    for(int i=0;i<n;++i)
    {
    	if(i == 0)
    	{
    		max_heap.push(arr1[0]);
    		ans[i] = arr1[0];
    		median = arr1[0];
		}
		else
		{
			if(arr1[i]>median)
			{
				min_heap.push(arr1[i]);
			}
			else
			{
				max_heap.push(arr1[i]);
			}
			
			if(max_heap.size()+2 == min_heap.size())
			{
				max_heap.push(min_heap.top());
				min_heap.pop();
			}
			else if(min_heap.size()+2 == max_heap.size())
			{
				min_heap.push(max_heap.top());
				max_heap.pop();
			}
			
			
			if(max_heap.size()>min_heap.size())
			{
				ans[i] = max_heap.top();
				median = max_heap.top();
			}
			else if(min_heap.size()>max_heap.size())
			{
				ans[i] = min_heap.top();
				median = min_heap.top();
			}
			else
			{
				middle = (min_heap.top() + max_heap.top() )/2;
				ans[i] = middle;
				median = middle;
			}
		}
	}
	
	for(int i=0;i<n;++i)
	cout<<ans[i]<<"\n";
}
