/*
Ques Find reapeated elements in an array (0<=a[i]<=N-1,Time-O(n),Space-O(1)):-


Theory-->The basic idea is to use a HashMap to solve the problem. But there is a catch, 
the numbers in the array are from 0 to n-1, and the input array has length n. So, the input 
array can be used as a HashMap. While Traversing the array, if an element ‘a’ is encountered 
then increase the value of a%n‘th element by n. The frequency can be retrieved by dividing 
the a % n’th element by n.

*/

void work()
{
	int n;
	cin>>n;
	
	int arr1[n+1];
	
	for(int i=0;i<n;++i)
	{
		cin>>arr1[i];
	}
	
	for(int i=0;i<n;++i)
	{
		arr1[arr1[i]%n] = arr1[arr1[i]%n] + n;
	}
	
	for(int i=0;i<n;++i)
	{
		if(arr1[i]>=(2*n))
		cout<<i<<" ";
	}
}
