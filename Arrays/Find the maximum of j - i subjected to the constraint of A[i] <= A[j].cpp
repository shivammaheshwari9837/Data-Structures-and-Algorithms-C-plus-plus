/*

Ques :- Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Intitution:- 1. For the observation, in previous hint, make 2 arrays, 
		First, will store smallest occuring element before the element
		Second, will store largest occuring element after the element

		2.)Traverse the Second array, till the element in second array is larger than or equal to First array, and store the index difference. And if it becomes smaller, 
    traverse the first array till it again becomes larger.

		3.)And store the max difference of this index difference.

*/

void work()
{
	int n;
	cin>>n;
	
	ll arr1[n];
	for(int i=0;i<n;++i)
	cin>>arr1[i];
	
	ll *leftMin = new ll[n];
	ll *rightMax = new ll[n];
	
	leftMin[0] = arr1[0];
	
	for(int i=1;i<n;++i)
	{
		leftMin[i] = min(arr1[i],leftMin[i-1]);
	}
	
	rightMax[n-1] = arr1[n-1];
	
	for(int i=n-2;i>=0;--i)
	{
		rightMax[i] = max(arr1[i],rightMax[i+1]);
	}
	
	int left=0,right=0,ans=0;
	
	while(right<n && left<n)
	{
		if(leftMin[left]<=rightMax[right])
		{
			ans = max(ans,right-left);
			++right;
		}
		else
		{
			++left;
		}
	}
	
	cout<<ans;

}
