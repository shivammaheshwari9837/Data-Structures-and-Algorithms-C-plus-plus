/*

Ques :- Jumping Catapillar (GFG)

Concept:- 1.)Similar to sieve of Erantheoses


*/

void work()
{
	int n;
	cin>>n;
	
	bool isEaten[n+1] = {false};
	
	int k;
	cin>>k;
	int arr1[k];
	
	for(int i=0;i<k;++i)
	cin>>arr1[i];
	
	//Sieve applications...
	for(int i=0;i<k;++i)
	{
		int val  = arr1[i];
		
		if(isEaten[val]!=true)
		{
			for(int j=val;j<=n;j+=val)
			isEaten[j] = true;
		}
	}
	
	int coun=0;
	for(int i=1;i<=n;++i)
	{
		if(isEaten[i] == false)
		++coun;
	}
	cout<<coun;
}
