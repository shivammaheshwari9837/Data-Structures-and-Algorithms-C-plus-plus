/*

Ques:- Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on...

Concept:- 1. Try to store two values at a single index...
	2. Let n1 and n2 be two values , and we have to store n1 and n2 at n1.		
		we can use formula:- n1 = n1 + (n2%z)*z, where z>n1 and z>n2.
    
 */
 
 void work()
{
	ll n;
	cin>>n;
	
	ll arr1[n];
	
	for(ll i=0;i<n;++i)
	cin>>arr1[i];
	
	
	ll maxi = arr1[n-1]+1;
	
	ll min_ind=-1,max_ind=n;
	
	for(ll i=0;i<n;++i)
	{
		if(i%2 == 0)
		{
			--max_ind;
			arr1[i]+=(arr1[max_ind]%maxi)*maxi;
		}
		else
		{
			++min_ind;
			arr1[i]+=(arr1[min_ind]%maxi)*maxi;
		}
	}
	
	for(ll i=0;i<n;++i)
	cout<<arr1[i]/maxi<<" ";
}
