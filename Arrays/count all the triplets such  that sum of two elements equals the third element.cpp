/*

Ques :- Given an array of distinct integers. The task is to count all the triplets such 
that sum of two elements equals the third element.

Concept:- Two pointer algorithm.....

*/

void work()
{
	ll n;
	cin>>n;
	
	ll arr1[n];
	
	for(int i=0;i<n;++i)
	cin>>arr1[i];
	
	sort(arr1,arr1+n);
	int coun=0;
	
	for(int i=n-1;i>=2;--i)
	{
		int left = 0,right = i-1;
		
		while(left<right)
		{
			if(arr1[left] + arr1[right] == arr1[i])
			{
				++coun;
				++left;
				--right;
			}
			else if(arr1[left] + arr1[right] > arr1[i])
			--right;
			else
			++left;
		}
	}
	
	if(coun)
	cout<<coun;
	else
	cout<<-1;
}
