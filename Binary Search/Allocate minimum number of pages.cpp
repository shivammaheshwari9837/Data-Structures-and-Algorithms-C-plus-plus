/*

Ques:- Allocate minimum number of pages(GFG)

Intitution:- 1.)uses binary search on answer concept.
	2.) We created aur search space as pages(assume number line of a pages)


*/


bool isValid(ll upper,ll stu,ll arr1[],ll n)
{
	ll t_stu=1;
	
	ll temp_sum=0;
	
	for(ll i=0;i<n;++i)
	{
		temp_sum+=arr1[i];
		if(temp_sum>upper)
		{
			++t_stu;
			temp_sum=arr1[i];
		}
	}
	
	if(t_stu<=stu)
	return true;
	else
	return false;
}
void work()
{
	ll n;
	cin>>n;
	
	ll arr1[n];
	ll start=0,end=0,res;
	
	for(ll i=0;i<n;++i) cin>>arr1[i] , start=max(start,arr1[i]) , end+=arr1[i];
	
	ll stu;
	cin>>stu;
	
	if(stu>n)
	res=-1;
	else
	{
		while(start<=end)
		{
			ll mid = start + (end-start)/2;
			bool curr=isValid(mid,stu,arr1,n);
			
			if(curr == true)
			{
				res=mid;
				end=mid-1;
			}
			else 
			{
				start=mid+1;
			}
		}
	}
	
	
	cout<<res;
	
}
