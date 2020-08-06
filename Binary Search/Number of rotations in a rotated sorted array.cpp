/*

Ques :-Number of rotations in a rotated sorted array...(elemnts are unique)

Method 1:- Time -O(n) 

Theory:- Just finding the minimum element..

Method 2:- Time - O(log2n) 

*/

void work()
{
	int n;
	cin>>n;
	
	ll arr1[n];
	
	for(int i=0;i<n;++i)
	{
		cin>>arr1[i];
	}
	
	int start=0,end=n-1,index=1;
	
	while(start<=end)
	{
		int mid = start+(end-start)/2;
		
		int prev,next;
		prev=(mid+n-1)%n;
		
		next=(mid+1)%n;
		
//		cout<<start<<" "<<mid<<" "<<end<<"\n";
		
		if(arr1[mid]<arr1[prev] && arr1[mid]<=arr1[next])
		{
			index=mid;
			break;
		}
		else if(arr1[mid]<arr1[end])
		end=mid-1;
		else
		start=mid+1;
	}
	
	cout<<n-index;
}
