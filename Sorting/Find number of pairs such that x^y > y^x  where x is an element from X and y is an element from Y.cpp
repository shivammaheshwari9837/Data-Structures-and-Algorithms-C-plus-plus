/*

Ques :- Given two arrays X and Y of positive integers, find number of pairs such that x^y > y^x (raised to power of) where x is an element from X and y is an element from Y.

Concept: - 1. using sorting.
	   2. Simply sort the array Y[], and for every element x in X[], find the index idx of  	   smallest number just greater than x in Y[]. 
	   3. All the elements after, this index idx satisfy the above relation. So add (n - 	   idx) to the ans.

Some Exceptions:- 1. for x = 2 and  y= 3,4
		  2. for x = 3 and y= 2
      
*/


void work()
{
	int m,n;
	cin>>m>>n;
	
	vector<int> v1(m),v2(n);
	
	map<int,int> m2;
	
	for(int i=0;i<m;++i)
	{
		cin>>v1[i];
	}
	
	for(int i=0;i<n;++i)
	{
		cin>>v2[i];
		++m2[v2[i]];
	}
	
	sort(v1.begin(),v1.end());
	
	sort(v2.begin(),v2.end());
	
	ll ans=0;
	
	for(int i=0;i<m;++i)
	{
		if(v1[i]>1)
		{
			int bound;
			if(v1[i] == 2)
			bound = 4;
			else
			bound = v1[i];
			
			if(v1[i] == 3)
			ans+=m2[2];
			
			int index = upper_bound(v2.begin(),v2.end(),bound) - v2.begin();
			
			ans+=(n-index) + m2[1];
		}
	}
	
	cout<<ans;
}
