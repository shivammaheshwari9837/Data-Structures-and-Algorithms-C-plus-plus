/*

Ques :- Maximum area in histogram

Concept:- 1.Find NSL(next smaller left) and NSR(next smaller right) first..
	2. Do some calculation using these two to find the area
  
  */
  
  void work()
{
    ll n,last_index;
    cin>>n;
    
    int arr1[n];
    vector<int> ans1,ans2;
    
    for(int i=0;i<n;++i)
    {
        cin>>arr1[i];
    }
    
    stack<pair<int,int> > s1,s2;
    
    
    //Next Smaller to left............
    s1.push({arr1[0] , 0});
    ans1.push_back(1);
    
    for(int i=1;i<n;++i)
    {
        while(s1.size()!=0 && s1.top().first>=arr1[i])
        {
        	s1.pop();
		}
        
        if(s1.size()!=0 && s1.top().first<arr1[i])
        {
            ans1.push_back(i - s1.top().second);
            s1.push({ arr1[i] ,i });
        }
        else if(s1.size() == 0)
        {
            ans1.push_back(i+1);
            s1.push({ arr1[i] ,i} );
        }
    }
    
    
    //Next smaller to right................
    s2.push({arr1[n-1] , n-1});
    ans2.push_back(1);
    
    for(int i=n-2;i>=0;--i)
    {
    	while(s2.size()!=0 && s2.top().first>=arr1[i])
    	s2.pop();
    	
    	if(s2.size()!=0 && s2.top().first<arr1[i])
    	{
    		ans2.push_back(s2.top().second - i);
    		s2.push({arr1[i] , i});
		}
		else if(s2.size() == 0)
		{
			ans2.push_back(n-i);
			s2.push({arr1[i] , i});
		}
	}
	
	reverse(ans2.begin(),ans2.end());
	
	
	//Final calculation....
	int res = 0;
	
	for(int i=0;i<n;++i)
	{
		int temp = ans1[i] + ans2[i] -1;
		res = max(res , arr1[i]*temp);
	}
	cout<<res;
    
    
}
