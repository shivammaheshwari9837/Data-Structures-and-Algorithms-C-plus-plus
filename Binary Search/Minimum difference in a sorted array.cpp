/*

Ques :- Minimum difference in a sorted array

*/

void work()
{
	int n;
	int k;
	cin>>n>>k;
	
	int arr1[n];
	
	for(int i=0;i<n;++i)
	{
		cin>>arr1[i];
	}
	
	int start=0,end=n-1;
	
	while(start<=end)
	{
		int mid=start+(end-start)/2;
		
		
		if(arr1[mid]==k)
		{
			break;
		}
		else if(arr1[mid]<k)
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}
	
	
	cout<<min(abs(k-arr1[start]),abs(k-arr1[end]));
	
}
