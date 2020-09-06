/*

Ques:- Given an integer x. The task is to find the square root of x. If x is not a perfect square, then return floor(√x).

*/

long long int floorSqrt(long long int n) 
{
    // Your code goes here   
	
	long long int start=0,end=n,res;
	
	while(start<=end)
	{
		long long int mid=start+(end-start)/2;
		
		if(mid*mid == n)
		{
			res=mid;
			break;
		}
		else if(mid*mid < n)
		{
			res=mid;
			start=mid+1;
		}
		else
		end=mid-1;
	}	
	
	return res;


}
