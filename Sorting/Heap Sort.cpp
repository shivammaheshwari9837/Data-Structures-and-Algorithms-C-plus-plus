/*

0 - based indexing

*/

void max_heapify(int arr1[],int i,int n)
{
	int left = 2*i;
	int right = 2*i + 1;
	
	int largest = i;
	
	if(left<n && arr1[left]>arr1[largest])
	largest = left;
	
	if(right<n && arr1[right]>arr1[largest])
	largest = right;
	
	if(largest!=i)
	{
		swap(arr1[i],arr1[largest]);
		
		max_heapify(arr1,largest,n);
	}
}

void build_max_heap(int arr1[],int n)
{
	for(int i=n/2;i>=0;--i)
	{
		max_heapify(arr1,i,n);
	}
}

void heap_sort(int arr1[],int n)
{
	int heap_size = n;
	build_max_heap(arr1,heap_size);
//	heap_size = heap_size-1;
	
	for(int i=n-1;i>=1;--i)
	{
		swap(arr1[0],arr1[i]);
		heap_size = heap_size-1;
		max_heapify(arr1,0,heap_size);
	}
}
