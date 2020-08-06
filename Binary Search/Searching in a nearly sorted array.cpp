/*

Ques:- Searching in nearly sorted array...

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
	
	int start=0,end=n-1,index=-1;
	
	while(start<=end)
	{
		int mid=start+(end-start)/2;
		
		//check...
		if(arr1[mid]==k)
		{
			index=mid;
			break;
		}
		else if(mid-1>=0 && arr1[mid-1]==k)
		{
			index=mid-1;
			break;
		}
		else if(mid+1<=n-1 && arr1[mid+1]==k)
		{
			index=mid+1;
			break;
		}
		else if(arr1[mid]<k)
		start=mid+2;
		else
		end=mid-2;
	}
	
	cout<<index;
	
}
