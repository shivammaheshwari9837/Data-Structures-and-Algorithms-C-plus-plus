/*

Ques:- Finding the peak element....
PS:-An array element is peak if it is not smaller than its neighbours. For corner elements, we need to consider only one neighbour.

*/

int peakElement(int arr1[], int n)
{
	int start=0,end=n-1,index;
	
	while(start<=end)
	{
		int mid=start+(end-start)/2;
		
		if(mid==0 && arr1[mid]>arr1[mid+1])
		{
			index=mid;
			break;
		}
		else if(mid==n-1 && arr1[mid]>arr1[mid-1])
		{
			index=mid;
			break;
		}
		else if(arr1[mid]>=arr1[mid+1] && arr1[mid]>=arr1[mid-1])
		{
			index=mid;
			break;
		}
		else if(arr1[mid+1]>arr1[mid])
		start=mid+1;
		else
		end=mid-1;
	}
	
	//cout<<index;
    return index;
}
