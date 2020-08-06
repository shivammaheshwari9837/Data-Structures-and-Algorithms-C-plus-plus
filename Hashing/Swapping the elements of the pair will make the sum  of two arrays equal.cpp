/*

Ques :- Given two arrays of integers, write a program to check if a pair of values (one value from each array) exists such that swapping the elements 
of the pair will make the sum of two arrays equal.

*/


void work()
{
	int n,m;
	cin>>n>>m;
	
	int arr1[n],arr2[m];
	
	unordered_map<int,int> m1,m2;
	
	int sum1=0,sum2=0;
	
	for(int i=0;i<n;++i)
	{
		cin>>arr1[i];
		sum1+=arr1[i];
		++m1[arr1[i]];	
	}
	
	for(int i=0;i<m;++i)
	{
		cin>>arr2[i];
		sum2+=arr2[i];
		++m2[arr2[i]];
	}	
	
	int diff = max(sum1,sum2) - min(sum1,sum2);
	
	
	if(diff%2 == 0)
	{
		if(sum1!=sum2)
		{
			for(auto i=m1.begin();i!=m1.end();++i)
			{
				int val = max(i->first,diff) - min(i->first,diff);
				
				if(m2.find(val)!=m2.end())
				{
					cout<<1;
					return;
				}
			}
		}
		else
		{
			cout<<1;
			return;
		}
	}
	
	
	cout<<-1;
}
