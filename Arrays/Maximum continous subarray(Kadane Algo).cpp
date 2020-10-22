/*

Ques :- Maximum continous subarray(Kadane Algo)

Theory:- We will use dp for this.
we have two choice:
		1. Selects on current ith element.
		2. Add current element to previous continous element.
		
Time - O(n)
Space - O(1)
 */
 
 void work()
{
    ll n;
    cin>>n;
    vector<ll> v1(n+1),dp(n+1,INT_MIN);
    
    for(ll i=1;i<=n;++i)
    {
        cin>>v1[i];
    }
    
    dp[1]=v1[1];
    for(ll i=2;i<=n;++i)
    {
        dp[i]=max(v1[i],dp[i-1]+v1[i]);
    }
    
    cout<<*max_element(dp.begin(),dp.end());
}
