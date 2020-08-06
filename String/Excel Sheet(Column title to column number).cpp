/*

Ques :- Column title to column number

*/

void work()
{
    string s;
    cin>>s;
    
    int res=0,temp;
    
    for(int i=s.size()-1;i>=0;--i)
    {
    	temp=pow(26,s.size()-1-i);
    	
    	if(temp==0)
    	temp+=(s[i]-('A'-1));
    	else
    	temp*=(int)(s[i]-('A'-1));
    	
    	res+=temp;
	}
	
	cout<<res;
}
