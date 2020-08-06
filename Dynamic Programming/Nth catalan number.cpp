/*

Ques :- Nth catalan number?

Concept:-
	1.) Thus recurance relation will be f(n) = summation(i=1 ..... N ) f(i-1) * f(n-i)
	2.) Apply DP too
  
  
Applications:-
  
  1) Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible 
  expressions are ((())), ()(()), ()()(), (())(), (()()).

2) Count the number of possible Binary Search Trees with n keys (See this)

3) Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.

4) Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.
  
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
