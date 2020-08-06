/*

Ques:-:-Given a sorted array with possibly duplicate elements, the task is to find 
indexes of first and last occurrences of an element x in the given array.

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

	int start=0,end=n-1;
	
	int first_occ=-1,last_occ=-1;
	
	while(start<=end)
	{
		int mid=start+(end-start)/2;
		
		if(arr1[mid]==k)
		{
			first_occ=mid;
			end=mid-1;
		}
		else if(k<arr1[mid])
		end=mid-1;
		else
		start=mid+1;
	}
	
	start=0,end=n-1;
	
	while(start<=end)
	{
		int mid=start+(end-start)/2;
		
		if(arr1[mid]==k)
		{
			last_occ=mid;
			start=mid+1;
		}
		else if(k<arr1[mid])
		end=mid-1;
		else 
		start=mid+1;
	}
	
	if(first_occ==-1||last_occ==-1)
	cout<<-1;
	else
	cout<<first_occ<<" "<<last_occ;
}
