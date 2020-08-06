/*

Ques  :-Given an array containing N integers and an integer K. Your task is to find the 
length of the longest Sub-Array with sum of the elements equal to the given value K.(T= O(n))

Intitution:- 1.)take prefix sum.
	2.) while taking prefix sum, search that there is exist some prefixSum - k exist which
	which reduce to some subarry.

*/


void  work()
{
	int n,k;
	cin>>n>>k;
	int arr1[n+1],prefix[n+1];

	for(int i=1;i<=n;++i)
	{
		cin>>arr1[i];
	}
	
	unordered_map<int,int> m1;
	
	m1[0]=0;
	prefix[0]=0;

	int temp=0;
	int ans=0;
	
	for(int i=1;i<=n;++i)
	{
		temp+=arr1[i];
		prefix[i]=temp;
		
		
		int finding =prefix[i]-(k);
		
		if(m1.find(finding)!=m1.end())
		{
			auto p=m1.find(finding);
			ans=max(ans,abs(i-(p->second) ) );
		}
		
		if(m1.find(prefix[i])==m1.end())
		{
			m1[prefix[i]]=i;
		}
	}
	
	cout<<ans;
}
