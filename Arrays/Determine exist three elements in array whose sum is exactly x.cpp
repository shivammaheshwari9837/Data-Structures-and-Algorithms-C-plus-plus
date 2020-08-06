/*

Ques 65:- Given an array A[] of N numbers and another number x, determine whether or not 
there exist three elements in A[] whose sum is exactly x.

Concept:- Just similar to----------( count all the triplets such 
that sum of two elements equals the third element)      ..ie.Two pointer by fixing a value

*/

void work()
{
	ll n,x;
	cin>>n>>x;
	
	ll arr1[n];
	
	for(int i=0;i<n;++i)
	cin>>arr1[i];
	
	sort(arr1,arr1+n);
	
	for(int i=n-1;i>=2;--i)
	{
		int left = 0,right = i-1;
		
		while(left<right)
		{
			if( ( arr1[left] + arr1[right] + arr1[i] ) == x)
			{
				cout<<1;
				return;
			}
			else if(( arr1[left] + arr1[right] + arr1[i] )> x)
			--right;
			else
			++left;
		}
	}
	
	cout<<0;
}

