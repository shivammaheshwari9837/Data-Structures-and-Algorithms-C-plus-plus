/*

Ques :-Subarray with the given sum(Space- O(1) )

Concept:- Sliding window technique..

*/


void work()
{
	ll n,tar;
	cin>>n>>tar;
	
	ll arr1[n];
	
	for(int i=0;i<n;++i)
	cin>>arr1[i];
	
	ll left=-1,right=-1,t_sum=0;
	
	while(left<n)
	{
		while(t_sum<tar)
		{
			++right;
			t_sum+=arr1[right];
		}
		
		if(t_sum == tar)
		{
			break;
		}
		
		while(t_sum>tar)
		{
			++left;
			t_sum-=arr1[left];
		}
		
		if(t_sum == tar)
		{
			break;
		}
	}
	
	if(left>=n)
	cout<<-1;
	else
	cout<<left+1<<" "<<right;
}
