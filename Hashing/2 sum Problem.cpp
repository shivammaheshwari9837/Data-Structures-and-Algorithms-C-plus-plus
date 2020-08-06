/*

Ques :- Is there a pair exist leads to target sum

Method 1:- Using sorting and two pointer.

*/


void work()
{
    int n,x;
    cin>>n>>x;
    
    int arr1[n+1];
    
    for(int i=1;i<=n;++i)
    cin>>arr1[i];
    
    sort(arr1+1,arr1+n+1);
    
    int left=1,right=n,temp;
    bool poss=false;
    
    while(left<right)
    {
    	int temp=arr1[left]+arr1[right];
    	
    	if(temp==x)
    	{
    		poss=true;
    		break;
		}
		else if(temp<x)
		++left;
		else
		--right;
	}
	
	if(poss)
	cout<<"Yes";
	else
	cout<<"No";
}
