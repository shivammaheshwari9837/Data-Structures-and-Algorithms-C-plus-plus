
/*
Ques Finding two repeated elements in array(1<=a[i]<=n), Time - O(n),Space - O(1)

Theory : Traverse the array. Do following for every index i of A[].
{
check for sign of A[abs(A[i])] ;
if positive then
   make it negative by   A[abs(A[i])]=-A[abs(A[i])];
else  // i.e., A[abs(A[i])] is negative
   this   element (ith element of list) is a repetition
}

*/

void work()
{
    int n;
    cin>>n;
    int A[n+1];
    
    //After runn
    for(int i=1;i<=n;++i)
    {
        cin>>A[i];
    }
    
    for(int i=1;i<=n;++i)
    {
    	if(A[abs(A[i])]>0)
    	{
    		A[abs(A[i])]=-A[abs(A[i])];
	}
	else
	{
			cout<<abs(A[i])<<" ";
	}
    }
    
    
}
