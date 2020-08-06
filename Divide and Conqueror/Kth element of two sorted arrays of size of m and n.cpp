/*

Ques :-  Kth element of two sorted arrays of size of m and n.(time = O(log(min(n,m) ) ) )

Concept:- Similar to (median of two sorted arrays)

*/

void work()
{
	int n,m,k,x,ans;
	cin>>n>>m>>k;
	
	vector<int> arr1,arr2;
	
	for(int i=0;i<n;++i)
	{
		cin>>x;
		arr1.push_back(x);
	}
	
	for(int i=0;i<m;++i)
	{
		cin>>x;
		arr2.push_back(x);
	}
	
	if(n>m)
	{
		swap(arr1,arr2);
		swap(n,m);
	}
	
	int low = 0,high = n;
	
	while(low<=high)
	{
		int partitionX = (low+high)/2;
		int partitionY = k - partitionX;
		
		if(partitionY < 0)
		{
			high = partitionX-1;
			continue;
		}
		else if(partitionY > m)
		{
			low = partitionX+1;
			continue;
		}
		
		int leftX = (partitionX == 0) ? INT_MIN : arr1[partitionX-1];
		int rightX = (partitionX == n) ? INT_MAX : arr1[partitionX];
		
		int leftY = (partitionY == 0) ? INT_MIN : arr2[partitionY-1];
		int rightY = (partitionY == m) ? INT_MAX : arr2[partitionY];
		
		if(leftX<=rightY && leftY<=rightX)
		{
			ans = max(leftX,leftY);
			break;
		}
		else if(leftX > rightY)
		high = partitionX-1;
		else
		low = partitionX+1;
	}
	
	cout<<ans;
}

