/*



*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Point
{
	int x,y;
};

struct Line
{
	Point p1,p2;
};

bool onLine(Line l1,Point p)    //check whether p is on the line or not (or checking colinearity)
{  
	if(p.x <= max(l1.p1.x, l1.p2.x) && p.x >= min(l1.p1.x, l1.p2.x) &&   //Point P must lie inside the range of Line l1 here
      (p.y <= max(l1.p1.y, l1.p2.y) && p.y >= min(l1.p1.y, l1.p2.y)))
      return true;
   
   return false;  //not lie, not intersect
}

int orientation(Point p,Point q,Point r)  // checking the orientation of point r is either clockwise/anti -clcockwise/co-linear  
{

  /*
  
      | p.x - r.x         q.x - r.x|
      | p.y - r.y         q.y - r.y|
      
      //Just to cross product for finding the determinant
  
  */
    
	int val = (p.x - r.x)*(q.y - r.y) - (p.y - r.y)*(q.x - r.x);  // Finding the determinent (resultant formula)
	
	if(val > 0)
	return 1;   //clockwise direction
	else if(val < 0)
	return 2;   //anti-clockwise direction
	else
	return 0;   //colinear
}

bool isIntersect(Line l1,Line l2)
{

  //four direction for two lines and points of other line
	int o1 = orientation(l1.p1,l1.p2,l2.p1); 
	int o2 = orientation(l1.p1,l1.p2,l2.p2);
	int o3 = orientation(l2.p1,l2.p2,l1.p1);
	int o4 = orientation(l2.p1,l2.p2,l1.p2);
	
	if(o1 != o2 && o3 != o4)  // one must be clock-wise and other must be anticlockwise to insersect
	return true;
	
	if(o1 == 0 && onLine(l1,l2.p1)) //checking if point p1 of Line l2 is lie over the line l1 or not.............similar other 3 conditions
	return true;
	
	if(o2 == 0 && onLine(l1,l2.p2))
	return true;
	
	if(o3 == 0 && onLine(l2,l1.p1))
	return true;
	
	if(o4 == 0 && onLine(l2,l1.p2))
	return true;
	
	return false;
}

void work()
{
    Line l1,l2;
    
    cin>>l1.p1.x>>l1.p1.y>>l1.p2.x>>l1.p2.y;
    cin>>l2.p1.x>>l2.p1.y>>l2.p2.x>>l2.p2.y;
    
    
    bool ans = isIntersect(l1,l2);
    cout<<ans;
    
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
