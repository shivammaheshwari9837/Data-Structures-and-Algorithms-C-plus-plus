/*

Ques :- Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

Concept:- Use some modulo concept of k
	some edge case like n is odd, for k==1 .

*/

void work()
{
	int n;
	cin>>n;
	
	int arr1[n];
	
	unordered_map<int,int> m1;
	
	for(int i=0;i<n;++i)
	{
		cin>>arr1[i];
	}
	
	int k;
	cin>>k;
	
	if(n%2!=0)
	{
		cout<<"False";
		return;
	}
	
	if(k == 1)
	{
		cout<<"True";
		return;
	}
	
	for(int i=0;i<n;++i)
	++m1[arr1[i]%k];
	
	bool check = true;
	int sea;
	
	for(int i=0;i<n;++i)
	{
		int modu = arr1[i]%k;
		
		if(modu == 0)
		sea = 0;
		else
		sea = k - modu;
		
		if(m1.find(sea)!=m1.end())
		{
			--m1[sea];
			if(m1[sea] == 0)
			m1.erase(sea);
		}
		else
		{
			check = false;
			break;
		}
	}
	
	if(check)
	cout<<"True";
	else
	cout<<"False";
}
