/*

Ques :- Given an integer N, how many structurally unique binary search trees are there that store values 1...N?

Concept:- 1.)Exact similar to finding the nth catalan number
	2.)Fixed some ith node in a certain BST, than left subtree has total (i-1) nodes and right subtree has total (n-i) nodes
	3.) Thus recurance relation will be f(n) = summation(i=1 ..... N ) f(i-1) * f(n-i)
	4.) Apply DP too

*/

const int siz = 105;
ll dp[siz];

ll catalan(int n)
{
	if(n == 0 || n == 1)
	return 1;
	
	if(dp[n] != -1)
	return dp[n];
	
	ll res = 0;
	for(int i=0;i<n;++i)
	{
		res += (catalan(i) * catalan(n-i-1) );
	}
	
	return ( dp[n] = res );
}

void work()
{
	int n;
	cin>>n;
	
	for(int i=0;i<=n;++i)
	dp[i] = -1;
	
	ll ans = catalan(n);
	
	cout<<ans;
	
}
