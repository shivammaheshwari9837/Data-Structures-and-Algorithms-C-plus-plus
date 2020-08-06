/*

Ques :-Pascal Triangle

Theory:- Uses stack DS

*/

void  work()
{
    int k;
    cin>>k;
    
    if(k==1)
    cout<<1;
    else if(k==2)
    cout<<1<<" "<<1;
    else
    {
        stack<int> s1,ans;
        s1.push(1);
        s1.push(1);
        
        for(int i=3;i<=k;++i)
        {
        	while(!ans.empty())
        	{
        		ans.pop();
			}
            ans.push(1);
            while(s1.size()>1)
            {
                int temp=s1.top();
                s1.pop();
                temp+=s1.top();
                ans.push(temp);
            }
            ans.push(1);
            s1=ans;
        }
        
        while(!ans.empty())
        {
            cout<<ans.top()<<" ";
            ans.pop();
        }
    }
}
