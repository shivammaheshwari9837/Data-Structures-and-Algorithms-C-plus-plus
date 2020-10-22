/*

Ques :-Merge overlapping subintervals(Time-(nlongn))

Theory:- 1. Sort the intervals according to the start time....
	2. uses stack to find out some conditions...
	

Time - O(n * logn)
Space - O(1)
*/


void work()
{
	
	//Clean...
	ans.clear();
	
    int n,x,y;
    cin>>n;
    
    for(int i=1;i<=n;++i)
    {
    	cin>>x>>y;
    	p1[i].first=x;
    	p1[i].second=y;
	}
	
	sort(p1+1,p1+n+1);
	
	s1.push({p1[1].first,p1[1].second});
	
	for(int i=2;i<=n;++i)
	{
		int low=p1[i].first;
		int upp=p1[i].second;
		
		int mlow=s1.top().first;
		int mupp=s1.top().second;
		
		if(low<=mupp)
		{
			s1.pop();
			s1.push({mlow,max(upp,mupp)});
		}
		else
		{
			s1.push({low,upp});
		}
	}
	
	while(!s1.empty())
	{
		ans.push_back({s1.top().first,s1.top().second});
		s1.pop();
	}
	
	sort(ans.begin(),ans.end());
	
	for(int i=0;i<ans.size();++i)
	cout<<ans[i].first<<" "<<ans[i].second<<" ";
	
	
	
}
