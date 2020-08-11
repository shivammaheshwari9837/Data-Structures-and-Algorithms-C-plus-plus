/*


*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Point
{
	int x,y;
};

bool comp(pair<int,int> &p1,pair<int,int> &p2)
{
	if(p1.first == p2.first)
	return (p1.second < p2.second);
	
	return (p1.first < p2.first);
}


int orientation(Point a,Point b,Point c)
{
	int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
	
	if(val > 0)
	return 1;
	else if(val <= 0)
	return 2;
 	else
 	return 0;
}

void work()
{
	int n;
	cin>>n;
	
	Point poi[n];
	
	for(int i=0;i<n;++i)
	{
		cin>>poi[i].x>>poi[i].y;
	} 
	
	vector<pair<int,int> > convexHull;
	
	int curr = 0;
	int tVal = poi[curr].x;
	
	for(int i=0;i<n;++i)
	{
		if(poi[i].x < tVal)
		{
			curr = i;
			tVal = poi[i].x;
		}
	}
	
	int end = curr;
	
	do
	{
		convexHull.push_back({poi[curr].x,poi[curr].y});
		
		int index = (curr + 1)%n;
		
		for(int i=0;i<n;++i)
		{
			if(orientation(poi[curr],poi[index],poi[i]) == 2)
			index = i;
		}
		
		curr = index;
		
	}while(curr != end);
	
	
	sort(convexHull.begin(),convexHull.end(),comp);
	
	vector<pair<int,int> >finalHull;
	
	for(int i=0;i<convexHull.size()-1;++i)
	{
	    if(!((convexHull[i].first  == convexHull[i+1].first) && (convexHull[i].second == convexHull[i+1].second)))
	    {
	        finalHull.push_back({convexHull[i].first,convexHull[i].second});
	    }
	}
	
	int last = convexHull.size()-1;
	finalHull.push_back({convexHull[last].first,convexHull[last].second});
	
	if(finalHull.size()<3)
	{
	    cout<<-1;
	    return;
	}
	
	for(int i=0;i<finalHull.size();++i)
	{
		cout<<finalHull[i].first<<" "<<finalHull[i].second;
		if(i != (finalHull.size() - 1))
		cout<<", ";
	}
	
	
}

int main()
 {
	ll test;
	cin>>test;
	for(int i=0;i<test;++i)
	{
	    work();
	    cout<<"\n";
	}
	return 0;
}
