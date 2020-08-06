/*

Ques :-Given an array of n elements, where each element is at most k away from its target 
position. The task is to print array in sorted form.(time-O(nlogk) )

Concept:- using min_heap

*/


void work()
{
	int n,k;
	cin>>n>>k;
	
	int arr1[n];
	
	priority_queue<int,vector<int>,greater<int> >min_heap;
	
	for(int i=0;i<n;++i)
	{
		cin>>arr1[i];
	}
	
	for(int i=0;i<n;++i)
	{
		min_heap.push(arr1[i]);
		
		if(min_heap.size()>k)
		{
			cout<<min_heap.top()<<" ";
			min_heap.pop();
		}
	}
	
	while(!min_heap.empty() )
	{
		cout<<min_heap.top()<<" ";
		min_heap.pop();
	}
}
