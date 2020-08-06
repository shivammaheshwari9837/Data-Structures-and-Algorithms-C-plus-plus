/*

Method 1:- Time-O(nlog(base 5)n)

Theory:- zeros increases due pairing of 2's and 5's prime factorization of factorial

*/

void work()
{
    int n,trai=0;
    cin>>n;
    
    for(int i=1;i<=n;++i)
    {
    	if(i%5==0)
    	{
    		int temp=i;
    		while(temp%5==0)
    		{
    			++trai;
    			temp/=5;
			}
		}
	}
	cout<<trai;
}

/*

Method 2:- Time O(log(base 5)n )

*/

int trailingZeroes(int n) {
        
        int trai=0;
        
    for(long i=5;n/i>=1;i*=5)
    {
        trai+=(n/i);
    }
        
        return trai;
        
  }
