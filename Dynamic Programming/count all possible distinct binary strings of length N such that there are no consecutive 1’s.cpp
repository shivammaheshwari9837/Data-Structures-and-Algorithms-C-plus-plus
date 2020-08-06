/*

Ques:- Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Concept:- 1.)use DP
	2.)choices----a)either put 1 at position
			b)either not put


*/

const int siz = 105;

int dp[siz][3];

int binary(int index,bool choice)
{
	//Base condition.........
	if(index<0)
	return 1;
	
	if(dp[index][choice]!=-1)
	return dp[index][choice];
	
	//Induction..
	int val;
	if(choice)
	{
		val = binary(index-1,false)%mod;
	}
	else
	{
		val =( binary(index-1,true)%mod + binary(index-1,false)%mod )%mod;
	}
	
	return (dp[index][choice] = val );
}

void work()
{
	int n;
	cin>>n;
	
	for(int i=0;i<=n;++i)
	for(int j=0;j<=1;++j)
	dp[i][j] = -1;
	
	int ans = binary(n-1,false);
	cout<<ans;
}
