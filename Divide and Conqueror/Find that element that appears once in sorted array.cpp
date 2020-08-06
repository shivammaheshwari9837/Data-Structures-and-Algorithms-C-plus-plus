/*

Ques :- Given a sorted array A, size N, of integers; every element appears twice except for one. Find that element that appears once in array.(T = O(logn) )

Concept:- 1.Observe index of elements before the answer and after the answer, rest is binary 	search

*/

void work()
{
	int n;
	cin>>n;
	
	int arr1[n];
	
	for(int i=0;i<n;++i)
	cin>>arr1[i];
	
	if(n == 1)
	{
		cout<<arr1[0];
		return;
	}
	
	int low = 0,high = n-1,ans;
	
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		
		if(mid == 0 && arr1[mid]!=arr1[mid+1])
		{
			ans = arr1[mid];
			break;
		}
		else if(mid == n-1 && arr1[mid]!=arr1[mid-1])
		{
			ans = arr1[mid];
			break;
		}
		else if(arr1[mid]!=arr1[mid+1] && arr1[mid]!=arr1[mid-1])
		{
			ans = arr1[mid];
			break;
		}
		else if(( mid%2 == 0 && arr1[mid] == arr1[mid+1] ) || (mid%2!=0 && arr1[mid] == arr1[mid-1]))
		low = mid +1;
		else 
		high = mid - 1;
	}
	
	cout<<ans;
}
