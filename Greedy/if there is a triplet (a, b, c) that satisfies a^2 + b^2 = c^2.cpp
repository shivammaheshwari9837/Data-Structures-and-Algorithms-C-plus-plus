/*

Ques 75:- Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a^2 + b^2 = c^2.Time(O(n^2) )

Concept:- Using "meet in the middle algorithm"

*/

void work()
{
	int n;
	cin>>n;
	
	int arr1[n],x;
	
	for(int i=0;i<n;++i)
	{
		cin>>x;
		arr1[i] = x*x;
	}
	
	sort(arr1,arr1+n);
	
	for(int i=n-1;i>=2;--i)
	{
		int j=0,k=i-1;
		
		while(j<k)
		{
			if(arr1[i] == arr1[j] + arr1[k])
			{
				cout<<"Yes";
				return;
			}
			else if(arr1[i] > arr1[j] + arr1[k])
			{
				++j;
			}
			else
			--k;
		}
	}
	
	cout<<"No";
}
