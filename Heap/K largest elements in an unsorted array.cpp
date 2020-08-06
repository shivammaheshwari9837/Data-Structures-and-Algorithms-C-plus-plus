/*

Ques :- K largest elements in an unsorted array (time-O(nlogK)
Concept:- Using min_heap

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
		cout<<arr1[i]<<" ";
		min_heap.push(arr1[i]);
		
		if(min_heap.size()>k)
		min_heap.pop();
	}
	cout<<"\n";
	
	while(!min_heap.empty() )
	{
		cout<<min_heap.top()<<" ";
		min_heap.pop();
	}
}
