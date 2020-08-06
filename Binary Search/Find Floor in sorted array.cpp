/*

Ques:- Find Floor in sorted array

*/

void work()
{
	int n,k;
	cin>>n>>k;
	
	int arr1[n];
	
	for(int i=0;i<n;++i)
	{
		cin>>arr1[i];
	}
	
	int start=0,end=n-1,ans=-1;
	
	while(start<=end)
	{
		int mid=start+(end-start)/2;
		
		//check...
		if(arr1[mid]==k)
		{
			ans=mid;
			break;
		}
		else if(arr1[mid]<k)
		{
			ans=mid;
			start=mid+1;
		}
		else
		end=mid-1;
	}
	
	cout<<ans;
	
}


/*

Similar used in finding the ceil of a sorted array

*/
