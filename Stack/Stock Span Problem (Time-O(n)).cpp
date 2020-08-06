/*

Ques:- Stock Span Problem (GFG)

Concept:- 1. similar to finding next greater element in left
	2. Subtracting the indexing then to find the number of elements
  
  */
  
  void work()
{
    ll n;
    cin>>n;
    
    ll arr1[n];
    vector<ll> ans;
    
    for(int i=0;i<n;++i)
    {
        cin>>arr1[i];
    }
    
    stack<pair<ll,ll> > s1;
    s1.push({arr1[0] , 0});
    
    ans.push_back(1);
    
    for(int i=1;i<n;++i)
    {
        while(s1.size()!=0 && s1.top().first<=arr1[i])
        {
        	s1.pop();
		}
        
        if(s1.size()!=0 && s1.top().first>arr1[i])
        {
            ans.push_back(i - s1.top().second);
            s1.push({ arr1[i] ,i });
        }
        else if(s1.size() == 0)
        {
            ans.push_back(i+1);
            s1.push({ arr1[i] ,i} );
        }
    }
    
    for(int i=0;i<ans.size();++i) cout<<ans[i]<<" ";
}
