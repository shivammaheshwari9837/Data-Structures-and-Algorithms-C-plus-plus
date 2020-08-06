/*
Merge two sorted arrys in O(1) extra space:

Theory:- use Shell sort concept here...Time(O(nlogn) )

*/


int gaps(int gap)
{
	if(gap<=1)
	return 0;
	else
	return (gap/2)+(gap%2);
}

void merge()
{
	int gap=(n+m),i,j;
	
	for(gap=gaps(gap);gap>0;gap=gaps(gap))
	{
		//Sorting in the first array....
		for(i=1;i+gap<=n;++i)
		{
			if(arr1[i]>arr1[i+gap])
			swap(arr1[i],arr1[i+gap]);
		}
		
		//Sorting in between two arrays....
		for(j=1;j<=m && i<=n ; ++i,++j)
		{
			if(arr1[i]>arr2[j])
			swap(arr1[i],arr2[j]);
		}
		
		//Sorting the second array...
			for(j=1;j+gap<=m;++j)
			{
				if(arr2[j]>arr2[j+gap])
				swap(arr2[j],arr2[j+gap]);
			}
	}
}
