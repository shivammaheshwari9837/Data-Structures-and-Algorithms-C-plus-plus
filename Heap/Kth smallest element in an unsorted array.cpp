/*

Ques:- Kth smallest element in an unsorted array...(time-O(nlogk) )
Theory:- Uses max heap


*/

void work()
{
	int n;
	cin>>n;
	
	priority_queue<int> max_heap;

	int arr1[n];
	for(int i=0;i<n;++i)
	{
		cin>>arr1[i];
	}

	int k;
	cin>>k;

	for(int i=0;i<n;++i)
	{
		max_heap.push(arr1[i]);
		
		if(max_heap.size()>k)
		max_heap.pop();
	}

	cout<<max_heap.top();
}
