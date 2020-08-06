/*

Ques :- Given an integer array A of N elements. You need to find the sum of two elements such that sum is closest to zero.

Intitution:- 1. Consider the number line in mind...
	2. Sort the array...
	3.make two pointer appraoch , first at -ve numbers and other at +ve number

*/

void work()
{
	int n;
	cin>>n;
	
	int arr1[n];
	
	for(int i=0;i<n;++i)
	cin>>arr1[i];
	
	sort(arr1,arr1+n);
	
	int neg=-1,pos=n;
	
	for(int i=0;i<n;++i)
	{
		if(arr1[i]>=0)
		{
			pos = min(pos,i);
		}
		else
		{
			neg = max(neg,i);
		}
	}
	
	if(neg == -1)
	{
		cout<<arr1[0]+arr1[1];
		return;
	}
	
	if(pos == n)
	{
		cout<<arr1[n-1]+arr1[n-2];
		return;
	}
	
	int diff = INT_MAX,ans;
	
	while(pos<n && neg>=0)
	{
//		cout<<neg<<" "<<pos<<"\n";
		
		int close = abs( arr1[pos] + arr1[neg] );
		if(close < diff)
		{
			diff = close;
			ans = arr1[pos] + arr1[neg];
		}
		
		if(arr1[pos]<abs(arr1[neg]))
		++pos;
		else if(arr1[pos]>abs(arr1[neg]))
		--neg;
		else
		{
// 			++pos;
// 			--neg;
            break;
		}
	}
	
	cout<<ans;
}
