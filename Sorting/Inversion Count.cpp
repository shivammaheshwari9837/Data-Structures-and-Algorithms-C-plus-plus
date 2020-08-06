/*
Ques :- Inversion Count(using Merge Sort)(time - O(nlogn) )

Theory:- concept of merge sort...
*/

void merging(int start,int mid,int end)
{
	int p=start,q=mid+1;
	
//	int first_len=mid-start+1;
	
	int curr=1;
	
	int temp[end-start+2];
	
	for(int i=start;i<=end;++i)
	{
		//first is finished....
		if(p>mid)
		{
			temp[curr++]=v1[q++];
		}
		else if(q>end) //second array is finished...
		{
			temp[curr++]=v1[p++];
		}
		else if(v1[p]<=v1[q]) //first array element is greater..
		{
			temp[curr++]=v1[p++];
		}
		else // second array element is greater...
		{
			in_coun+=(mid-p+1); //single line added to merge sort..
//			cout<<p<<"\n";
			temp[curr++]=v1[q++];
		}
	}
	
	//copy to original array..
//	cout<<curr<<" "<<end-start+1<<"\n";
	for(int i=1;i<curr;++i)
	{
		v1[start++]=temp[i];
	}
}


void mergeSort(int start,int end)
{
	if(start<end)
	{
		int mid=(start+end)/2;
	
		mergeSort(start,mid);
		mergeSort(mid+1,end);
		
		merging(start,mid,end);
	}
}
