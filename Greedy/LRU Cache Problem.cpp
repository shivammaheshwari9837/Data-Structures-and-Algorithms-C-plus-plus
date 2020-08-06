/*

Ques :- LRU Cache Problem

Concept:- Few points to remember--
	1. if memory is left and element does not found, just add it int the memory
	2. if page/element does found in memory, just updates its old time to current time
	3. if memory if full and element/page does not found, remove the oldest/least recent 
	used page/element and update with current one, here page fault occures

*/

void work()
{
	int n;
	cin>>n;
	
	int arr1[n];
	
	for(int i=0;i<n;++i)
	{
		cin>>arr1[i];
	}
	
	int mem;
	cin>>mem;
	
	int page = 0;
	map<int,int> m1,exist;
	
	for(int i=0;i<n;++i)
	{
		if(m1.size()<mem && ( exist.find(arr1[i]) == exist.end()) )
		{
				m1[i] = arr1[i];
				exist[arr1[i]]=i;
				++page;
		}
		else if(exist.find(arr1[i] ) == exist.end())
		{
			++page;
			
			auto p = m1.begin();
			int f = p->first;
			int s = p->second;
			
			m1.erase(f);
			exist.erase(s);
			
			m1[i] = arr1[i];
			exist[arr1[i]] = i;
		}
		else
		{
			int rem = exist[arr1[i]];
			m1.erase(rem);
			exist.erase(arr1[i]);
				
			m1[i] = arr1[i];
			exist[arr1[i]]=i;
		}
	}
	
	cout<<page;
}
