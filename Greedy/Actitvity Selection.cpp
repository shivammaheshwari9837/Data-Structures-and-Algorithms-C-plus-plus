/*

Ques 74:-   Given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can 
only work on a single activity at a time.

Note : The start time and end time of two activities may coincide.

Concept:- 1. Pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of previously selected 
activity.

2. Sort the activities according to their finishing time so that one can always consider the next activity as minimum finishing time activity.

*/

bool comp(pair<int,int> &p1,pair<int,int> &p2)
{
	return (p1.second<p2.second);
}

void work()
{
	int n;
	cin>>n;
	
	vector<pair<int,int> >arr1(n);
	
	for(int i=0;i<n;++i)
	{
		cin>>arr1[i].first;
	}
	
	for(int i=0;i<n;++i)
	{
		cin>>arr1[i].second;
	}
	
	sort(arr1.begin(),arr1.end(),comp);

	int ans=1;
	int y=0;
	
	for(int i=1;i<n;++i)
	{
		if(arr1[i].first>=arr1[y].second)
		{
			++ans;
			y=i;
		}		
	}
	
	cout<<ans;
}
